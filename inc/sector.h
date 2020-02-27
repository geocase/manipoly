#ifndef SECTOR_H
#define SECTOR_H

#include <vector>

class cNode;
class cLineDef;
class cSector;

class cNode {
public:
	double x = 0, y = 0;
	
	void Rotate(const double ax, const double ay, const double r);
	void Translate(const double nx, const double ny);
};

class cLineDef {
public:
	cNode *a, *b;

	cLineDef(double ax, double ay, double bx, double by);
	cLineDef(cNode *na, cNode *nb);
};

class cSector  {
public:
	std::vector<cLineDef> faces;
	uint32_t faceCount = 0;

	void AddFace(const cLineDef *l);
	void BuildFromNodes(cNode *p, uint32_t nc);
};

#endif
