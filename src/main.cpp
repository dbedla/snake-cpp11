#include<iostream>
#include <vector>

#include "../include/CGameControler.h"

#include "../include/CPoint.h"
#include "../include/key_handler.h"
#include "../include/frame.h"
#include "../include/def.h"

#include "../include/snake.h"
#include "../include/CMoveSnake.h"
#include "../include/CLogger.h"
#include "../include/CBasicWall.h"
#include "../include/CColisionDetector.h"
#include "../include/CItemsToEat.h"

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

void test_random_in_eat_element_class()
{
    CItemToEat eat(20, 30);

    CPoint p;

    for(int i=0; i< 10; i++)
    {
        p =  eat.createRandomPoint();
        boost::this_thread::sleep(boost::posix_time::milliseconds(100*i));
        std::cout<<"(" << p._x << "," << p._y << ")" <<std::endl;
    }

}

void test_eat_element_function()
{
    CItemToEat eat(20, 30);

    eat.addElementToEat(CPoint(1,1));

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

    CGameControler &Game = CGameControler::getInstance();
    Game.RunGame();

    //test_eat_element_function();
    //test_random_in_eat_element_class();
    //testerOfsnakemove();
    //tester_colision_detector();

    //std::cout<<"2\n";
    return 0;
}

