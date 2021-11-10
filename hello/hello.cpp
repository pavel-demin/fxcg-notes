#include <string>
#include <sstream>
#include <vector>

#include <fxcg/defs.h>
#include <fxcg/print.h>
#include <fxcg/syscalls.h>

using namespace ustl;

int main()
{
  int i, key;
  string hello = "  ++ Hello World! ++";
  ostringstream stream;
  vector<char> digit, small, capital;

  stream << hello;

  PrintXY(2, 2, stream.str().c_str(), TEXT_MODE_NORMAL, TEXT_COLOR_RED);

  for(i = 0; i < 32; ++i)
  {
    digit.push_back(32 + i);
    capital.push_back(64 + i);
    small.push_back(96 + i);
  }
  digit.push_back(0);
  small.push_back(0);
  capital.push_back(0);

  print(0, 88, COLOR_BLACK, COLOR_WHITE, digit.data());
  print(0, 104, COLOR_BLACK, COLOR_WHITE, capital.data());
  print(0, 120, COLOR_BLACK, COLOR_WHITE, small.data());

  Bdisp_MMPrint(0, 136, digit.data(), 0, 0xffffffff, 0, 0, COLOR_BLACK, COLOR_WHITE, 1, 0);
  Bdisp_MMPrint(0, 156, capital.data(), 0, 0xffffffff, 0, 0, COLOR_BLACK, COLOR_WHITE, 1, 0);
  Bdisp_MMPrint(0, 176, small.data(), 0, 0xffffffff, 0, 0, COLOR_BLACK, COLOR_WHITE, 1, 0);

  print(320, 200, COLOR_BLACK, COLOR_WHITE, "  Assert");

  while(1)
  {
    GetKey(&key);
    switch(key)
    {
    case KEY_CTRL_F6:
      assert(0);
      break;
    }
  }

  return 0;
}
