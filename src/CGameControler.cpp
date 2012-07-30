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
    bool elemnt_colision = false;
    while(_play)
    {
        logger.Log("snake pos", snake.getFrameElements());
        boost::this_thread::sleep(boost::posix_time::milliseconds(300));
        snake.moveSnake(move);
        frame->clearFrame();
        frame->drawObjIntoFrame(snake);
        frame->drawObjIntoFrame(*wall);
        frame->drawObjIntoFrame(*eatMe);
        frame->drawFrame();
        //parseKeyMove(moveSnakeObj);

        elemnt_colision = colision_detector( *wall, snake);
        if(elemnt_colision)
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
            snakeEatElement();
        }
       // if(i%10 == 0){snake.addBodyPart();}
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

CGameControler::CGameControler(): snake(CPoint(10, 10), 6), logger("log_File.txt")
{
    std::ios::sync_with_stdio(true);
    _play = _readKey = true;
    frame = new CFrame();
    wall = new CBasicWall(frame->getWidith(), frame->getHeight());
    eatMe = new CItemToEat(frame->getWidith(), frame->getHeight());
}


void CGameControler::addSingleNonColisionElementToEat()
{
    CLogger l("eatme.txt");
    CPoint newElementToEat;// = eatMe->createRandomPoint();

    while( colision_detector(*eatMe, *wall) || eatMe->getNumberOfElementsToEat()==0 )
    {
        newElementToEat = eatMe->createRandomPoint();
        l.Log("randompoint: ", newElementToEat);
        eatMe->addElementToEat(newElementToEat);
    }
    eatMe->addElementToEat(newElementToEat);

    l.Log("point at end: ", newElementToEat);

}


void CGameControler::snakeEatElement()
{
    if( colision_detector(snake, *eatMe) )
    {
        const PointsList snakeBody = snake.getFrameElements();
        std::for_each(snakeBody.begin(), snakeBody.end(),
                      [&eatMe](const CPoint p){ eatMe->removeElementToEat(p); } );
        snake.addBodyPart();
    }
}
