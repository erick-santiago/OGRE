/*
 * EntityMgr.cpp
 *
 *  Created on: Mar 12, 2020
 *      Author: esantiago
 */

#include "Entities.h"
#include "EntityMgr.h"
#include "Globals.h"
#include "Enums.h"

#include <OgreEntity.h>
//#include <OgreConfigFile.h>
//#include "OgreRenderWindow.h"
#include <OgreSceneManager.h>
//#include <OgreCamera.h>
//#include "OgreViewport.h"
#include <iostream>

#include <OgreException.h>

int EntityMgr::unique_id = 0;  // left off here... need to clean and polish design and implementation

EntityMgr::EntityMgr(Engine *engine)
	: Mgr( engine ), entityCount(0), vPos(0)
{
}

EntityMgr::~EntityMgr()
{
	Stop();
}

void EntityMgr::Init()
{

}

void EntityMgr::LoadLevel()
{

}

void EntityMgr::Tick(float dt)
{
	for (auto it = ev.begin(); it != ev.end(); ++it)
	{
		(*it)->tick( dt );
	}

	//std::cout << "\ntest2";
}

void EntityMgr::Stop()
{

}


Entity * EntityMgr::createMyEntity(EntityType entType, Ogre::Vector3 pos)
{
	Ogre::String id = Ogre::StringConverter::toString(unique_id);

	Entity *entity;

	switch( entType )
	{
	case CUBE:
		entity = new Cube();

		entity->ent = mSceneMgr->createEntity(entity->entName + id, entity->meshName);
		entity->ent->setMaterialName("Examples/TrippySkyBox");
		entity->scnNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(entity->nodeName + id);
		entity->scnNode->setPosition( pos );
		entity->posVec = pos;
		entity->scnNode->attachObject( entity->ent );
		entity->scnNode->showBoundingBox(false);
		++unique_id;
		++entityCount;
		break;
	case SPHERE:
		entity = new Sphere();

		entity->ent = mSceneMgr->createEntity(entity->entName + id, entity->meshName);
		//entity->ent->setMaterialName("Examples/SphereMappedRustySteel");
		entity->ent->setMaterialName("Examples/SphereMappedRustySteel");
		entity->scnNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(entity->nodeName + id);
		entity->scnNode->setPosition( pos );
		entity->posVec = pos;
		entity->scnNode->attachObject( entity->ent );
		entity->scnNode->showBoundingBox(false);
		++unique_id;
		++entityCount;
		break;
	case DESTROYER:
			entity = new Destroyer();

			entity->ent = mSceneMgr->createEntity(entity->entName + id, entity->meshName);
			//entity->ent->setMaterialName("Examples/TrippySkyBox");
			entity->scnNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(entity->nodeName + id);
			entity->scnNode->setPosition( pos );
			entity->posVec = pos;
			entity->scnNode->attachObject( entity->ent );
			entity->scnNode->showBoundingBox(false);
			++unique_id;
			++entityCount;
			break;
	case CARRIER:
			entity = new Carrier();

			entity->ent = mSceneMgr->createEntity(entity->entName + id, entity->meshName);
			//entity->ent->setMaterialName("Examples/TrippySkyBox");
			entity->scnNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(entity->nodeName + id);
			entity->scnNode->setPosition( pos );
			entity->posVec = pos;
			entity->scnNode->attachObject( entity->ent );
			entity->scnNode->showBoundingBox(false);
			++unique_id;
			++entityCount;
			break;
	case SPEEDBOAT:
			entity = new Speedboat();

			entity->ent = mSceneMgr->createEntity(entity->entName + id, entity->meshName);
			//entity->ent->setMaterialName("Examples/TrippySkyBox");
			entity->scnNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(entity->nodeName + id);
			entity->scnNode->setPosition( pos );
			entity->posVec = pos;
			entity->scnNode->attachObject( entity->ent );
			entity->scnNode->showBoundingBox(false);
			++unique_id;
			++entityCount;
			break;
	case FRIGATE:
			entity = new Frigate();

			entity->ent = mSceneMgr->createEntity(entity->entName + id, entity->meshName);
			//entity->ent->setMaterialName("Examples/TrippySkyBox");
			entity->scnNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(entity->nodeName + id);
			entity->scnNode->setPosition( pos );
			entity->posVec = pos;
			entity->scnNode->attachObject( entity->ent );
			entity->scnNode->showBoundingBox(false);
			++unique_id;
			++entityCount;
			break;
	case ALIENSHIP:
			entity = new AlienShip();

			entity->ent = mSceneMgr->createEntity(entity->entName + id, entity->meshName);
			//entity->ent->setMaterialName("Examples/TrippySkyBox");
			entity->scnNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(entity->nodeName + id);
			entity->scnNode->setPosition( pos );
			entity->posVec = pos;
			entity->scnNode->attachObject( entity->ent );
			entity->scnNode->showBoundingBox(false);
			++unique_id;
			++entityCount;
			break;
	}

	return entity;

}

void EntityMgr::selectNextEntity()
{
	ev.at(vPos)->scnNode->showBoundingBox(false);
	++vPos;
	if( vPos >= entityCount )
		vPos = 0;
	ev.at(vPos)->scnNode->showBoundingBox(true);
}

Entity * EntityMgr::selectedEntity()
{
	return ev.at(vPos);
}


// left off here... might remove some #includes...



