#ifndef CBASICWALL_H
#define CBASICWALL_H

#include "CPoint.h"
#include "IFrameElement.h"

class CBasicWall: public IFrameElement<PointsList >
{
public:
    CBasicWall(unsigned int widith, unsigned int height);
    virtual const PointsList& getFrameElements() const;

private:
    PointsList _wall;

};

#endif // CBASICWALL_H
