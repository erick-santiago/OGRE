/*
 * InputMgr.cpp
 *
 *  Created on: Mar 7, 2020
 *      Author: esantiago
 */

#include "Engine.h"
#include "InputMgr.h"
#include "Globals.h"
#include "Functions.h"
#include "EntityMgr.h"

#include <OgreEntity.h>
#include <OgreConfigFile.h>
#include "OgreRenderWindow.h"
#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include "OgreViewport.h"
#include <iostream>

#include <OgreException.h>


InputMgr::InputMgr(Engine *engine)
	: Mgr( engine ), keyTime( 0.2f )
{
}

InputMgr::~InputMgr()
{
	Stop();
}

void InputMgr::Init()
{
	// initializing OIS
	Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
	OIS::ParamList pl;
	size_t windowHnd = 0;
	std::ostringstream windowHndStr;

	mWindow->getCustomAttribute("WINDOW", &windowHnd);
	windowHndStr << windowHnd;
	pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

	mInputManager = OIS::InputManager::createInputSystem( pl );

	mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, false ));
	mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, false ));

	//Set initial mouse clipping size
	windowResized(mWindow);

	// Register as a Window listener
	Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

	// registering our application as a FrameListener
	mRoot->addFrameListener(this);

}

void InputMgr::LoadLevel()
{

}

void InputMgr::Tick(float dt)
{

}

void InputMgr::Stop()
{
	//Remove ourself as a Window listener
	Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);

	windowClosed(mWindow);
}


//Adjust mouse clipping area
void InputMgr::windowResized(Ogre::RenderWindow* rw)
{
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);

    const OIS::MouseState &ms = mMouse->getMouseState();
    ms.width = width;
    ms.height = height;
}

//Unattach OIS before window shutdown (very important under Linux)
void InputMgr::windowClosed(Ogre::RenderWindow* rw)
{
    //Only close for window that created OIS (the main window in these demos)
    if(rw == mWindow)
    {
        if(mInputManager)
        {
            mInputManager->destroyInputObject( mMouse );
            mInputManager->destroyInputObject( mKeyboard );

            OIS::InputManager::destroyInputSystem(mInputManager);
            mInputManager = 0;
        }
    }
}

// we can perform our per-frame tasks in this frameRenderingQueued() function.
bool InputMgr::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
    if(mWindow->isClosed())
        return false;

    ////std::cout << "\nTest... frameRenderingQueued is called..." << std::endl;
    //Need to capture/update each device
    mKeyboard->capture();
    mMouse->capture();

    if(mKeyboard->isKeyDown(OIS::KC_ESCAPE))
    {
    	////std::cout << "\nTest... Escape was pressed..." << std::endl;
    	Ogre::LogManager::getSingletonPtr()->logMessage("***Test... Escape was pressed...  ***");
        return false;
    }

    updateCamera( fe );
    updateDesiredSpeedHeading( fe );
    updateSelection( fe );
    // left off here... adding updateDesired(fe) and polishing Globals.h...
    // for now okay but need to clean up

    return true;
}


void InputMgr::updateCamera(const Ogre::FrameEvent& fe)
{
	float move = 250.0f;
	float rotate = 0.01f;

		 Ogre::Vector3 camVec = Ogre::Vector3::ZERO;

		  if (mKeyboard->isKeyDown(OIS::KC_W))
		    camVec.z -= move;

		  if (mKeyboard->isKeyDown(OIS::KC_S))
		    camVec.z += move;

		  if (mKeyboard->isKeyDown(OIS::KC_E))
		    camVec.y += move;

		  if (mKeyboard->isKeyDown(OIS::KC_F))
		    camVec.y -= move;

		  if (mKeyboard->isKeyDown(OIS::KC_A))
		  {
		    if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
			      cameraNode->yaw(Ogre::Degree(5 * rotate));
		    else
		      camVec.x -= move;
		  }

		  if (mKeyboard->isKeyDown(OIS::KC_D))
		  {
		    if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
		      cameraNode->yaw(Ogre::Degree(-5 * rotate));
		    else
		      camVec.x += move;
		  }

		  cameraNode->translate(camVec * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);

}

void InputMgr::updateDesiredSpeedHeading(const Ogre::FrameEvent& fe)
{
	static float keyboardTimer = 0.0f;

	keyboardTimer -= fe.timeSinceLastFrame;

	if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_NUMPAD8)){
			keyboardTimer = keyTime;
			engine->entityMgr->selectedEntity()->desiredSpeed += engine->entityMgr->selectedEntity()->delta;
		}
		if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_NUMPAD2)){
			keyboardTimer = keyTime;
			engine->entityMgr->selectedEntity()->desiredSpeed -= engine->entityMgr->selectedEntity()->delta;
		}
		if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_NUMPAD4)){
			keyboardTimer = keyTime;
			engine->entityMgr->selectedEntity()->desiredHeading -= engine->entityMgr->selectedEntity()->deltaTheta;
		//turn left is decreasing degrees, turn right is increasing degrees because
		//increasing degrees gives us the +ive Z axis
		}
		if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_NUMPAD6)){
			keyboardTimer = keyTime;
			engine->entityMgr->selectedEntity()->desiredHeading += engine->entityMgr->selectedEntity()->deltaTheta;
		}
		engine->entityMgr->selectedEntity()->desiredHeading = FixAngle(engine->entityMgr->selectedEntity()->desiredHeading);

		//Set velocity to zero....
		if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_SPACE)){
			keyboardTimer = keyTime;
			engine->entityMgr->selectedEntity()->velVec = Ogre::Vector3::ZERO;
			engine->entityMgr->selectedEntity()->desiredSpeed = engine->entityMgr->selectedEntity()->speed = 0;
			engine->entityMgr->selectedEntity()->desiredHeading = engine->entityMgr->selectedEntity()->heading;
		}

}

void InputMgr::updateSelection(const Ogre::FrameEvent& fe)
{
	static float keyboardTimer = 0.0f;

	keyboardTimer -= fe.timeSinceLastFrame;

	  if( keyboardTimer < 0.0f)
	  {
		  if ( mKeyboard->isKeyDown(OIS::KC_TAB) )
		  {
			  keyboardTimer = keyTime;
			  engine->entityMgr->selectNextEntity();
		  }
	  }

}

