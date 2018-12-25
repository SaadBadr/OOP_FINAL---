#pragma once

#include "CFigure.h"

class CTriangle:public CFigure
{
private:
	int iD;
	Point vertices[3];
public:
	CTriangle(Point p, Point p1, Point p2, GfxInfo FigureGfxInfo);
	virtual void Draw(Output*pOut)const;
	virtual Point* getPoints();
	bool Isinside(int x, int y);
	void ChngFillClrState(bool c);
	void Save(ofstream &);
	void Load(ifstream & load);
	~CTriangle();
};

