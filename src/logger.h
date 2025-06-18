
///////////////////////////////////////////////////////////////////////////////
//
//        Logger Class
//
//        This class handles logging anything needed.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LOGGER
#define LOGGER

#include <string>
using std::string;
#include <filesystem>
using std::filesystem::path;
#include <fstream>
using std::ofstream;
#include <ctime>

// The types of logs possible
enum LogType {
  INFO,
  ERROR,
  WARN,
};

class Logger {
  public:
    Logger();
    ~Logger();
    void log(LogType, string);

  private:
    path file;
    ofstream outFile;
    struct tm dateTime;
    void updateDateTime();
};

#endif //LOGGER 
