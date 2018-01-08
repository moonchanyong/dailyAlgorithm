#include <string.h>

using namespace std;

namespace mcy {

  static void removeElementAtArry(int *arr, int index, int size)
  {
    // #include string.h
    memmove(arr + index, arr + index + 1, (size - index - 1) * sizeof(int));

  }



}
