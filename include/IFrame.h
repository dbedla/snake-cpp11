#ifndef IFRAME_H
#define IFRAME_H

#include"IFrameElement.h"

template<typename GridUnit, typename GraphRep, typename Points>
class IFrame
{
public:
    //void SetPoint(const CPoint p, GraphicalRepresentation graphPointRep);
    //IFrame(){}
    virtual void drawFrame() = 0;
    virtual void drawObjIntoFrame(const IFrameElement<Points >&, GraphRep) = 0;
    virtual void clearFrame() = 0;
    virtual GridUnit getWidith() = 0;
    virtual GridUnit getHeight() = 0;
    virtual ~IFrame(){}
};

#endif // IFRAME_H
