#include "GameObject.h"


GameObject::GameObject(int pID, Vec3f pNormal){
	id = pID;
	normal = pNormal;
}


int GameObject::getID() {
	return id;
}
