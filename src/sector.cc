#include <iostream>
#include "sector.h"

void cNode::Translate(const int32_t nx, const int32_t ny) {
	this->x = nx;
	this->y = ny;
}

cLineDef::cLineDef(int32_t ax, int32_t ay, int32_t bx, int32_t by) {
	this->a->x = ax;
	this->a->y = ay;
	this->b->x = bx;
	this->b->y = by;
}

cLineDef::cLineDef(cNode *na, cNode *nb) {
	this->a = na;
	this->b = nb;
}

void cSector::AddFace(const cLineDef *l) {
	this->faces.push_back(*l);	
	this->faceCount++;
}
