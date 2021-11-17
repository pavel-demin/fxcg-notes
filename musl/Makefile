PREFIX   = /opt/casio
TARGET   = libmusl.a
OBJECTS  = $(patsubst %.c,%.o,$(wildcard */*.c))
INCLUDES = -Iinclude -Iinternal -I$(PREFIX)/include
CFLAGS   = -Os -mb -m4a-nofpu -mhitachi -ffreestanding -fno-strict-aliasing
ARFLAGS  = cru
################################################################################
CC       = sh3eb-elf-gcc
AR       = sh3eb-elf-gcc-ar
RM       = rm -f
################################################################################
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo ">> Linking $@"
	@$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	@echo ">> Compiling $<"
	@$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	@echo ">> Cleaning..."
	@$(RM) $(OBJECTS)
	@$(RM) $(TARGET)
