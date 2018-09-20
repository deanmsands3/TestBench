/*
 * AssetManager.h
 *
 *  Created on: Mar 10, 2018
 *      Author: deansands
 */

#ifndef ASSETMANAGER_H_
#define ASSETMANAGER_H_
#include <unordered_map>
#include <string>
#include <cstdint>
#include <mutex>
#include <fstream>
#include "ByteArray.h"
#include "Logger.h"
#include "libs/nlohmann/json.hpp"

using json = nlohmann::json;


namespace DMS3{
template<typename T, typename U>
class ResourceManager{
	typedef T* PT;
	typedef U* PU;

	typedef PT (*TfpU)(U);

	TfpU _load_resource;
	unsigned int _i;
	std::string _key;
	std::mutex _lock;
	void _lock_up(){_lock.lock();}
	void _unlock(){_lock.unlock();}
	std::unordered_map<std::string, unsigned int> _strings_ids;
	std::unordered_map<unsigned int, std::string> _ids_strings;
	std::unordered_map<unsigned int, T*> _ids_resources;

public:
	unsigned int push_resource(U resource,
			std::string resource_name) {
		unsigned resource_id =_i;
		_i++;
		_ids_strings[resource_id] = resource_name;
		_strings_ids[resource_name] = resource_id;
		_ids_resources[resource_id] = _load_resource(resource);
		return resource_id;
	}

	T* get_resource(unsigned int asset_id) {
		return _ids_resources[asset_id];
	}

	T* get_resource(std::string asset_name) {
		return get_resource(_strings_ids[asset_name]);
	}
	void free_resource(unsigned int resource_id) {
		std::string resource_name=_ids_strings[resource_id];
		_free_resource(resource_id, resource_name);
	}

	void free_resource(std::string resource_name) {
		int resource_id =_strings_ids[resource_name];
		_free_resource(resource_id, resource_name);
	}

	void _free_resource(unsigned int resource_id, std::string resource_name) {
		FILE_LOG(logINFO) << "ResourceManager: Freeing " << resource_name;
		_lock_up();
		T *delete_me = _ids_resources[resource_id];
		_ids_strings.erase(resource_id);
		_strings_ids.erase(resource_name);
		_ids_resources.erase(resource_id);
		if(delete_me) {delete delete_me;}
		_unlock();
	}


	ResourceManager<T,U>(
			std::string index, std::string key, TfpU _new_load_resource
			):_i(0), _load_resource(_new_load_resource){
		std::ifstream indexStream(index);		// Load Index file
		FILE_LOG(logINFO) << "ResourceManager: Constructor";
		json root;				// Create a JSON object named root
		try{
			indexStream>>root;

		}
		catch(std::exception &e){
			FILE_LOG(logERROR)<<"ResourceManager::Block A";
			FILE_LOG(logERROR)<<e.what();
			return;
		}
		try{
			json resources=root[key];
			for(auto resource:resources.items()){
				std::string resourceName=resource.key();
				std::string fileName = resource.value().at("file");
				FILE_LOG(logINFO)<< "ResourceManager: Adding " << fileName;
				this->push_resource(fileName, resourceName);
			}
		}
		catch(std::exception &e){
			FILE_LOG(logERROR)<<"ResourceManager::Block B";
			FILE_LOG(logERROR)<<e.what();
			return;
		}

	}
	void _copy_that(const ResourceManager &that){
		that._lock_up();
		_i=that._i;
		_load_resource=that._load_resource;
		_key=that._key;
		_strings_ids=that._strings_ids;
		_ids_strings=that._ids_strings;
		_ids_resources=that._ids_resources;
		that._unlock();
	}
	ResourceManager<T, U>(const ResourceManager &that){
		_copy_that(that);
	}

	ResourceManager<T, U>(const ResourceManager *that){
		_copy_that(*that);
	}
	virtual ~ResourceManager();
};

class AssetManager {
	unsigned int _i;
	std::mutex _lock;
	std::unordered_map<std::string, unsigned int> _strings_ids;
	std::unordered_map<unsigned int, std::string> _ids_strings;
	std::unordered_map<unsigned int, ByteArray*> _ids_assets;
	void _free_asset(unsigned int asset_id, std::string asset_name);
	static ByteArray* _load_asset(std::string file_name);
	void _lock_up();
	void _unlock();
public:
	unsigned int push_asset(std::string file_name, std::string asset_name);
	ByteArray* get_asset(unsigned int asset_id);
	ByteArray* get_asset(std::string asset_name);
	virtual void free_asset(unsigned int asset_id);
	virtual void free_asset(std::string asset_name);
	AssetManager(std::string index);
	AssetManager(const AssetManager &that);
	AssetManager(const AssetManager *that);
	virtual ~AssetManager();
}; //AssetManager

class TextureManager{

};

}; //Namespace DMS3

#endif /* ASSETMANAGER_H_ */
