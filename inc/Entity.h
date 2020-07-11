/*
 * Entity.h
 *
 *  Created on: Feb 15, 2020
 *      Author: esantiago
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <OgreEntity.h>
#include "Enums.h"

class Aspect;

class Entity
{
	friend class EntityMgr;

public:

	static int count_id;  // left off here... working on Entity header and implementation file

	std::string entName;
	std::string nodeName;
	std::string meshName;

	Ogre::Vector3 posVec;
	Ogre::Vector3 velVec;

	float acceleration, turnRate;
	float speed, desiredSpeed, minSpeed, maxSpeed;
	float heading, desiredHeading;
	float delta;
	float deltaTheta;

	Ogre::Entity	*ent;
	Ogre::SceneNode *scnNode;

	EntityType entityType;

	std::list< Aspect *> al;

	// member functions

	Entity(EntityType entType);
	virtual ~Entity(){}

	void tick(float dt);

};



#endif /* ENTITY_H_ */
