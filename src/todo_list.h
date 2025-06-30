
///////////////////////////////////////////////////////////////////////////////
//
//        Todo_List Class
//
//        This class handles the organization of Todo_Items
//
///////////////////////////////////////////////////////////////////////////////

#ifndef TODO_LIST
#define TODO_LIST

#include "todo_item.h"
#include <map>
using std::map;

class Todo_List {
public:
  Todo_List();
  ~Todo_List();

private:
  map<dateTime, Todo_Item *> list;
  // NOTE:
  // This way of storing the list doubles up the dateTime,
  // since Todo_Item already has a copy of dateTime.
  // Possible fix:
  //  make dateTime a pointer to Todo_Item->dateTime
};

#endif // !TODO_LIST
