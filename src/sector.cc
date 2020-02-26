#include <iostream>
#include "sector.h"

cLineDef::cLineDef(int32_t ax, int32_t ay, int32_t bx, int32_t by) {
	this->a->x = ax;
	this->a->y = ay;
	this->b->x = bx;
	this->b->y = by;
}

cLineDef::cLineDef(sNode *na, sNode *nb) {
	this->a = na;
	this->b = nb;
}

void cSector::AddFace(const cLineDef *l) {
	this->faces.push_back(*l);	
	this->faceCount++;
}
