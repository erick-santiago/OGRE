/*
 * Globals.h
 *
 *  Created on: Mar 7, 2020
 *      Author: esantiago
 */

#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_

#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>


extern 	  Ogre::Root* mRoot;
extern    Ogre::RenderWindow* mWindow;
extern    Ogre::SceneManager* mSceneMgr;
extern    Ogre::Camera* mCamera;
extern    Ogre::SceneNode* cameraNode;

extern    OIS::InputManager* mInputManager;
extern    OIS::Mouse* mMouse;
extern    OIS::Keyboard* mKeyboard;



#endif /* INC_GLOBALS_H_ */
