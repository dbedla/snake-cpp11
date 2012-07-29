#ifndef IMAPELEMENT_H
#define IMAPELEMENT_H

#include "CPoint.h"
#include <vector>

//

template <typename T>
class IFrameElement
{
public:
    virtual const T& getFrameElements() const = 0;
    virtual ~IFrameElement(){}
};

#endif // IMAPELEMENT_H
