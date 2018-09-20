/*
 * Entities.h
 *
 *  Created on: Mar 10, 2018
 *      Author: deansands
 */

#ifndef SRC_ENTITY_H_
#define SRC_ENTITY_H_
#include <SFML/Graphics.hpp>
#include <memory>
#include "AssetManager.h"

namespace DMS3{

class Entity {
  unsigned int _id;
  unsigned int _z_order;
  sf::Vector2f _position;
  sf::Sprite _sprite;
public:
	Entity(unsigned int id, sf::Sprite sprite);
	virtual ~Entity();
	unsigned int getId() const;
	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f position);
	const sf::Sprite& getSprite() const;
	void setSprite(const sf::Sprite& sprite);
	virtual void update(float t);
	virtual void draw(sf::RenderWindow *render_window);
	unsigned int getZOrder() const;
	void setZOrder(unsigned int order);
};

}; //namespace DMS3
#endif /* SRC_ENTITY_H_ */
