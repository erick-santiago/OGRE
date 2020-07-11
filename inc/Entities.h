/*
 * Entities.h
 *
 *  Created on: Feb 16, 2020
 *      Author: esantiago
 */

#ifndef ENTITIES_H_
#define ENTITIES_H_

#include "Entity.h"


class Cube : public Entity
{

public:

	Cube();  // left off here...

};

class Sphere : public Entity
{

public:

	Sphere();

};

class Destroyer : public Entity
{

public:

	Destroyer();

};

class Carrier : public Entity
{

public:

	Carrier();

};

class Speedboat : public Entity
{

public:

	Speedboat();

};

class Frigate : public Entity
{

public:

	Frigate();

};

class AlienShip : public Entity
{

public:

	AlienShip();

};

#endif /* ENTITIES_H_ */
