#ifndef SECTOR_H
#define SECTOR_H

#include <vector>

class cNode;
class cLineDef;
class cSector;

class cNode {
public:
	int32_t x = 0, y = 0;
	void Translate(const int32_t nx, const int32_t ny);
};

class cLineDef {
public:
	cNode *a, *b;

	cLineDef(int32_t ax, int32_t ay, int32_t bx, int32_t by);
	cLineDef(cNode *na, cNode *nb);
};

class cSector  {
public:
	std::vector<cLineDef> faces;
	uint32_t faceCount = 0;

	void AddFace(const cLineDef *l);
};

#endif
