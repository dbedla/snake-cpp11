#ifndef SNAKE_H
#define SNAKE_H

//#include <vector>
#include <CPoint.h>
#include <vector>
#include <def.h>
#include <IFrameElement.h>
#include <functional>
#include <algorithm>

//MIN_SNAKE_LENGTH should be at least 2
const unsigned int MIN_SNAKE_LENGTH = 3;

class CSnake: public IFrameElement<PointsList >
{
public:
    CSnake(CPoint headPosition, int startLength);
    void addBodyPart();
    virtual const PointsList& getFrameElements() const;

    void moveSnake( std::function<void(PointsList&)>& );

    const int getMinSnakeLen();
private:
    PointsList _body;
    const int minSnakeLen;
};

#endif // SNAKE_H
