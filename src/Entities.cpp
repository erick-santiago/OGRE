/*
 * Entities.cpp
 *
 *  Created on: Feb 16, 2020
 *      Author: esantiago
 */

#include "Entity.h"
#include "Entities.h"
#include "math.h"

#define PI 3.14159265


Cube::Cube()
	: Entity(CUBE)
{
	meshName = "cube.mesh";
	entName  = "Cube: ";
	nodeName = "cubeNode";

}

Sphere::Sphere()
	: Entity(SPHERE)
{
	meshName = "sphere.mesh";
	entName  = "Sphere: ";
	nodeName = "sphereNode";

}

Destroyer::Destroyer()
	: Entity(DESTROYER)
{
	meshName = "ddg51.mesh";
	entName  = "Destroyer: ";
	nodeName = "DestroyerNode";

	minSpeed = 0;
	maxSpeed = 16.0f;//meters per second...
	acceleration = 5.0f; // fast
	turnRate = 5.0f;

}

Carrier::Carrier()
	: Entity(CARRIER)
{
	meshName = "cvn68.mesh";
	entName  = "Carrier: ";
	nodeName = "CarrierNode";

	minSpeed = 0;
	maxSpeed = 20.0f;//meters per second...
	acceleration = 1.0f; // slow
	turnRate = 2.0f;
	heading = 0;
	desiredHeading = 0;

}

Speedboat::Speedboat()
	: Entity(SPEEDBOAT)
{
	meshName = "cigarette.mesh";
	entName  = "Speedboat: ";
	nodeName = "SpeedboatNode";

	minSpeed = 0;
	maxSpeed = 30.0f;//meters per second...
	acceleration = 10.0f; // slow
	turnRate = 10.0f;

}

Frigate::Frigate()
	: Entity(FRIGATE)
{
	meshName = "sleek.mesh";
	entName  = "Frigate: ";
	nodeName = "FrigateNode";

	minSpeed = 0;
	maxSpeed = 15.0f;//meters per second...
	acceleration = 5.0f; // slow
	turnRate = 7.0f;

}

AlienShip::AlienShip()
	: Entity(ALIENSHIP)
{
	meshName = "alienship.mesh";
	entName  = "AlienShip: ";
	nodeName = "AlienShipNode";

	minSpeed = 0;
	maxSpeed = 50.0f;//meters per second...
	acceleration = 20.0f; // slow
	turnRate = 20.0f;

}

