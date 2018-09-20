/*
 * TwoDimRenderingEngine.cpp
 *
 *  Created on: Aug 30, 2018
 *      Author: dean
 */

#include "TwoDimRenderingEngine.h"

namespace DMS3 {

TwoDimRenderingEngine::TwoDimRenderingEngine(unsigned new_width, unsigned new_height):
		_width(new_width),_height(new_height) {}

TwoDimRenderingEngine::~TwoDimRenderingEngine() {
	_entities.clear();
	_tile_map.clear();
}
unsigned TwoDimRenderingEngine::getHeight() const {
	return _height;
}

void TwoDimRenderingEngine::setHeight(unsigned height) {
	_height = height;
}

unsigned TwoDimRenderingEngine::getWidth() const {
	return _width;
}

void TwoDimRenderingEngine::setWidth(unsigned width) {
	_width = width;
}

void TwoDimRenderingEngine::render(sf::Vector2 v2) {
	for(auto layer:this->_layers){

	}

}

} /* namespace DMS3 */

