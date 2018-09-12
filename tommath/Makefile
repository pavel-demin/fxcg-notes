PREFIX   = /opt/casio
TARGET   = libtommath.a
SOURCES  = $(wildcard */*.c)
OBJECTS  = $(SOURCES:.c=.o)
INCLUDES = -Iinclude -I$(PREFIX)/include
CFLAGS   = -Os -mb -m4a-nofpu -mhitachi -flto -ffreestanding -fno-strict-aliasing
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
