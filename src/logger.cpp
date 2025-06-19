#include "logger.h"
#include <ctime>
#include <iostream>
using std::endl;
#include <string>
using std::string, std::to_string;
///////////////////////////////////////////////////////////////////////////////
//
//        Logger()
//
//        Default Constructor
//
///////////////////////////////////////////////////////////////////////////////

Logger::Logger() {
  updateDateTime();
  // TODO: Need to make this look in local dir logs/
  string file_s = "logs-" + to_string(dateTime.tm_year) + "-" +
                  to_string(dateTime.tm_mon) + "-" +
                  to_string(dateTime.tm_mday) + ".log";
  file = path(file_s);
  outFile.open(file, std::ios::app);

  outFile << "Logging started.";
}

///////////////////////////////////////////////////////////////////////////////
//
//        ~Logger()
//
//        Deconstructor
//
///////////////////////////////////////////////////////////////////////////////

Logger::~Logger() { outFile.close(); }

///////////////////////////////////////////////////////////////////////////////
//
//        log
//
//        Writes a log message to the log file
//
//        INPUT:
//        LogType - Type of message
//        string  - Message
//
///////////////////////////////////////////////////////////////////////////////

void Logger::log(LogType type, string message) {
  updateDateTime();
  outFile << "[" << to_string(dateTime.tm_hour) << ":"
          << to_string(dateTime.tm_min) << ":" << to_string(dateTime.tm_sec)
          << "] [";

  switch (type) {
  case WARN:
    outFile << "WARN] ";
    break;
  case ERROR:
    outFile << "ERROR] ";
    break;
  case INFO:
    outFile << "INFO] ";
    break;
  }

  outFile << message << endl;
}

///////////////////////////////////////////////////////////////////////////////
//
//        updateDateTime()
//
//        Updates Logger.dateTime to be the current date and time
//
///////////////////////////////////////////////////////////////////////////////

void Logger::updateDateTime() {
  time_t now = time(0);
  dateTime = *localtime(&now);
  dateTime.tm_mon += 1;     // tm_mon indexed at 0
  dateTime.tm_year += 1900; // tm_year starts count at 1900
}
