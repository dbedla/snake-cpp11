#include "../include/CLogger.h"

CLogger* CLogger::_instance = NULL;
boost::mutex CLogger::_write_file_mutex;

CLogger& CLogger::getInstance()
{
    boost::lock_guard<boost::mutex>  guard( CLogger::_write_file_mutex );
    if(_instance == NULL)
    {
        _instance = new CLogger();
    }
    return *_instance;
}

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
    boost::lock_guard<boost::mutex>  guard( CLogger::_write_file_mutex );
    logFile << s << std::endl;
}

void CLogger::Log(std::string s, CPoint p)
{
    boost::lock_guard<boost::mutex>  guard( CLogger::_write_file_mutex );
    logFile << s << " : (" << p._x << ", " << p._y <<")\n";
}

void CLogger::Log(std::string s, PointsList vecOfPoints)
{
    boost::lock_guard<boost::mutex>  guard( CLogger::_write_file_mutex );
    logFile << s <<" : ";
    std::for_each(vecOfPoints.begin(), vecOfPoints.end(),
                  [&](CPoint &p){logFile << " (" << p._x << "," << p._y <<") ";});
    logFile << std::endl;
}
