#include <iostream>

#include "sector.h"
#include "window.h"

#define NODES 4

int main() {
	srand(time(NULL));
	cWindow primWin;

	cNode *points = new cNode[NODES];
		
	points[0].Translate(primWin.winx / 2 - 100, primWin.winy / 2 - 100);
	points[1].Translate(primWin.winx / 2 + 100, primWin.winy / 2 - 100);
	points[2].Translate(primWin.winx / 2 + 100, primWin.winy / 2 + 100);
	points[3].Translate(primWin.winx / 2 - 100, primWin.winy / 2 + 100);

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

	for(int k = 0; k < 15000; k++) {				
		for(int i = 0; i < quad.faceCount; i++) {
			tempA = *(quad.faces.at(i).a);
			tempB = *(quad.faces.at(i).b);
			primWin.DrawLine(tempA.x, tempA.y, tempB.x, tempB.y, col);
		}
		for(int m = 0; m < NODES; m++) {
			points[m].Rotate(primWin.winx / 2, primWin.winy / 2, .001);
		} 
		
		primWin.Update();
	}
	std::cout << "faces: " << quad.faceCount << std::endl;

	return 0;
}
