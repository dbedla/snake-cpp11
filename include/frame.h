#ifndef FRAME_H
#define FRAME_H

#include <algorithm>
#include <unistd.h>
#include <sys/ioctl.h>
#include <iostream>
#include "CPoint.h"
#include "IFrameElement.h"
#include <algorithm>
#include <functional>

#include <cstdio>
#include <termios.h>

/*
  Poin 0,0 is in top righrt corner
  */
typedef char GraphicalRepresentation;
const GraphicalRepresentation EMPTY_FIELD = ' ';


class CFrame
{
public:
    CFrame();
    void SetPoint(const CPoint p, GraphicalRepresentation graphPointRep);
    void drawFrame();
    void drawObjIntoFrame(const IFrameElement<PointsList >&, GraphicalRepresentation graphPointRep);
    void clearFrame();
    unsigned int getWidith();
    unsigned int getHeight();
private:
    std::vector< std::vector<char> > _frame;

};

#endif // FRAME_H
