/*
 * EntityMgr.h
 *
 *  Created on: Mar 12, 2020
 *      Author: esantiago
 */

#ifndef INC_ENTITYMGR_H_
#define INC_ENTITYMGR_H_

#include "Mgr.h"
#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>
#include "Entity.h"


class EntityMgr : public Mgr
{

public:

	EntityMgr(Engine *engine);
	~EntityMgr();

	void Init();
	void LoadLevel();
	void Tick(float dt);
	void Stop();

	Entity * createMyEntity(EntityType entType, Ogre::Vector3 pos);  // left off here...

	void selectNextEntity();
	Entity * selectedEntity();

	void tick(float dt);

	std::vector< Entity *> ev;

	static int unique_id;

	int entityCount;
	int vPos;  // position in vector container

private:


};



#endif /* INC_ENTITYMGR_H_ */
