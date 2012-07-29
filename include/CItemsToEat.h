#ifndef CITEMSTOEAT_H
#define CITEMSTOEAT_H

#include "CPoint.h"
#include "IFrameElement.h"

class CItemToEat:  public IFrameElement<PointsList >
{
public:
    CItemToEat();
    virtual const PointsList& getFrameElements() const;

private:
    //const unsigned int _numberOfItems;
    PointsList _itemsToEat;

};

#endif // CITEMSTOEAT_H
