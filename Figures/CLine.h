#pragma once

#include "CFigure.h"

class CLine: public CFigure
{
private:
	int iD;
	Point terminal[2];
public:
	CLine(Point,Point,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool Isinside(int x, int y);
	virtual Point* getPoints();
	bool isSelected();
	void Save(ofstream &);
	void Load(ifstream & load);
	~CLine();
};

