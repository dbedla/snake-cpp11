#include "../include/CColisionDetector.h"


bool CColisionDetector::operator()( IFrameElement<PointsList> &movableObj, IFrameElement<PointsList> &staticObj)
{
    const PointsList& staticElements = staticObj.getFrameElements();
    const PointsList& moveableElements = movableObj.getFrameElements();

    PointsList wholePoints;
    wholePoints.insert(wholePoints.end(), staticElements.begin(), staticElements.end());
    wholePoints.insert(wholePoints.end(), moveableElements.begin(), moveableElements.end());

    wholePoints.sort();
    wholePoints.unique();

    if(wholePoints.size() == staticElements.size() + moveableElements.size())
    {
        return false;
    }

    return true;
}
