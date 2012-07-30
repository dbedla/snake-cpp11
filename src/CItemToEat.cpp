#include "../include/CItemsToEat.h"

CItemToEat::CItemToEat(){}

CItemToEat::CItemToEat(unsigned int rangeX, unsigned int rangeY): _rangeX(rangeX), _rangeY(rangeY)
{
}

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
    normalizeElementsToEat();
}

void CItemToEat::removeElementToEat(const CPoint & pointToRemove)
{
    _itemsToEat.remove(pointToRemove);
    normalizeElementsToEat();
}

void CItemToEat::normalizeElementsToEat()
{
    _itemsToEat.sort();
    _itemsToEat.unique();
}

const PointsList& CItemToEat::getFrameElements() const
{
    return _itemsToEat;
}

unsigned int CItemToEat::getNumberOfElementsToEat()
{
    return _itemsToEat.size();
}

CPoint CItemToEat::createRandomPoint()
{
    std::mt19937 rand_engin(static_cast<unsigned long>(time(0)));
    std::uniform_int_distribution<unsigned int> randomRangeX(0,_rangeX);
    std::uniform_int_distribution<unsigned int> randomRangeY(0,_rangeY);
    auto randomGenX = std::bind(randomRangeX, rand_engin);
    auto randomGenY = std::bind(randomRangeY, rand_engin);

    unsigned int newX = randomGenX();
    unsigned int newY = randomGenY();

    return CPoint(newX, newY);
}
