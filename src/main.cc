#include <iostream>

#include "sector.h"
#include "window.h"

int main() {
	cWindow primWin;

	sNode *points = new sNode[4];
	points[0].x = 10;
	points[0].y = 10;
	points[1].x = 20;
	points[1].y = 10;
	points[2].x = 20;
	points[2].y = 20;
	points[3].x = 10;
	points[3].y = 20;

	
	cSector quad;

	for(int i = 0; i < 4; i++) {
		if(i + 1 > 3) {
			quad.AddFace(new cLineDef(points[i], points[i-1]));
		} else {
			quad.AddFace(new cLineDef(points[i], points[i+1]));
		}
	}

	sNode tempA;
	sNode tempB;

	for(int i = 0; i < 4; i++) {
		tempA = quad.faces.at(i).a;
		tempB = quad.faces.at(i).b;

		std::cout << tempA.x << ", " << tempA.y << " : " << tempB.x << ", " << tempB.y << std::endl;
	}

	std::cout << "faces: " << quad.faceCount << std::endl;

	return 0;
}
