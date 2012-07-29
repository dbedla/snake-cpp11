#include "../include/CLogger.h"

CLogger::CLogger(const std::string file)
{
    logFile.open(file);

}

CLogger::~CLogger()
{
    logFile.close();
}

void CLogger::Log(std::string s)
{
    logFile << s << std::endl;
}

void CLogger::Log(std::string s, CPoint p)
{
    logFile << s << " : (" << p._x << ", " << p._y <<")\n";
}

void CLogger::Log(std::string s, PointsList vecOfPoints)
{
    logFile << s <<" : ";
    std::for_each(vecOfPoints.begin(), vecOfPoints.end(), [&logFile](CPoint &p){logFile << " (" << p._x << "," << p._y <<") ";});
    logFile << std::endl;
}
