PREFIX   = /opt/casio
TARGET   = libdialogs.a
OBJECTS  = $(patsubst %.c,%.o,$(wildcard src/*.c))
INCLUDES = -Iinclude -I$(PREFIX)/include
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
