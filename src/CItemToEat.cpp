#include "../include/CItemsToEat.h"


CItemToEat::CItemToEat(){}

CItemToEat::CItemToEat(const CPoint& newPoint)
{
    _itemsToEat.push_back(newPoint);
}


CItemToEat::CItemToEat(const PointsList& srcPoints)
{
    std::for_each(srcPoints.begin(), srcPoints.end(),
                  [&_itemsToEat](const CPoint& newPoint){_itemsToEat.push_back(newPoint);});
}

void CItemToEat::addElementToEat(const CPoint & newPoint)
{
    _itemsToEat.push_back(newPoint);
    removeNormalizeElementsToEat();
}

void CItemToEat::removeElementToEat(const CPoint & pointToRemove)
{
    _itemsToEat.remove(pointToRemove);
    removeNormalizeElementsToEat();
}

void CItemToEat::removeNormalizeElementsToEat()
{
    _itemsToEat.sort();
    _itemsToEat.unique();
}

const PointsList& CItemToEat::getFrameElements() const
{
    return _itemsToEat;
}
