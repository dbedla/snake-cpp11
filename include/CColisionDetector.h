#ifndef CCOLISIONDETECTOR_H
#define CCOLISIONDETECTOR_H

#include "IFrameElement.h"
#include "CPoint.h"

class CColisionDetector
{
public:
    CColisionDetector(){}
    bool operator()(IFrameElement<PointsList> &movableObj, IFrameElement<PointsList> &staticObj);
};

#endif // CCOLISIONDETECTOR_H
