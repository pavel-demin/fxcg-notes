#include <stdlib.h>
#include <string.h>

#include <fxcg/defs.h>
#include <fxcg/print.h>
#include <fxcg/syscalls.h>

#include <dialogs.h>

#define COLS 64
#define ROWS 33

int generation, running, wire, electron, x, y;

color_t *vram;

static char world[2][COLS * ROWS] = {0};
static char buffer[4096] = {0};

static const char example[] =
{
  "        ..            \n"
  " ....tH.. ......      \n"
  ".       ..      .     \n"
  ".               .     \n"
  ".              ...... \n"
  ".               .    .\n"
  ".               .    .\n"
  " ...............     .\n"
  "                     .\n"
  " ...                 .\n"
  " ...                 .\n"
  " .................... \n"
  " ..                   \n"
};

void box(int x, int y, int w, int h, int color)
{
  int i, j;
  for(i = 0; i < w; ++i)
  {
    for(j = 0; j < h; ++j)
    {
      vram[(y + j) * LCD_WIDTH_PX + x + i] = color;
    }
  }
}

void cross(int x, int y, int color)
{
  int i;
  for(i = 0; i < 5; ++i)
  {
    vram[(y + 2) * LCD_WIDTH_PX + x + i] = color;
    vram[(y + i) * LCD_WIDTH_PX + x + 2] = color;
  }
}

void transition(const char *in, char *out, int w, int h)
{
  int i, j, k, l;
  int color, counter, index;

  for(i = 0; i < w; ++i)
  {
    for(j = 0; j < h; ++j)
    {
      index = j * w + i;
      if(i == x && j == y && wire)
      {
        wire = 0;
        switch(in[index])
        {
        case 't':
          out[index] = ' ';
          color = COLOR_BLACK;
          break;
        case 'H':
          out[index] = ' ';
          color = COLOR_BLACK;
          break;
        case '.':
          out[index] = ' ';
          color = COLOR_BLACK;
          break;
        default:
          out[index] = '.';
          color = COLOR_BLUE;
          break;
        }
      }
      else if(i == x && j == y && electron)
      {
        electron = 0;
        switch(in[index])
        {
        case 'H':
          out[index] = '.';
          color = COLOR_BLUE;
          break;
        default:
          out[index] = 'H';
          color = COLOR_RED;
          break;
        }
      }
      else if(running)
      {
        switch(in[index])
        {
        case 't':
          out[index] = '.';
          color = COLOR_BLUE;
          break;
        case 'H':
          out[index] = 't';
          color = COLOR_YELLOW;
          break;
        case '.':
          counter = 0;
          for(k = i - 1; k < i + 2; ++k)
          {
            if(k < 0 || k >= w) continue;
            for(l = j - 1; l < j + 2; ++l)
            {
              if(l < 0 || l >= h) continue;
              counter += (in[l * w + k] == 'H');
            }
          }
          if(counter == 1 || counter == 2)
          {
            out[index] = 'H';
            color = COLOR_RED;
          }
          else
          {
            out[index] = '.';
            color = COLOR_BLUE;
          }
          break;
        default:
          out[index] = in[index];
          color = COLOR_BLACK;
          break;
        }
      }
      else
      {
        out[index] = in[index];
        switch(in[index])
        {
        case 't':
          color = COLOR_YELLOW;
          break;
        case 'H':
          color = COLOR_RED;
          break;
        case '.':
          color = COLOR_BLUE;
          break;
        default:
          color = COLOR_BLACK;
          break;
        }
      }
      if(color != COLOR_BLACK) box(1 + i * 6, 1 + j * 6, 5, 5, color);
      if(i == x && j == y) cross(1 + i * 6, 1 + j * 6, COLOR_WHITE);
    }
  }
}

void copy(const char *in, int size, char *out, int w, int h)
{
  int i, code, eol, col, row;

  col = 0;
  row = 0;

  for(i = 0; i < size && col < w && row < h; ++i)
  {
    code = in[i];
    eol = (code == '\n' || code == '\r');

    if(eol)
    {
      if(col > 0)
      {
        ++row;
        col = 0;
      }
      continue;
    }

    out[row * w + col] = code;
    ++col;
  }
}

void menu()
{
  if(running)
  {
    print(0, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, "Stop ");
  }
  else
  {
    print(0, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, "Start");
  }
  print(64, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, " Save");
  print(128, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, " Load");
  print(192, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, " Wire");
  print(256, LCD_HEIGHT_PX - 16, COLOR_BLACK, COLOR_WHITE, "Electron");
}

void timeout()
{
  memset(vram, 0, LCD_WIDTH_PX * (LCD_HEIGHT_PX - 16) * 2);
  transition(world[generation], world[1 - generation], COLS, ROWS);
  menu();
  Bdisp_PutDisp_DD();
  generation = 1 - generation;
}

void load(int fd)
{
  size_t size;

  size = Bfile_GetFileSize_OS(fd);
  if(size > sizeof(buffer)) size = sizeof(buffer);
  size = Bfile_ReadFile_OS(fd, buffer, size, 0);
  Bfile_CloseFile_OS(fd);

  generation = 0;

  memset(world[0], ' ', COLS * ROWS);
  memset(world[1], ' ', COLS * ROWS);

  copy(buffer, size, world[0], COLS, ROWS);
}

int main()
{
  int fd;
  int key, timer;

  generation = 0;
  running = 1;
  wire = 0;
  electron = 0;
  x = COLS - 1;
  y = ROWS - 1;

  memset(world[0], ' ', COLS * ROWS);
  memset(world[1], ' ', COLS * ROWS);

  copy(example, sizeof(example), world[0], COLS, ROWS);

  Bdisp_EnableColor(1);
  vram = GetVRAMAddress();

  timer = Timer_Install(0, timeout, 80);
  Timer_Start(timer);

  while(1)
  {
    GetKey(&key);
    switch(key)
    {
    case KEY_CTRL_F1:
      running = 1 - running;
      break;
    case KEY_CTRL_F3:
      Timer_Stop(timer);
      Timer_Deinstall(timer);
      memset(vram, 255, LCD_WIDTH_PX * LCD_HEIGHT_PX * 2);
      fd = open_file_dialog("", "*");
      if(fd >= 0) load(fd);
      timer = Timer_Install(0, timeout, 100);
      Timer_Start(timer);
      break;
    case KEY_CTRL_F4:
      wire = 1;
      break;
    case KEY_CTRL_F5:
      electron = 1;
      break;
    case KEY_CTRL_UP:
      if(y > 0) --y;
      break;
    case KEY_CTRL_DOWN:
      if(y < ROWS - 1) ++y;
      break;
    case KEY_CTRL_LEFT:
      if(x > 0) --x;
      break;
    case KEY_CTRL_RIGHT:
      if(x < COLS - 1) ++x;
      break;
    }
  }

  return 0;
}
