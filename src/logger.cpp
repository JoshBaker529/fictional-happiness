#include "logger.h"
#include <ctime>
#include <iostream>
//using std::cout;
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
  // NOTE: tm_year starts from 1900
  // NOTE: tm_mon is 0 indexed
  string file_s = "logs-" + to_string(dateTime.tm_year + 1900) \
                 + "-" + to_string(dateTime.tm_mon + 1) \
                 + "-" + to_string(dateTime.tm_mday) + ".log";
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

Logger::~Logger() {
  outFile.close();
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
}
