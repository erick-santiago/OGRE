/*
 * GameMgr.cpp
 *
 *  Created on: Mar 7, 2020
 *      Author: esantiago
 */

#include "Engine.h"
#include "GameMgr.h"
#include "Globals.h"

#include <vector>
#include <memory>
#include "Entity.h"
#include "Entities.h"
#include "EntityMgr.h"
#include <OgreMeshManager.h>

#include <OgreEntity.h>
//#include <OgreConfigFile.h>
//#include "OgreRenderWindow.h"
#include <OgreSceneManager.h>
//#include <OgreCamera.h>
//#include "OgreViewport.h"
#include <iostream>

#include <OgreException.h>


GameMgr::GameMgr(Engine *engine)
	: Mgr( engine )
{
}

GameMgr::~GameMgr()
{
	Stop();
}

void GameMgr::Init()  // left off here... running the program... maybe should be in LoadLevel()?
{
	// setting up the Scene ***************************************

	const Ogre::Real surfaceHeight = 0;
		EntityType Destroyer = DESTROYER;
		EntityType Carrier	 = CARRIER;
		EntityType Speedboat = SPEEDBOAT;
		EntityType Frigate	 = FRIGATE;
		EntityType AlienShip = ALIENSHIP;

	    mSceneMgr->setAmbientLight(Ogre::ColourValue(.25, .25, .25));

	  	// Create ground
	    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, surfaceHeight);

	    Ogre::MeshManager::getSingleton().createPlane(
	      "ground",
	      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	      plane, 10000, 10000, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

	    Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

	    groundEntity->setMaterialName("Ocean2_Cg");
	    groundEntity->setCastShadows(false);

	    // Create SkyBox
	    mSceneMgr->setSkyBox(true, "Examples/MorningSkyBox");

	  Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
	  pointLight->setType(Ogre::Light::LT_POINT);
	  pointLight->setPosition(250, 150, 250);
	  pointLight->setDiffuseColour(Ogre::ColourValue::White);
	  pointLight->setSpecularColour(Ogre::ColourValue::White);

	  engine->entityMgr->ev.push_back( engine->entityMgr->createMyEntity(AlienShip, Ogre::Vector3(-100,1,300)) );
	  engine->entityMgr->ev.push_back( engine->entityMgr->createMyEntity(Speedboat, Ogre::Vector3(-100,1,150)) );
	  engine->entityMgr->ev.push_back( engine->entityMgr->createMyEntity(Frigate, Ogre::Vector3(-100,1,0)) );
	  engine->entityMgr->ev.push_back( engine->entityMgr->createMyEntity(Destroyer, Ogre::Vector3(-100,1,-150)) );
	  engine->entityMgr->ev.push_back( engine->entityMgr->createMyEntity(Carrier, Ogre::Vector3(-100,1,-300)) );


	  engine->entityMgr->ev.at(vPos)->scnNode->showBoundingBox(true);
}

void GameMgr::LoadLevel()
{

}

void GameMgr::Tick(float dt)
{

}

void GameMgr::Stop()
{

}


// left off here... might remove some #includes...

