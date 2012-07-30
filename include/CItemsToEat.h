#ifndef CITEMSTOEAT_H
#define CITEMSTOEAT_H

#include "CPoint.h"
#include "IFrameElement.h"
#include <algorithm>

class CItemToEat:  public IFrameElement<PointsList >
{
public:
    CItemToEat();
    CItemToEat(const CPoint&);
    CItemToEat(const PointsList&);
    virtual const PointsList& getFrameElements() const;
    void addElementToEat(const CPoint&);
    void removeElementToEat(const CPoint&);
private:
    //const unsigned int _numberOfItems;
    PointsList _itemsToEat;
    void removeNormalizeElementsToEat();
};

#endif // CITEMSTOEAT_H
