/*
 * RenderingEngine.h
 *
 *  Created on: Aug 30, 2018
 *      Author: dean
 */

#ifndef ENGINECORE_RENDERINGENGINE_H_
#define ENGINECORE_RENDERINGENGINE_H_

namespace DMS3 {
class GameWindow;
class RenderingEngine {
	GameWindow *_game_window;
public:
	RenderingEngine(GameWindow *new_game_window);
	virtual ~RenderingEngine();
};

} /* namespace DMS3 */

#endif /* ENGINECORE_RENDERINGENGINE_H_ */
