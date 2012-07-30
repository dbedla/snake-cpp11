#ifndef CITEMSTOEAT_H
#define CITEMSTOEAT_H

#include "CPoint.h"
#include "IFrameElement.h"
#include <algorithm>
#include <random>

class CItemToEat:  public IFrameElement<PointsList >
{
public:
    CItemToEat();
    CItemToEat(unsigned int rangeX, unsigned int rangeY);
    CItemToEat(const CPoint&);
    CItemToEat(const PointsList&);
    virtual const PointsList& getFrameElements() const;
    void addElementToEat(const CPoint&);
    void removeElementToEat(const CPoint&);
    unsigned int getNumberOfElementsToEat();
    CPoint createRandomPoint();
private:
    std::mt19937 *_rand_enginX;
    std::mt19937 *_rand_enginY;
    std::uniform_int_distribution<unsigned int> *_randomRangeX;
    std::uniform_int_distribution<unsigned int> *_randomRangeY;
    unsigned int _rangeX;
    unsigned int _rangeY;
    PointsList _itemsToEat;
    void normalizeElementsToEat();
    void initRand();
};

#endif // CITEMSTOEAT_H
