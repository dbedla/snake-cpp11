#include<iostream>
#include <vector>



#include "../include/CPoint.h"
#include "../include/key_handler.h"
#include "../include/frame.h"
#include "../include/def.h"

#include "../include/snake.h"
#include "../include/CMoveSnake.h"
#include "../include/CLogger.h"
#include "../include/CBasicWall.h"
#include "../include/CColisionDetector.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread_time.hpp>
#include <boost/thread.hpp>

/*
void testerOfsnakemove()
{
    CPoint headPos(10, 10);
    CSnake snake(headPos, 4);
    CMoveSnake moveSnakeObj;

    std::function<void(PointsList&)> move = std::bind(&CMoveSnake::moveObj, &moveSnakeObj, std::placeholders::_1) ;

    //snake.moveSnake( move );
    //moveSnakeObj.setDirection(LEFT);
    //snake.moveSnake( move );
    //moveSnakeObj.setDirection(LEFT);
    //snake.moveSnake( move );
    moveSnakeObj.setDirection(UP);
    snake.moveSnake( move );

    moveSnakeObj.setDirection(RIGHT);
    snake.moveSnake( move );

    moveSnakeObj.setDirection(DOWN);
    snake.moveSnake( move );
    //moveSnakeObj.setDirection(DOWN);
    //snake.moveSnake( move );
    //moveSnakeObj.setDirection(RIGHT);
    //snake.moveSnake( move );
}*/

void tester_colision_detector(void)
{
    CBasicWall wall(20, 20);
    CPoint headPosition(4,3);
    CSnake snake(headPosition, 3);
    CColisionDetector colision_detector;
    CMoveSnake mveObj;
    std::function<void(PointsList&)> move = std::bind(&CMoveSnake::moveObj, &mveObj, std::placeholders::_1);

    colision_detector(snake, wall);
    snake.moveSnake(move);

    colision_detector(snake, wall);
    snake.moveSnake(move);

    colision_detector(snake, wall);
    snake.moveSnake(move);

    colision_detector(snake, wall);
    snake.moveSnake(move);

}

class CGameControler
{
public:
    CGameControler();
    void RunGame();

private:
    //CPoint obj;
    CFrame *frame;
    CSnake snake;
    CKeyHandler keyHandler;
    CMoveSnake moveSnakeObj;
    CLogger logger;
    CBasicWall *wall;
    CColisionDetector colision_detector;
    bool _readKey;
    boost::mutex _mtxReadKey;
    void parseKeyMove(CMoveSnake &DirectionKeeper);
    void stopKeboardRead();
    bool _play;
};

void CGameControler::stopKeboardRead()
{
    boost::lock_guard<boost::mutex>  guard( _mtxReadKey);
    _readKey = false;
}

void CGameControler::RunGame()
{
    std::function<void(PointsList&)> move = std::bind(&CMoveSnake::moveObj, &moveSnakeObj, std::placeholders::_1) ;
    std::function<void(CMoveSnake&)> th_key_handler_func =
            std::bind(&CGameControler::parseKeyMove, this, std::placeholders::_1 );
    boost::thread workerThreadKeyHandler(th_key_handler_func, boost::ref(moveSnakeObj));
    bool elemnt_colision = false;
    while(_play)
    {
        logger.Log("snake pos", snake.getFrameElements());
        boost::this_thread::sleep(boost::posix_time::milliseconds(500));
        snake.moveSnake(move);
        frame->clearFrame();
        frame->drawObjIntoFrame(snake);
        frame->drawObjIntoFrame(*wall);
        frame->drawFrame();
        //parseKeyMove(moveSnakeObj);

        elemnt_colision = colision_detector( *wall, snake);
        if(elemnt_colision)
        {
            std::cout<<"kolizja\nkoniec gry\n";
            break;
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
}


int main(void)
{
    /*
    CPoint p(5,5);
    CFrame f;
    f.SetPoint(p);
    f.drawFrame();

    CKeyHandler keyHandler;
    keyHandler();
    */

    CGameControler Game;
    Game.RunGame();

    //testerOfsnakemove();

    //tester_colision_detector();

    //std::cout<<"2\n";
    return 0;
}
