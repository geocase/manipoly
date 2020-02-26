#include <iostream>

#include "sector.h"
#include "window.h"

#define NODES 1000

int main() {
	srand(time(NULL));
	cWindow primWin;

	sNode *points = new sNode[NODES];
		
	cSector quad;

	for(int i = 0; i < NODES; i++) {
		if(i + 1 > NODES - 1) {
			quad.AddFace(new cLineDef(&points[i], &points[0]));
		} else {
			quad.AddFace(new cLineDef(&points[i], &points[i+1]));
		}
	}

	sNode tempA;
	sNode tempB;

	sColor_t col;
	col.r = 255;
	col.g = 255;
	col.b = 255;
	col.a = 255;
	

	for(int k = 0; k < 10000; k++) {	
		for(int m = 0; m < NODES; m++) {
				points[m].x = rand() % primWin.winx;
				points[m].y = rand() % primWin.winy;
		}	
		for(int i = 0; i < quad.faceCount; i++) {
			tempA = *(quad.faces.at(i).a);
			tempB = *(quad.faces.at(i).b);
			primWin.DrawLine(tempA.x, tempA.y, tempB.x, tempB.y, col);
		}
		
		primWin.Update();
	}
	std::cout << "faces: " << quad.faceCount << std::endl;

	return 0;
}
