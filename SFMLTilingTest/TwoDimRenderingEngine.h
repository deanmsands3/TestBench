/*
 * TwoDimRenderingEngine.h
 *
 *  Created on: Aug 30, 2018
 *      Author: dean
 */

#ifndef ENGINECORE_TWODIMRENDERINGENGINE_H_
#define ENGINECORE_TWODIMRENDERINGENGINE_H_
#include <vector>
#include <SFML/Graphics.hpp>
#include "RenderingEngine.h"
#include "Entity.h"
#include "RenderLayer.h"
namespace DMS3 {

class TwoDimRenderingEngine:public RenderingEngine {
	unsigned _width, _height;
	std::vector< RenderLayer > _layers;
	std::vector< std::vector<Entity *> > _entities;
public:
	void render(sf::Vector2 v2);
	TwoDimRenderingEngine(unsigned new_width, unsigned new_height);
	virtual ~TwoDimRenderingEngine();

	unsigned getHeight() const;

	void setHeight(unsigned height);

	unsigned getWidth() const;

	void setWidth(unsigned width);
};

} /* namespace DMS3 */

#endif /* ENGINECORE_TWODIMRENDERINGENGINE_H_ */
