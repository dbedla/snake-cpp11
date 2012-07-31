#include "../include/CGameControler.h"

#include "../include/CLogger.h"

void CGameControler::stopKeboardRead()
{
    boost::lock_guard<boost::mutex>  guard( _mtxReadKey);
    _readKey = false;
}

void CGameControler::RunGame()
{
    std::function<void(PointsList&)> move = std::bind(&CMoveSnake::moveObj,
                                                      &moveSnakeObj, std::placeholders::_1) ;
    std::function<void(CMoveSnake&)> th_key_handler_func =
            std::bind(&CGameControler::parseKeyMove, this, std::placeholders::_1 );
    boost::thread workerThreadKeyHandler(th_key_handler_func, boost::ref(moveSnakeObj));

    while(_play)
    {
        logger.Log("snake pos", snake->getFrameElements());
        boost::this_thread::sleep(boost::posix_time::milliseconds(_gameSpeed));
        snake->moveSnake(move);
        frame->clearFrame();
        frame->drawObjIntoFrame(*snake);
        frame->drawObjIntoFrame(*wall);
        frame->drawObjIntoFrame(*eatMe);
        frame->drawFrame();

        if(colision_detector( *wall, *snake))
        {
            std::cout<<"kolizja\nkoniec gry\n";
            break;
        }
        if(eatMe->getNumberOfElementsToEat() == 0)
        {
            addSingleNonColisionElementToEat();
        }
        else
        {
            if(snakeEatElement())
            {
                speedUP();
            }

        }
    }
    stopKeboardRead();
    workerThreadKeyHandler.join();
}

void CGameControler::parseKeyMove(CMoveSnake &DirectionKeeper)
{
    while(_readKey)
    {
    char k = keyHandler.getKeyFromKeybord();
    switch (k)
    {
        case LEFT:
        {
            DirectionKeeper.setDirection(LEFT);
            break;
        }
        case RIGHT:
        {
            DirectionKeeper.setDirection(RIGHT);
            break;
        }
        case DOWN:
        {
            DirectionKeeper.setDirection(DOWN);
            break;
        }
        case UP:
        {
            DirectionKeeper.setDirection(UP);
            break;
        }
        case 'q':
        {
            _play = false;
        }
        default:
        {
        }
    }
    }

}

CGameControler::CGameControler(): logger("log_File.txt")
{
    std::ios::sync_with_stdio(true);
    _play = _readKey = true;
    frame.reset( new CFrame());
    wall.reset( new CBasicWall(frame->getWidith(), frame->getHeight()) );
    eatMe.reset( new CItemToEat(frame->getWidith()-1, frame->getHeight()-1) );
    snake.reset(new CSnake( CPoint(frame->getWidith()/2, frame->getHeight()/2), MIN_SNAKE_LENGTH)  );
    _gameSpeed = START_SPEED;
}


void CGameControler::addSingleNonColisionElementToEat()
{
    CLogger l("eatme.txt");
    CPoint newElementToEat;

    do
    {
        newElementToEat = eatMe->createRandomPoint();
        l.Log("randompoint: ", newElementToEat);
        eatMe->addElementToEat(newElementToEat);
    }while( colision_detector(*eatMe, *wall) || eatMe->getNumberOfElementsToEat()==0 );
    l.Log("point at end: ", newElementToEat);

}

void CGameControler::speedUP()
{
    unsigned int newSpeed = _gameSpeed - SPEED_UP;
    if(newSpeed < _gameSpeed)
    {
        _gameSpeed = newSpeed;
    }
}

bool CGameControler::snakeEatElement()
{
    if( colision_detector(*snake, *eatMe) )
    {
        const PointsList snakeBody = snake->getFrameElements();
        std::for_each(snakeBody.begin(), snakeBody.end(),
                      [&eatMe](const CPoint p){ eatMe->removeElementToEat(p); } );
        snake->addBodyPart();
        return true;
    }
    return false;
}
