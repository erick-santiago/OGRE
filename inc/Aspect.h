/*
 * Aspect.h
 *
 *  Created on: Feb 19, 2020
 *      Author: esantiago
 */

#ifndef ASPECT_H_
#define ASPECT_H_

#include "Entity.h"

enum AspectType {
	RENDERASP	= 1,
	PHYSICSASP	= 2,
	ROTATORASP	= 3,
	NULLASP		= 4
};


class Aspect {

public:

	Aspect(Entity *ent);
	virtual ~Aspect();

	virtual void tick(float dt) = 0;  // pure virutal fnc. makes this class Abstract

	Entity *entity;

	AspectType aspectType;

};



#endif /* ASPECT_H_ */
