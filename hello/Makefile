PREFIX   = /opt/casio
TARGET   = hello.g3a
BINARY   = $(TARGET:.g3a=.bin)
OBJECTS  = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
INCLUDES = -I$(PREFIX)/include -I$(PREFIX)/include/ustl
CXXFLAGS = -Os -mb -m4a-nofpu -mhitachi -std=c++98 -ffreestanding -fno-strict-aliasing -fno-rtti -fno-exceptions
LDFLAGS  = -nostdlib -T$(PREFIX)/ldscript.ld
LIBS     = -L$(PREFIX)/lib -lustl -lmusl -lfxcg -lgcc
################################################################################
CXX      = sh3eb-elf-g++
RM       = rm -f
################################################################################
.PRECIOUS: $(OBJECTS) $(BINARY)

all: $(TARGET)

%.g3a: %.bin
	@echo ">> Creating $@"
	@mkg3a -n :Hello -i uns:unselected.png -i sel:selected.png $^ $@

%.bin: $(OBJECTS)
	@echo ">> Linking $@"
	@$(CXX) $(LDFLAGS) $^ $(LIBS) -o $@

%.o: %.cpp
	@echo ">> Compiling $<"
	@$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<

clean:
	@echo ">> Cleaning..."
	@$(RM) $(OBJECTS)
	@$(RM) $(BINARY)
	@$(RM) $(TARGET)
