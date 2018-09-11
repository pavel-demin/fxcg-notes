TARGET   = libmusl.a
SOURCES  = $(wildcard */*.c)
OBJECTS  = $(SOURCES:.c=.o)
INCLUDES = -Iinclude -Iinternal
CFLAGS   = -Os -mb -m4a-nofpu -mhitachi -flto
ARFLAGS  = cru
################################################################################
CC       = sh3eb-elf-gcc
AR       = sh3eb-elf-gcc-ar
RANLIB   = sh3eb-elf-gcc-ranlib
RM       = rm -f
################################################################################
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo ">> Linking $@"
	@$(AR) $(ARFLAGS) $@ $^
	@$(RANLIB) $@

%.o: %.c
	@echo ">> Compiling $<"
	@$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	@$(RM) $(OBJECTS)
	@$(RM) $(TARGET)
