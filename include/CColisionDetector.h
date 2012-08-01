#ifndef CCOLISIONDETECTOR_H
#define CCOLISIONDETECTOR_H

#include "IColisionDetector.h"
#include "IFrameElement.h"
#include "CPoint.h"

class CColisionDetector: public IColisionDetector<PointsList>
{
public:
    CColisionDetector(){}
    bool operator()(IFrameElement<PointsList> &movableObj, IFrameElement<PointsList> &staticObj);
    virtual ~CColisionDetector(){}
};

#endif // CCOLISIONDETECTOR_H
