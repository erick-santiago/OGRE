/*
 * GfxMgr.h
 *
 *  Created on: Mar 7, 2020
 *      Author: esantiago
 */

#ifndef INC_GFXMGR_H_
#define INC_GFXMGR_H_

#include "Mgr.h"
#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>


class GfxMgr : public Mgr//, public Ogre::WindowEventListener, public Ogre::FrameListener
{

public:

	GfxMgr(Engine *engine);
	~GfxMgr();

	void Init();
	void LoadLevel();
	void Tick(float dt);
	void Stop();

protected:

	// Ogre::FrameListener
	//Overrides Ogre::FrameListener::frameRenderingQueued via Ogre::FrameListener
	//virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

private:

	Ogre::String mResourcesCfg;
	Ogre::String mPluginsCfg;

};



#endif /* INC_GFXMGR_H_ */
