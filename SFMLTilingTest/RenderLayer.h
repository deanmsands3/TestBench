/*
 * RenderLayer.h
 *
 *  Created on: Sep 2, 2018
 *      Author: dean
 */

#ifndef ENGINECORE_RENDERLAYER_H_
#define ENGINECORE_RENDERLAYER_H_
#include <vector>
namespace DMS3 {

class RenderLayer {
	unsigned _tile_size;

public:
	RenderLayer();
	virtual ~RenderLayer();
};

} /* namespace DMS3 */

#endif /* ENGINECORE_RENDERLAYER_H_ */
