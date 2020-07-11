/*
 * InputMgr.h
 *
 *  Created on: Mar 7, 2020
 *      Author: esantiago
 */

#ifndef INC_INPUTMGR_H_
#define INC_INPUTMGR_H_

#include "Mgr.h"
#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>


class InputMgr : public Mgr, public Ogre::WindowEventListener, public Ogre::FrameListener
{

public:

	InputMgr(Engine *engine);
	~InputMgr();

	void Init();
	void LoadLevel();
	void Tick(float dt);
	void Stop();

	void updateCamera(const Ogre::FrameEvent& fe);
	void updateDesiredSpeedHeading(const Ogre::FrameEvent& fe);
	void updateSelection(const Ogre::FrameEvent& fe);

protected:

	// Ogre::WindowEventListener
	virtual void windowResized(Ogre::RenderWindow* rw);  // overrides Ogre::WindowEventListener::windowResized
	virtual void windowClosed(Ogre::RenderWindow* rw);   // overrides Ogre::WindowEventListener::windowClosed

	// Ogre::FrameListener
	//Overrides Ogre::FrameListener::frameRenderingQueued via Ogre::FrameListener
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);

private:

	float keyTime;

};



#endif /* INC_INPUTMGR_H_ */
