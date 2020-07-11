/*
 * Globals.cpp
 *
 *  Created on: Mar 7, 2020
 *      Author: esantiago
 */

#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include "Globals.h"


Ogre::Root* mRoot = NULL;
Ogre::RenderWindow* mWindow = NULL;
Ogre::SceneManager* mSceneMgr = NULL;
Ogre::Camera* mCamera = NULL;
Ogre::SceneNode* cameraNode = NULL;

OIS::InputManager* mInputManager = NULL;
OIS::Mouse* mMouse = NULL;
OIS::Keyboard* mKeyboard = NULL;


