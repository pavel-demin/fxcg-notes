#include <stdlib.h>
#include <string.h>

#include <fxcg/defs.h>
#include <fxcg/print.h>
#include <fxcg/syscalls.h>

#include <dialogs.h>

#include "sprites.h"

struct piece
{
  int head;
  int step;
  int size;
};

struct state
{
  int active;
  int size;
  int map[26];
  struct piece list[18];
};

struct moves
{
  int size;
  char data[1024];
};

struct data
{
  int size;
  int curr;
  char buffer[8192];
};

static color_t *vram;

static struct state state;

static struct moves moves;

static struct data data;

static const char example[] =
  "oooooEooooDEooAADEoooCoooooCoooooCBB"
  "oooxoooooEoooAAEooooDCCCooDoooooDooo"
  "ooooxoooooFooAAoFoxoEDDoooEoooooEooo"
  "ooCoooooCoooAACooooooooDoooooDBBBooD"
  "ooDooxooDoooAADooooooooECCCooEoooooo"
  "ooxooxooEoooAAEooooooooFDDDooFoooooo"
  "ooDoooooDoooAADooooooooEoBBooECCCooE"
  "ooEooxooEoooAAEooooooooFCCCooFoDDooo"
  "ooxxoGooEooGooEAAGoooFoooooFDDoooooo"
  "ooDoooooDoooAADooEoooooEBBBooECCCooo"
  "ooxoooooECCCAAEooFoooooFDDDooFoooooo"
  "BBBooGCCCooGAAFoooooFoooooxooxoooooo"
  "oooDoooooDooAAoDoEoCoooEoCBBoEoooooo"
  "oooxoooooEooAAoEoFoDoooFoDCCoFoooooo"
  "oooxoxoooFooAAoFoooEoooGoEDDoGoooooo"
  "oooDoooooDEoAAoDEFoCoooFoCBBoFoooooo"
  "oooooxooEoooAAEoooooECCCDDDooFoooooF"
  "ooxooxooooooAAFoooooFDDDEEEooGoooooG"
  "oooEoooooEooAAoEoFoooooFoDBBoFoDCCoo"
  "oooxoooooFCCAAoFoGoEoooGoEDDoGoooooo"
  "oooxxooooFooAAoFoHoEooGHoEDDGHoooooo"
  "oooooooooEoFAAoEoFBBoEoFoDoooooDCCoo"
  "ooExooooEFooAAEFoGoDoooGoDCCoGoooooo"
  "ooFxoxooFGooAAFGoooEoooHoEDDoHoooooo"
  "oooooooooEFGAAoEFGBBoEoGoDoooooDCCoo"
  "oooooxoooFooAAoFoooEoFCCoEDDoGoooooG"
  "oooxoxooooooAAoGoooFoGDDoFEEoHoooooH"
  "ooDoooooDooFooDAAFBBBEoFoooECCoooooo"
  "ooooxoooFoooAAFoooEoFCCCEDDoGoooooGo"
  "oooxoooooooxAAoGoooFoGDDoFEEoHoooooH";

void decode(const char *p)
{
  char code;
  int i, j, k, l;
  state.active = 0;
  state.size = 0;
  moves.size = 0;
  for(i = 0; i < 26; ++i)
  {
    state.map[i] = -1;
  }
  for(i = 0; i < 36; ++i)
  {
    code = p[i];
    if(code == 'o' || code == '.') continue;
    if(code == 'x')
    {
      state.list[state.size].head = i;
      state.list[state.size].step = 1;
      state.list[state.size].size = 1;
      ++state.size;
    }
    if(code >= 'A' && code <= 'Z')
    {
      j = code - 'A';
      if(state.map[j] < 0)
      {
        state.map[j] = state.size;
        state.list[state.size].head = i;
        state.list[state.size].step = 0;
        state.list[state.size].size = 1;
        state.active = state.size;
        ++state.size;
      }
      else
      {
        k = state.map[j];
        if(state.list[k].size == 1)
        {
          state.list[k].step = i - state.list[k].head;
        }
        else if(state.list[k].size == 2 && i - state.list[k].head != state.list[k].step * 2)
        {
          state.list[state.size].step = 0;
        }
        ++state.list[k].size;
      }
    }
  }
  l = 1;
  for(i = 0; i < state.size; ++i)
  {
    if(state.list[i].step == 0)
    {
      state.size = 0;
      break;
    }
    if(state.list[i].size != 1 && i != state.map[0])
    {
      state.map[l] = i;
      ++l;
    }
  }
  for(i = l; i < 26; ++i)
  {
    state.map[i] = -1;
  }
}

