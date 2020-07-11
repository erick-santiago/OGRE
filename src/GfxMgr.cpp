/*
 * GfxMgr.cpp
 *
 *  Created on: Mar 7, 2020
 *      Author: esantiago
 */

#include "Engine.h"
#include "GfxMgr.h"
#include "Globals.h"

#include <OgreEntity.h>
#include <OgreConfigFile.h>
#include "OgreRenderWindow.h"
#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include "OgreViewport.h"
#include <iostream>

#include <OgreException.h>


GfxMgr::GfxMgr(Engine *engine)
	: Mgr( engine ), mResourcesCfg(Ogre::StringUtil::BLANK),
	  mPluginsCfg(Ogre::StringUtil::BLANK)
{
}

GfxMgr::~GfxMgr()
{
	Stop();
}

void GfxMgr::Init()
{
#ifdef _DEBUG
  mResourcesCfg = "resources_d.cfg";
  mPluginsCfg = "plugins_d.cfg";
#else
  mResourcesCfg = "resources.cfg";
  mPluginsCfg = "plugins.cfg";
#endif

  // creating the Root Object ************************************

  mRoot = new Ogre::Root(mPluginsCfg);

  // setting up our applications resources ************************

  Ogre::ConfigFile cf;
  cf.load(mResourcesCfg);

  Ogre::String name, locType;
  Ogre::ConfigFile::SectionIterator secIt = cf.getSectionIterator();

    while (secIt.hasMoreElements())
    {
      Ogre::ConfigFile::SettingsMultiMap* settings = secIt.getNext();
      Ogre::ConfigFile::SettingsMultiMap::iterator it;

      for (it = settings->begin(); it != settings->end(); ++it)
      {
        locType = it->first;
        name = it->second;

        Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, locType);
      }
    }

    // configuring the RenderSystem ******************************

    if (!(mRoot->restoreConfig() || mRoot->showConfigDialog()))
    {
    	std::cout << "\nNeed to throw Exception here and delete 'Ogre.cfg' file...";
    }

    // creating a RenderWindow ************************************

    mWindow = mRoot->initialise(true, "As4 Render Window");

    // initializing resources *************************************

    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    // creating a Scene Manager************************************

        mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);

    // creating the Camera ****************************************

    mCamera = mSceneMgr->createCamera("MainCam");

    mCamera->setPosition(Ogre::Vector3(0, 75, 600));
    mCamera->lookAt(Ogre::Vector3(100, 0, -200));
    mCamera->setNearClipDistance(5);

    // A node to attach the camera to so we can move the camera node instead of the camera.
    cameraNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    cameraNode->setPosition(0, 200, 500);
    cameraNode->attachObject(mCamera);

    // adding a ViewPort ******************************************

    Ogre::Viewport* vp = mWindow->addViewport(mCamera);

    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

    mCamera->setAspectRatio(
      Ogre::Real(vp->getActualWidth()) /
      Ogre::Real(vp->getActualHeight()));

    // registering our application as a FrameListener
    //mRoot->addFrameListener(this);


}

void GfxMgr::LoadLevel()
{

}

void GfxMgr::Tick(float dt)
{
	Ogre::WindowEventUtilities::messagePump();

	if( !mRoot->renderOneFrame() )
	{
		Ogre::LogManager::getSingletonPtr()->logMessage("***Test... renderOneFrame() is called and is false...  ***");
		engine->keepRunning = false;
	}
}

void GfxMgr::Stop()
{
	delete mRoot;
}










