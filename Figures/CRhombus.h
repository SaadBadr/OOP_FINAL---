#pragma once

#include "CFigure.h"


class CRhombus:public CFigure
{
private:
	int iD;
	Point center[1];
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool Isinside(int x, int y);
	virtual Point* getPoints();
	bool isSelected();
	void ChngFillClrState(bool c);
	void Save(ofstream &);
	void Load(ifstream & load);
	~CRhombus();
};

