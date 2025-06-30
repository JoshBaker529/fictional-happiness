
///////////////////////////////////////////////////////////////////////////////
//
//        Todo_Item Class
//
//        This class is a single todo list item
//        NOTE: May change to struct
//
///////////////////////////////////////////////////////////////////////////////

#ifndef TODO_ITEM
#define TODO_ITEM

#include <string>
using std::string;

struct dateTime {
  short year, month, day, hour, minute;

  bool operator<(const dateTime &r) {
    return std::tie(year, month, day, hour, minute) <
           std::tie(r.year, r.month, r.day, r.hour, r.minute);
  }
};

class Todo_Item {
public:
  Todo_Item(string name = "", string description = "",
            dateTime dateTime = {0, 0, 0, 0, 0});
  string name, description;
  dateTime dateTime;
};

#endif // !TODO_ITEM
#define TODO_ITEM
