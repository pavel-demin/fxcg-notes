#include <fxcg/defs.h>
#include <fxcg/print.h>
#include <fxcg/syscalls.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static color_t file[] =
{
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0xf79e, 0xf79e, 0xf79e,
  0xf79e, 0xf79e, 0x0000, 0x73ae, 0x0000, 0xffff, 0xffff, 0xffff,
  0x0000, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0x0000, 0xb596,
  0x73ae, 0x0000, 0xffff, 0xffff, 0x0000, 0xf79e, 0xf79e, 0xf79e,
  0xf79e, 0xf79e, 0x0000, 0xf79e, 0xb596, 0x73ae, 0x0000, 0xffff,
  0x0000, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0x0000, 0xf79e,
  0xf79e, 0xb596, 0x73ae, 0x0000, 0x0000, 0xf79e, 0xf79e, 0xf79e,
  0xf79e, 0xf79e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xa514,
  0xa514, 0xa514, 0xa514, 0x0000, 0x0000, 0xf79e, 0xf79e, 0xf79e,
  0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0x0000,
  0x0000, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e,
  0xf79e, 0xf79e, 0xf79e, 0x0000, 0x0000, 0xf79e, 0xf79e, 0xf79e,
  0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0x0000,
  0x0000, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e,
  0xf79e, 0xf79e, 0xf79e, 0x0000, 0x0000, 0xf79e, 0xf79e, 0xf79e,
  0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0x0000,
  0x0000, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e,
  0xf79e, 0xf79e, 0xf79e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

static color_t folder[] =
{
  0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff,
  0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0xa38a, 0xed51,
  0xed51, 0xa38a, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
  0x0000, 0xa38a, 0xed51, 0xed51, 0xed51, 0xed51, 0xa38a, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xeeb1, 0xeeb1, 0xeeb1,
  0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0x0000,
  0x0000, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1,
  0xeeb1, 0xeeb1, 0xeeb1, 0x0000, 0x0000, 0xeeb1, 0xeeb1, 0xeeb1,
  0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0x0000,
  0x0000, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1,
  0xeeb1, 0xeeb1, 0xeeb1, 0x0000, 0x0000, 0xeeb1, 0xeeb1, 0xeeb1,
  0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0x0000,
  0x0000, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1, 0xeeb1,
  0xeeb1, 0xeeb1, 0xeeb1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

struct entry
{
  int size;
  char name[31];
  char info[7];
};

color_t *vram;

static int compare(const void *p1, const void *p2)
{
  struct entry *e1 = *(struct entry **)p1;
  struct entry *e2 = *(struct entry **)p2;
  int dir1 = (e1->size == 0);
  int dir2 = (e2->size == 0);
  return (dir1 == dir2) ? strcmp(e1->name, e2->name) : (dir2 - dir1);
}

static void draw_icon(int x, int y, int w, int h, const color_t *icon)
{
  int i, j;
  color_t color;
  for(i = 0; i < h; ++i)
  {
    for(j = 0; j < w; ++j)
    {
      color = icon[i * w + j];
      if(color == 0xffff) continue;
      vram[(y + i) * LCD_WIDTH_PX + x + j] = color;
    }
  }
}

static int draw_list(const char *dir, struct entry **list, int size, int first, int current)
{
  int i, y;
  char buffer[8];
  struct scrollbar sb;

  sb.i1 = 0;
  sb.indicatormaximum = size;
  sb.indicatorheight = 9;
  sb.indicatorpos = first;
  sb.i5 = 0;
  sb.barheight = LCD_HEIGHT_PX - 48;
  sb.bartop = 0;
  sb.barleft = LCD_WIDTH_PX - 6;
  sb.barwidth = 6;

  memset(vram + LCD_WIDTH_PX * 24, 255, LCD_WIDTH_PX * 172 * 2);
  print(0, 23, COLOR_BLUE, COLOR_WHITE, dir);
  for(i = first; i < first + 9 && i < size; ++i)
  {
    y = 40 + (i - first) * 17;
    if(i == current)
    {
      memset(vram + LCD_WIDTH_PX * y, 0, LCD_WIDTH_PX * 16 * 2);
      print(16, y, COLOR_WHITE, COLOR_BLACK, list[i]->name);
    }
    else
    {
      print(16, y, COLOR_BLACK, COLOR_WHITE, list[i]->name);
    }
    if(list[i]->size == 0)
    {
      draw_icon(2, y + 3, 12, 10, folder);
    }
    else
    {
      draw_icon(2, y + 1, 12, 14, file);
      if(i == current)
      {
        print(316, y, COLOR_WHITE, COLOR_BLACK, list[i]->info);
      }
      else
      {
        print(316, y, COLOR_BLACK, COLOR_WHITE, list[i]->info);
      }
    }
  }
  Scrollbar(&sb);
  sprintf(buffer, "%d", first);
  print(0, LCD_HEIGHT_PX - 17, COLOR_BLACK, COLOR_WHITE, buffer);
  sprintf(buffer, "%d", current);
  print(40, LCD_HEIGHT_PX - 17, COLOR_BLACK, COLOR_WHITE, buffer);
}

static int fill_list(const char *dir, const char *mask, struct entry **list, int size)
{
  int i, rc, type, handle;
  unsigned short path[266], found[266];
  char buffer[266];
  struct file_info info;

  i = 0;
  strcpy(buffer, dir);
  strcat(buffer, "*");
  Bfile_StrToName_ncpy(path, buffer, 266);
  rc = Bfile_FindFirst_NON_SMEM(path, &handle, found, &info);
  Bfile_StrToName_ncpy(path, mask, 266);
  while(rc == 0 && i < size)
  {
    Bfile_NameToStr_ncpy(buffer, found, 266);
    if((info.fsize != 0 && Bfile_Name_MatchMask(path, found)) || (info.fsize == 0 && strcmp(buffer, "..") != 0 && strcmp(buffer, ".") != 0))
    {
      list[i]->size = info.fsize;
      strncpy(list[i]->name, buffer, 30);
      list[i]->name[30] = 0;
      if(info.fsize)
      {
        type = 0;
        while(info.fsize >= 1024)
        {
          info.fsize /= 1024;
          ++type;
        }

        switch(type)
        {
        case 1:
          list[i]->info[5] = 'K';
          break;
        case 2:
          list[i]->info[5] = 'M';
          break;
        }
        list[i]->info[0] = ':';
        list[i]->info[1] = ' ';
        sprintf(buffer, "%4d", info.fsize);
        memcpy(list[i]->info + (type ? 1 : 2), buffer, 4);
        list[i]->info[6] = 0;
      }
      ++i;
    }
    rc = Bfile_FindNext_NON_SMEM(handle, found, &info);
  }
  Bfile_FindClose(handle);
  qsort(list, i, sizeof(struct entry *), compare);
  return i;
}

FILE *open_file_dialog(const char *dir, const char *mask)
{
  int size, i, first, level, key;
  struct entry pool[256];
  struct entry *list[256];
  char current[266] = "\\\\fls0\\";

  for(i = 0; i < 256; ++i)
  {
    list[i] = &pool[i];
  }

  vram = GetVRAMAddress();

  strcat(current, dir);
  size = fill_list(current, mask, list, 256);
  i = 0;
  first = 0;
  level = 0;
  while(1)
  {
    draw_list(current + 6, list, size, first, i);
    GetKey(&key);
    switch(key)
    {
    case KEY_CTRL_UP:
      --i;
      if(i < 0)
      {
        i = size - 1;
        first = size > 9 ? size - 9 : 0;
      }
      if(i < first) --first;
      break;
    case KEY_CTRL_DOWN:
      ++i;
      if(i >= size)
      {
        i = 0;
        first = 0;
      }
      if(i > first + 8) ++first;
      break;
    case KEY_CTRL_EXE:
      if(size == 0) break;
      if(list[i]->size == 0)
      {
        strcat(current, list[i]->name);
        strcat(current, "\\");
        size = fill_list(current, mask, list, 256);
        i = 0;
        first = 0;
        ++level;
      }
      else
      {
        strcat(current, list[i]->name);
        return fopen(current, "r");
      }
      break;
    case KEY_CTRL_EXIT:
      if(level)
      {
        i = strlen(current) - 1;
        while(current[--i] != '\\');
        current[i + 1] = 0;
        size = fill_list(current, mask, list, 256);
        i = 0;
        first = 0;
        --level;
      }
      else
      {
        return NULL;
      }
      break;
    }
  }
}
