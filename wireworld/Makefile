PREFIX   = /opt/casio
TARGET   = wirewrld.g3a
BINARY   = $(TARGET:.g3a=.bin)
OBJECTS  = $(patsubst %.c,%.o,$(wildcard *.c))
INCLUDES = -I$(PREFIX)/include
CFLAGS   = -Os -mb -m4a-nofpu -mhitachi -ffreestanding -fno-strict-aliasing
LDFLAGS  = -nostdlib -T$(PREFIX)/ldscript.ld
LIBS     = -L$(PREFIX)/lib -ldialogs -lmusl -lfxcg -lgcc
################################################################################
CC       = sh3eb-elf-gcc
AR       = sh3eb-elf-gcc-ar
RM       = rm -f
################################################################################
.PRECIOUS: $(OBJECTS) $(BINARY)

all: $(TARGET)

%.g3a: %.bin
	@echo ">> Creating $@"
	@mkg3a -n :Wireworld -i uns:unselected.png -i sel:selected.png $^ $@

%.bin: $(OBJECTS)
	@echo ">> Linking $@"
	@$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

%.o: %.c
	@echo ">> Compiling $<"
	@$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	@echo ">> Cleaning..."
	@$(RM) $(OBJECTS)
	@$(RM) $(BINARY)
	@$(RM) $(TARGET)
