/*
 * Aspect.cpp
 *
 *  Created on: Feb 20, 2020
 *      Author: esantiago
 */

#include "Entity.h"
#include "Aspect.h"

Aspect::Aspect(Entity *ent)
{
	entity = ent;
	aspectType = NULLASP;
}

Aspect::~Aspect(){}

