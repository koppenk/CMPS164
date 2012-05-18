#ifndef CUP_H
#define CUP_H

#pragma once
#include "util.h"
#include "Drawable.h"
#include "GameObject.h"

class cup : public GameObject, Drawable
{
public:
	cup(int pID, Vec3f pPosition, Vec3f pColor, float pRadius);
	~cup();
	Vec3f getPosition();
	void draw();
	string toString();
	AUTO_SIZE;
private:


	Vec3f position;
	float radius;
};

#endif
