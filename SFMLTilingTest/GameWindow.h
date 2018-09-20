/*
 * GameWindow.h
 *
 *  Created on: Mar 10, 2018
 *      Author: deansands
 */

#ifndef DMS3_GAMEWINDOW_H_
#define DMS3_GAMEWINDOW_H_
#include <memory>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "EntityManager.h"
namespace DMS3{

class GameWindowManager;

class GameWindow {
   sf::RenderWindow _window;
    std::shared_ptr<GameWindowManager> _game_window_manager;
    EntityManager _entity_manager;
    std::shared_ptr<GameWindow> _next_window;
	bool _active;
 	virtual void _setup();
	virtual void _loop();
	virtual void _close();
	virtual void _preload();
	virtual void _update_entities(float t);
	void draw();
public:
	std::shared_ptr<GameWindow> open();
	void push_entity(unsigned int id, const Entity  &entity);
	GameWindow(std::shared_ptr<GameWindowManager> window_manager);
	virtual ~GameWindow();
	const std::shared_ptr<GameWindowManager>& getGameWindowManager() const;
};

class GameWindowManager{
	std::shared_ptr<AssetManager> _asset_manager;
	std::shared_ptr<GameWindow> _current_window;
	unsigned _width;
	unsigned _height;
public:
	GameWindowManager(const GameWindowManager *that);
	GameWindowManager(const GameWindowManager &that);
	GameWindowManager(std::shared_ptr<AssetManager> asset_manager);
	virtual ~GameWindowManager();
	void open_window(std::shared_ptr<GameWindow> new_game_window);
	template<class T>
	inline std::shared_ptr<GameWindow> newWindow(){
		return std::shared_ptr<GameWindow>(new T(std::make_shared<GameWindowManager>(this)));
	}
	const std::shared_ptr<AssetManager>& getAssetManager() const;
	const std::shared_ptr<GameWindow>& getCurrentWindow() const;
	void setCurrentWindow(const std::shared_ptr<GameWindow>& currentWindow);

	unsigned getHeight() const;
	unsigned getWidth() const;
};

}; //namespace DMS3
#endif /* SRC_GAMEWINDOW_H_ */
