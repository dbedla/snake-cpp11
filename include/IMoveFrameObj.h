#ifndef MOVEFRAMEOBJ_H
#define MOVEFRAMEOBJ_H

template <typename FrameBasicElement, typename MoveDirection>
class IMoveFrameObj
{
public:
    //CMoveFrameObj();
    virtual void moveObj(FrameBasicElement&)  {}
    virtual void setDirection(MoveDirection&) {}
    virtual MoveDirection getDirection() {}
    virtual ~IMoveFrameObj(){}
};

#endif // MOVEFRAMEOBJ_H
