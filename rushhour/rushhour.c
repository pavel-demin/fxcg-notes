#include <stdlib.h>
#include <stdint.h>
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

struct data
{
  int size;
  int curr;
  char buffer[8192];
};

static color_t *vram;

static int active, size;

static struct piece list[18];

static int map[26];

static struct data data;

static const char exemple[] = "BBoKMxDDDKMoIAALooIoJLEEooJFFNoGGoxN";

void decode(const char *p)
{
  char code;
  int i, j, k, l;
  active = 0;
  size = 0;
  for(i = 0; i < 26; ++i)
  {
    map[i] = -1;
  }
  for(i = 0; i < 36; ++i)
  {
    code = p[i];
    if(code == 'o' || code == '.') continue;
    if(code == 'x')
    {
      list[size].head = i;
      list[size].step = 1;
      list[size].size = 1;
      ++size;
    }
    if(code >= 'A' && code <= 'Z')
    {
      j = code - 'A';
      if(map[j] < 0)
      {
        map[j] = size;
        list[size].head = i;
        list[size].step = 0;
        list[size].size = 1;
        active = size;
        ++size;
      }
      else
      {
        k = map[j];
        if(list[k].size == 1)
        {
          list[k].step = i - list[k].head;
        }
        else if(list[k].size == 2 && i - list[k].head != list[k].step * 2)
        {
          list[size].step = 0;
        }
        list[k].size += 1;
      }
    }
  }
  l = 1;
  for(i = 0; i < size; ++i)
  {
    if(list[i].step == 0)
    {
      size = 0;
      break;
    }
    if(list[i].size != 1 && i != map[0])
    {
      map[l] = i;
      ++l;
    }
  }
  for(i = l; i < 26; ++i)
  {
    map[i] = -1;
  }
}

int occupied(int c)
{
  int i, j;
  struct piece *p;
  for(i = 0; i < size; ++i)
  {
    p = list + i;
    for(j = 0; j < p->size; ++j)
    {
      if(p->head + j * p->step == c) return 1;
    }
  }
  return 0;
}

void move(int m)
{
  int j, c, d, n;
  struct piece *p = list + active;
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
}

void draw(int x, int y, int w, int h, const color_t *s)
{
  int i;
  for(i = 0; i < h; ++i)
  {
    memcpy(vram + LCD_WIDTH_PX * (y + i) + x, s + w * i, w * 2);
  }
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
  for(i = 0; i < size; ++i)
  {
    p = list + i;
    x = (p->head % 6) * 29;
    y = (p->head / 6) * 29 + 24;
    if(p->size == 1)
    {
      draw(x + 1, y + 1, 28, 28, wall);
    }
    else if(p->size == 2 && i == map[0])
    {
      draw(x + 3, y + 3, 53, 24, car1);
      print(x + 26, y + 8, COLOR_BLACK, 0xf800, "A");
      if(i == active) arrows(x + 10, y + 8, x + 42, y + 8, 17, 16, 0xf800);
    }
    else if(p->size == 2 && p->step == 1)
    {
      draw(x + 3, y + 3, 53, 24, car2);
      print(x + 26, y + 8, COLOR_BLACK, 0x05ff, label);
      if(i == active) arrows(x + 10, y + 8, x + 42, y + 8, 17, 16, 0x05ff);
    }
    else if(p->size == 2)
    {
      draw(x + 3, y + 3, 24, 53, car3);
      print(x + 12, y + 22, COLOR_BLACK, 0x05ff, label);
      if(i == active) arrows(x + 12, y + 6, x + 12, y + 38, 30, 31, 0x05ff);
    }
    else if(p->size == 3 && p->step == 1)
    {
      draw(x + 3, y + 3, 82, 24, car4);
      print(x + 39, y + 8, COLOR_BLACK, 0x05ff, label);
      if(i == active) arrows(x + 23, y + 8, x + 55, y + 8, 17, 16, 0x05ff);
    }
    else if(p->size == 3)
    {
      draw(x + 3, y + 3, 24, 82, car5);
      print(x + 12, y + 35, COLOR_BLACK, 0x05ff, label);
      if(i == active) arrows(x + 12, y + 19, x + 12, y + 51, 30, 31, 0x05ff);
    }
    if(p->size != 1 && i != map[0]) label[0] += 1;
  }
}

void menu()
{
  print(0, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, "  Undo");
  print(64, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, " Reset");
  print(128, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, "  Load");
  print(192, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, " Random");
  print(256, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, "  Prev");
  print(320, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, "  Next");
}

void timeout()
{
  memset(vram + LCD_WIDTH_PX * 24, 255, LCD_WIDTH_PX * 176 * 2);
  draw(0, 24, 181, 175, board);
  game();
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

  data.size = 0;
  data.curr = 0;

  decode(exemple);

  while(1)
  {
    SetSetupSetting(0x14, 0x84);
    GetKey(&key);
    if(key >= KEY_CHAR_A && key <= KEY_CHAR_Z)
    {
      i = map[key - KEY_CHAR_A];
      if(i >= 0) active = i;
      continue;
    }
    switch(key)
    {
    case KEY_CTRL_F1:
      break;
    case KEY_CTRL_F2:
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
      break;
    case KEY_CTRL_F5:
      if(data.curr - 36 >= 0)
      {
        data.curr -= 36;
        decode(data.buffer + data.curr);
      }
      break;
    case KEY_CTRL_F6:
      if(data.curr + 36 < data.size)
      {
        data.curr += 36;
        decode(data.buffer + data.curr);
      }
      break;
    case KEY_CTRL_UP:
      if(list[active].step != 1) move(-1);
      break;
    case KEY_CTRL_DOWN:
      if(list[active].step != 1) move(1);
      break;
    case KEY_CTRL_LEFT:
      if(list[active].step == 1) move(-1);
      break;
    case KEY_CTRL_RIGHT:
      if(list[active].step == 1) move(1);
      break;
    }
  }

  return 0;
}
