#include <iostream>
#include <cmath>
#include "sector.h"

void cNode::Rotate(const double ax, const double ay, const double r) {
	double nx = (this->x - ax) * std::cos(r) - (this->y - ay) * std::sin(r);
	double ny = (this->y - ay) * std::cos(r) + (this->x - ax) * std::sin(r);

	this->x = nx + ax;
	this->y = ny + ay;
}

void cNode::Translate(const double nx, const double ny) {
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
