/*
 * GameWindow.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: deansands
 */

#include "GameWindow.h"

namespace DMS3{

//Game Window member functions
GameWindow::GameWindow(std::shared_ptr<GameWindowManager> window_manager):
	_game_window_manager(window_manager),
	_entity_manager(window_manager->getAssetManager()),
	_next_window(NULL),
	_active(false){
	_preload();
}

std::shared_ptr<GameWindow> GameWindow::open(){
	_active = true;
	_setup();
	_loop();
	_close();
	return _next_window;
}

void GameWindow::_preload(){}

void GameWindow::_setup() {}

void GameWindow::_loop() {
	bool active=true;
    float t;
	t=0.00f;
	sf::Clock clock; // starts the clock
    while (_window.isOpen() && active==true)
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        sf::Time elapsed = clock.restart();
        t += elapsed.asSeconds();
        _update_entities(t);
        draw();
    }
}
void GameWindow::_close() {

}

void GameWindow::push_entity(unsigned int id, const Entity& entity) {
	//_entity_manager[id]=entity;

}

GameWindow::~GameWindow() {
	// TODO Auto-generated destructor stub
}

void GameWindow::draw(){
    _window.clear();
	for(auto that_entity:this->_entity_manager){
	    _window.draw((that_entity.second->getSprite()));
	}
    _window.display();
}

void GameWindow::_update_entities(float t) {
	for(auto that_entity:this->_entity_manager){
	    that_entity.second->update(t);
	}
}

//Game Window Manager member functions

//Constructor
GameWindowManager::GameWindowManager(
	std::shared_ptr<AssetManager> asset_manager) {
	auto desktop_mode=sf::VideoMode::getDesktopMode();
	_width=desktop_mode.width;
	_height=desktop_mode.height;

}

GameWindowManager::~GameWindowManager() {
}

void GameWindowManager::open_window(
		std::shared_ptr<GameWindow> new_game_window) {
	_current_window = new_game_window;
	while(_current_window){
		_current_window = _current_window->open();
	}
}

const std::shared_ptr<AssetManager>& GameWindowManager::getAssetManager() const {
	return _asset_manager;
}


const std::shared_ptr<GameWindow>& GameWindowManager::getCurrentWindow() const {
	return _current_window;
}

GameWindowManager::GameWindowManager(const GameWindowManager& that):
	_asset_manager(that._asset_manager),
	_current_window(that._current_window),
	_height(that._height),
	_width(that._width)
	{}
GameWindowManager::GameWindowManager(const GameWindowManager* that):
	_asset_manager(that->_asset_manager),
	_current_window(that->_current_window),
	_height(that->_height),
	_width(that->_width)
	{}

void GameWindowManager::setCurrentWindow(
		const std::shared_ptr<GameWindow>& currentWindow) {
	_current_window = currentWindow;
}

const std::shared_ptr<GameWindowManager>& GameWindow::getGameWindowManager() const {
	return _game_window_manager;
}


unsigned GameWindowManager::getHeight() const {
	return _height;
}

unsigned GameWindowManager::getWidth() const {
	return _width;
}

}; // namespace DMS3