int occupied(int c)
{
  int i, j;
  struct piece *p;
  for(i = 0; i < state.size; ++i)
  {
    p = state.list + i;
    for(j = 0; j < p->size; ++j)
    {
      if(p->head + j * p->step == c) return 1;
    }
  }
  return 0;
}

void move(int m)
{
  int c, n;
  struct piece *p;
  if(moves.size >= sizeof(moves.data)) return;
  p = state.list + state.active;
  if(m > 0)
  {
    c = p->head + p->size * p->step;
    n = p->head + p->step;
  }
  else
  {
    c = p->head - p->step;
    n = c;
  }
  if(c < 0 || c > 35) return;
  if(p->step == 1)
  {
    if(c / 6 != p->head / 6) return;
  }
  else
  {
    if(c % 6 != p->head % 6) return;
  }
  if(occupied(c)) return;
  p->head = n;
  moves.data[moves.size] = m * (state.active + 1);
  ++moves.size;
}

void undo()
{
  int m;
  char code;
  struct piece *p;
  if(moves.size <= 0) return;
  --moves.size;
  code = moves.data[moves.size];
  p = state.list + abs(code) - 1;
  m = code < 0 ? 1 : -1;
  p->head += m * p->step;
}

void draw(int x, int y, int w, int h, const color_t *s)
{
  int i;
  for(i = 0; i < h; ++i)
  {
    memcpy(vram + LCD_WIDTH_PX * (y + i) + x, s + w * i, w * 2);
  }
}

void board()
{
  int i, j;
  for(i = 0; i < 175; ++i)
  {
    if(i % 29)
    {
      for(j = 0; j < 175; j += 29)
      {
        vram[LCD_WIDTH_PX * (24 + i) + j] = COLOR_BLACK;
      }
    }
    else
    {
      memset(vram + LCD_WIDTH_PX * (24 + i), 0, 175 * 2);
    }
  }
  draw(175, 24 + 67, 6, 12, arrow);
}

void arrows(int x1, int y1, int x2, int y2, char c1, char c2, color_t color)
{
  char arrow[2] = " ";
  arrow[0] = c1;
  print(x1, y1, COLOR_BLACK, color, arrow);
  arrow[0] = c2;
  print(x2, y2, COLOR_BLACK, color, arrow);
}

void game()
{
  int i, x, y;
  struct piece *p;
  char label[2] = "B";
  for(i = 0; i < state.size; ++i)
  {
    p = state.list + i;
    x = (p->head % 6) * 29;
    y = (p->head / 6) * 29 + 24;
    if(p->size == 1)
    {
      draw(x + 1, y + 1, 28, 28, wall);
    }
    else if(p->size == 2 && i == state.map[0])
    {
      draw(x + 3, y + 3, 53, 24, car1);
      print(x + 26, y + 8, COLOR_BLACK, 0xf800, "A");
      if(i == state.active) arrows(x + 10, y + 8, x + 42, y + 8, 17, 16, 0xf800);
    }
    else if(p->size == 2 && p->step == 1)
    {
      draw(x + 3, y + 3, 53, 24, car2);
      print(x + 26, y + 8, COLOR_BLACK, 0x05ff, label);
      if(i == state.active) arrows(x + 10, y + 8, x + 42, y + 8, 17, 16, 0x05ff);
    }
    else if(p->size == 2)
    {
      draw(x + 3, y + 3, 24, 53, car3);
      print(x + 12, y + 22, COLOR_BLACK, 0x05ff, label);
      if(i == state.active) arrows(x + 12, y + 6, x + 12, y + 38, 30, 31, 0x05ff);
    }
    else if(p->size == 3 && p->step == 1)
    {
      draw(x + 3, y + 3, 82, 24, car4);
      print(x + 40, y + 8, COLOR_BLACK, 0x05ff, label);
      if(i == state.active) arrows(x + 24, y + 8, x + 56, y + 8, 17, 16, 0x05ff);
    }
    else if(p->size == 3)
    {
      draw(x + 3, y + 3, 24, 82, car5);
      print(x + 12, y + 36, COLOR_BLACK, 0x05ff, label);
      if(i == state.active) arrows(x + 12, y + 20, x + 12, y + 52, 30, 31, 0x05ff);
    }
    if(p->size != 1 && i != state.map[0]) label[0] += 1;
  }
}

