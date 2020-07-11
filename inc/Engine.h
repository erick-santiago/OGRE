/*
 * Engine.h
 *
 *  Created on: Feb 20, 2020
 *      Author: sushil
 */

#ifndef ENGINE_H_
#define ENGINE_H_

class EntityMgr;
class GameMgr;
class GfxMgr;
class InputMgr;

class Engine {
public:
	Engine();
	virtual ~Engine();

	EntityMgr *entityMgr;
	GameMgr   *gameMgr;
	GfxMgr    *gfxMgr;
	InputMgr  *inputMgr;

	void Init();
	void Run();
	void TickAll(float dt);
	void Cleanup();

	bool keepRunning;
};

#endif /* ENGINE_H_ */
