/*
 * Aspects.h
 *
 *  Created on: Feb 20, 2020
 *      Author: esantiago
 */

#ifndef ASPECTS_H_
#define ASPECTS_H_

#include "Aspect.h"

class Physics: public Aspect
{

public:

	Physics(Entity *ent);
	~Physics();

	void tick(float dt);
};

class Render: public Aspect
{

public:

	Render(Entity *ent);
	~Render();

	void tick(float dt);
};



#endif /* ASPECTS_H_ */
