/*
 * Entity.cpp
 *
 *  Created on: Feb 20, 2020
 *      Author: esantiago
 */

#include "Entity.h"
#include "Aspects.h"


Entity::Entity(EntityType entType)
	: ent( NULL ), scnNode( NULL)
{
	entityType = entType;
	posVec = Ogre::Vector3::ZERO;
	velVec = Ogre::Vector3::ZERO;
	al.clear();//= new std::list<Aspect*>();
	Physics *phx = new Physics(this);  // left off here... studying Aspects
	al.push_front(phx);
	Render *rndrr = new Render(this);
	al.push_front(rndrr);

	delta = 5.0f;
	deltaTheta = 5.0f;
	acceleration = 0;
	desiredHeading = heading = 0;
	turnRate = 0;
	desiredSpeed = speed = 0;
	minSpeed = maxSpeed = 0;

}


void Entity::tick(float dt)
{
	for (auto it = al.begin(); it != al.end(); ++it)
	{
			(*it)->tick( dt );
	}

}

