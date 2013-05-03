#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <vector>
#include <CPoint.h>
#include <fstream>
#include <algorithm>
#include <boost/thread.hpp>

class CLogger
{
public:
    static CLogger& getInstance();
    ~CLogger();
    void Log(std::string s, PointsList vecOfPoints);
    void Log(std::string s, CPoint p);
    void Log(std::string s);

private:
    static boost::mutex _write_file_mutex;
    std::ofstream logFile;
    CLogger(const std::string file = "snake_log.txt");
    static CLogger *_instance;
};

#endif // LOGGER_H
