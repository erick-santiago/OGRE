/*
 * GameMgr.h
 *
 *  Created on: Mar 7, 2020
 *      Author: esantiago
 */

#ifndef INC_GAMEMGR_H_
#define INC_GAMEMGR_H_

#include "Mgr.h"
#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>


class GameMgr : public Mgr
{

public:

	GameMgr(Engine *engine);
	~GameMgr();

	void Init();
	void LoadLevel();
	void Tick(float dt);
	void Stop();

private:

	int vPos = 0;  // position in vector container

};


#endif /* INC_GAMEMGR_H_ */
