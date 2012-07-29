#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <vector>
#include "CPoint.h"
#include <fstream>
#include <algorithm>

class CLogger
{
public:
    CLogger(const std::string file);
    ~CLogger();
    void Log(std::string s, PointsList vecOfPoints);
    void Log(std::string s, CPoint p);
    void Log(std::string s);

private:
    std::ofstream logFile;
};

#endif // LOGGER_H