void convert(int v, char *p)
{
  int i;
  for(i = 0; i < 3; ++i) p[i] = ' ';
  p[3] = '0';
  p[4] = 0;
  p += 3;
  while(v > 0)
  {
    *p-- = '0' + (v % 10);
    v /= 10;
  }
}

void text()
{
  char buffer[5];
  print(232, 56, COLOR_BLACK, COLOR_WHITE, "number:");
  convert(data.curr / 36 + 1, buffer);
  print(296, 56, COLOR_BLACK, COLOR_WHITE, buffer);
  print(240, 88, COLOR_BLACK, COLOR_WHITE, "moves:");
  convert(moves.size, buffer);
  print(296, 88, COLOR_BLACK, COLOR_WHITE, buffer);
  if(state.list[state.map[0]].head == 16)
  {
    print(240, 120, COLOR_BLACK, COLOR_WHITE, "state:   solved");
  }
  else
  {
    print(240, 120, COLOR_BLACK, COLOR_WHITE, "state: unsolved");
  }
}

void menu()
{
  print(  0, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, " Undo   ");
  print( 64, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, " Reset  ");
  print(128, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, "  Load  ");
  print(192, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, " Random ");
  print(256, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, "   Prev ");
  print(320, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, "   Next ");
}

void timeout()
{
  memset(vram + LCD_WIDTH_PX * 24, 255, LCD_WIDTH_PX * 176 * 2);
  board();
  game();
  text();
  menu();
  Bdisp_PutDisp_DD();
}

void load(int fd)
{
  int i;
  char code;
  size_t size;

  size = Bfile_GetFileSize_OS(fd);
  if(size > sizeof(data.buffer)) size = sizeof(data.buffer);
  size = Bfile_ReadFile_OS(fd, data.buffer, size, 0);
  Bfile_CloseFile_OS(fd);

  data.size = 0;
  data.curr = 0;
  for(i = 0; i < size; ++i)
  {
    code = data.buffer[i];
    if(code == 'o' || code == '.' || code == 'x' || (code >= 'A' && code <= 'Z'))
    {
      data.buffer[data.size] = code;
      ++data.size;
    }
  }
  if(data.size >= 36) decode(data.buffer);
}

int main()
{
  int i, fd, key, timer;

  Bdisp_EnableColor(1);
  vram = GetVRAMAddress();

  Bkey_SetAllFlags(0x80);

  timer = Timer_Install(0, timeout, 100);
  Timer_Start(timer);

  data.size = sizeof(example);
  data.curr = 0;
  memcpy(data.buffer, example, sizeof(example));

  decode(data.buffer);

  while(1)
  {
    SetSetupSetting(0x14, 0x84);
    GetKey(&key);
    if(key >= KEY_CHAR_A && key <= KEY_CHAR_Z)
    {
      i = state.map[key - KEY_CHAR_A];
      if(i >= 0) state.active = i;
      continue;
    }
    switch(key)
    {
    case KEY_CTRL_F1:
      undo();
      break;
    case KEY_CTRL_F2:
      decode(data.buffer + data.curr);
      break;
    case KEY_CTRL_F3:
      Timer_Stop(timer);
      Timer_Deinstall(timer);
      memset(vram, 255, LCD_WIDTH_PX * LCD_HEIGHT_PX * 2);
      fd = open_file_dialog("", "*.txt");
      if(fd >= 0) load(fd);
      timer = Timer_Install(0, timeout, 100);
      Timer_Start(timer);
      break;
    case KEY_CTRL_F4:
      i = data.size / 36;
      i = rand() % i;
      data.curr = i * 36;
      decode(data.buffer + data.curr);
      break;
    case KEY_CTRL_F5:
      if(data.curr - 36 >= 0)
      {
        data.curr -= 36;
        decode(data.buffer + data.curr);
      }
      break;
    case KEY_CTRL_F6:
      if(data.curr + 71 < data.size)
      {
        data.curr += 36;
        decode(data.buffer + data.curr);
      }
      break;
    case KEY_CTRL_UP:
      if(state.list[state.active].step != 1) move(-1);
      break;
    case KEY_CTRL_DOWN:
      if(state.list[state.active].step != 1) move(1);
      break;
    case KEY_CTRL_LEFT:
      if(state.list[state.active].step == 1) move(-1);
      break;
    case KEY_CTRL_RIGHT:
      if(state.list[state.active].step == 1) move(1);
      break;
    }
  }

  return 0;
}
