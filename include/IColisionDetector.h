#ifndef ICOLISIONDETECTOR_H
#define ICOLISIONDETECTOR_H

#include "IFrameElement.h"

template <typename Points>
class IColisionDetector
{
public:
    virtual bool operator()(IFrameElement<Points> &, IFrameElement<Points> &) = 0;
    virtual ~IColisionDetector(){}

};

#endif // ICOLISIONDETECTOR_H
