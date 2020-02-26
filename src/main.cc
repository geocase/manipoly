#include <iostream>

#include "sector.h"
#include "window.h"

#define NODES 2

int main() {
	srand(time(NULL));
	cWindow primWin;

	cNode *points = new cNode[NODES];
		
	points[0].Translate(primWin.winx / 2, primWin.winy / 2);
//	points[0].Translate(0, 0);
//	points[1].Translate(100, 0);
	points[1].Translate(primWin.winx / 2 + 100, primWin.winy / 2);

	cSector quad;

	for(int i = 0; i < NODES; i++) {
		if(i + 1 > NODES - 1) {
			quad.AddFace(new cLineDef(&points[i], &points[0]));
		} else {
			quad.AddFace(new cLineDef(&points[i], &points[i+1]));
		}
	}

	cNode tempA;
	cNode tempB;

	sColor_t col;
	col.r = 255;
	col.g = 255;
	col.b = 255;
	col.a = 255;

	for(int k = 0; k < 10000; k++) {				
		for(int i = 0; i < quad.faceCount; i++) {
			primWin.DrawLine(points[0].x, points[0].y, points[1].x, points[1].y, col);
		}
		points[1].Rotate(points[0].x, points[0].y, .001);
		
		primWin.Update();
	}
	std::cout << "faces: " << quad.faceCount << std::endl;

	return 0;
}
