#include "../include/CItemsToEat.h"

CItemToEat::CItemToEat():_rangeX(0), _rangeY(0){initRand();}

CItemToEat::CItemToEat(unsigned int rangeX, unsigned int rangeY): _rangeX(rangeX), _rangeY(rangeY)
{
    initRand();
}

CItemToEat::CItemToEat(const CPoint& newPoint)
{
    _itemsToEat.push_back(newPoint);
    initRand();
}


CItemToEat::CItemToEat(const PointsList& srcPoints)
{
    std::for_each(srcPoints.begin(), srcPoints.end(),
                  [&_itemsToEat](const CPoint& newPoint){_itemsToEat.push_back(newPoint);});
}

void CItemToEat::addElementToEat(const CPoint & newPoint)
{
    _itemsToEat.clear();
    _itemsToEat.push_back(newPoint);
    //normalizeElementsToEat();
}

void CItemToEat::removeElementToEat(const CPoint & pointToRemove)
{
    _itemsToEat.remove(pointToRemove);
    //normalizeElementsToEat();
}

void CItemToEat::normalizeElementsToEat()
{
    _itemsToEat.sort();
    _itemsToEat.unique();
}

void CItemToEat::initRand()
{
    std::random_device rdX;
    std::random_device rdY;
    _rand_enginX.reset( new std::mt19937(rdX()) );
    _rand_enginY.reset( new std::mt19937(rdY()) );
    _randomRangeX.reset( new std::uniform_int_distribution<unsigned int> (0,_rangeX) );
    _randomRangeY.reset( new std::uniform_int_distribution<unsigned int> (0,_rangeY) );
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
    unsigned int rX = _randomRangeX->operator ()(*_rand_enginX);
    unsigned int rY = _randomRangeY->operator ()(*_rand_enginY);
    return CPoint(rX, rY);
}
