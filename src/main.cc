#include <iostream>

#include "sector.h"
#include "window.h"
#include "input.h"

#define NODES 4

int main() {
	srand(time(NULL));
	cWindow primWin;
	cInput primIn;
	cVertex *points = new cVertex[NODES];
		
	points[0].PlaceAt(primWin.winx / 2 - 100, primWin.winy / 2 - 100);
	points[1].PlaceAt(primWin.winx / 2 + 100, primWin.winy / 2 - 100);
	points[2].PlaceAt(primWin.winx / 2 + 100, primWin.winy / 2 + 100);
	points[3].PlaceAt(primWin.winx / 2 - 100, primWin.winy / 2 + 100);

//	for(int l = 0; l < NODES; l++) {
//		points[l].PlaceAt(rand() % primWin.winx, rand() % primWin.winy);
//	}

	cPolygon quad;
	quad.BuildFromVertexArray(points, NODES);	

	cVertex tempA;
	cVertex tempB;

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
		points[3].PlaceAt(primIn.mouseX, primIn.mouseY);
		points[1].PlaceAt(primIn.mouseX, primIn.mouseY);
		points[1].Rotate(primWin.winx / 2, primWin.winy / 2, 3.14);
		points[0].Rotate(primWin.winx / 2, primWin.winy / 2, -.001);
		points[2].Rotate(primWin.winx / 2, primWin.winy / 2, -.001);
		primWin.Update();
		primIn.Update();
	}
	std::cout << "faces: " << quad.faceCount << std::endl;

	return 0;
}
