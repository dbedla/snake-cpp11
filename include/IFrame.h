#ifndef IFRAME_H
#define IFRAME_H

template<typename GridUnit, typename GraphRep, typename Point>
class IFrame
{
public:
    //void SetPoint(const CPoint p, GraphicalRepresentation graphPointRep);
    virtual void drawFrame() = 0;
    virtual void drawObjIntoFrame(const IFrameElement<Point >&, GraphRep) = 0;
    virtual void clearFrame() = 0;
    virtual GridUnit getWidith() = 0;
    virtual GridUnit getHeight() = 0;
    virtual ~IFrame();
};

#endif // IFRAME_H
