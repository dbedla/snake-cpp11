#ifndef MOVEFRAMEOBJ_H
#define MOVEFRAMEOBJ_H

template <typename FrameBasicElement, typename MoveDirection>
class IMoveFrameObj
{
public:
    //CMoveFrameObj();
    virtual void moveObj(FrameBasicElement&)  = 0;
    virtual void setDirection(const MoveDirection&) = 0;
    virtual MoveDirection getDirection() = 0;
    virtual ~IMoveFrameObj(){}
};

#endif // MOVEFRAMEOBJ_H
