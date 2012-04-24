#include "renderManager.h"


renderManager::renderManager()
{
}


renderManager::~renderManager()
{
	cout << "render manager destructor";
}

void renderManager::drawLevel(CMMPointer<level> lev) {
	//get the level info
	std::map<int, CMMPointer<tile>> tiles = lev->getTiles();
	std::map<int, CMMPointer<ball>> balls = lev->getBalls();
	std::map<int, CMMPointer<tee>> tees = lev->getTees();
	std::map<int, CMMPointer<cup>> cups = lev->getCups();

	std::map<int, CMMPointer<tile>>::iterator itT;
	for ( itT=tiles.begin() ; itT != tiles.end(); itT++ ) {
		drawTile((*itT).second);
	}
	
	std::map<int, CMMPointer<ball>>::iterator itB;
	for ( itB=balls.begin() ; itB!= balls.end(); itB++ ) {
		drawBall((*itB).second);
	}

	std::map<int, CMMPointer<cup>>::iterator itC;
	for ( itC=cups.begin() ; itC != cups.end(); itC++ ) {
		drawCup((*itC).second);
	}
	

	
}

void renderManager::drawTile(CMMPointer<tile> t) 
{
	GLfloat tileColor[3] = { 0.0f, 0.9f, 0.0f };
	glColor3fv(tileColor);
	Vec3f normal = t->getNormal();
	Vec3f* vertices = t->getVertices();
	int numVerts = t->getNumVertices();

	glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(normal[0], normal[1], normal[2]);
		for (int i = 0; i < numVerts; i++)
		{
			glVertex3f(vertices[i][0], vertices[i][1], vertices[i][2]);
		}
	glEnd();
}

void renderManager::drawBall(CMMPointer<ball> b) 
{
	Vec3f position = b->getPosition();
	GLfloat ballColor[3] = { 1.0f, 0.0f, 0.0f };
	glColor3fv(ballColor);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(position[0], position[1], position[2]);
	glutSolidSphere(.05, 10, 10);
	glPopMatrix();
}


void renderManager::drawCup(CMMPointer<cup> c) 
{
	Vec3f position = c->getPosition();
	GLfloat ballColor[3] = { 0.0f, 0.0f, 0.0f };
	glColor3fv(ballColor);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(position[0], position[1], position[2]);
	glutSolidSphere(.07, 10, 10);
	glPopMatrix();
}

