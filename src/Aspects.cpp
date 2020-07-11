/*
 * Aspects.cpp
 *
 *  Created on: Feb 20, 2020
 *      Author: esantiago
 */

#include "Aspects.h"
#include "math.h"
#include "Functions.h"
#include <OgreSceneNode.h>
#include <OgreNode.h>
#include <OgreEntity.h>
#include "OgreVector3.h"
#include <iostream>

#define PI 3.14159265

Physics::Physics(Entity *ent)
	: Aspect(ent)
{
	aspectType = PHYSICSASP;
}

Physics::~Physics(){}


void Physics::tick(float dt)
{
		//first, get new speed from desired speed
		if(entity->desiredSpeed > entity->speed){
			entity->speed += entity->acceleration * dt;
		} else if (entity->desiredSpeed < entity->speed){
			entity->speed -= entity->acceleration * dt;
		}
		entity->speed = Clamp(entity->minSpeed, entity->maxSpeed, entity->speed);

		//close but no cigar. When I try to go from a heading of 350 to a heading of 10,
		//I should turn to right/starboard not keep decreasing heading till I get to 10 because it is 20 degrees from -10 (350) to +10 by turning to port/right and
		//340 degrees from 350 (-10) to 10 by turning left/port

		//now, get new heading from desired heading
		if(entity->desiredHeading > entity->heading){
			if(entity->desiredHeading - entity->heading > 180)
				entity->heading -= entity->turnRate * dt;
			else
				entity->heading += entity->turnRate * dt;
		} else if (entity->desiredHeading < entity->heading){
			if(entity->desiredHeading - entity->heading < -180)
				entity->heading += entity->turnRate * dt;
			else
				entity->heading -= entity->turnRate * dt;;
		}
		// now fixing heading angle to stay within 0-360 (degrees) bounds
		entity->heading = FixAngle(entity->heading);

		//Now do the trig
		entity->velVec.y = 0.0f; // just to be safe, we do not want ships in the air.
		entity->velVec.x = Ogre::Math::Cos(Ogre::Degree(entity->heading)) * entity->speed; //adjacent/hyp
		entity->velVec.z = Ogre::Math::Sin(Ogre::Degree(entity->heading)) * entity->speed; //opposite/hyp

		//This does not change!
		entity->posVec += entity->velVec * dt;

}


Render::Render(Entity *ent)
	: Aspect(ent)
{
	aspectType = RENDERASP;
}

Render::~Render(){}


void Render::tick(float dt)  // left off here... need to test this now...
{
	entity->scnNode->setPosition(entity->posVec); //now ogre should render the sceneNode at the new position...
	entity->scnNode->resetOrientation(); // yaw is relative to 0
	entity->scnNode->yaw(Ogre::Degree(-entity->heading));
		//bounding boxes are rendered so...
		//if(entity->isSelected)
			//entity->scnNode->showBoundingBox(true);
		//else
			//entity->scnNode->showBoundingBox(false); //or we could do this in the entity mgr every time tab is pressed....

}


