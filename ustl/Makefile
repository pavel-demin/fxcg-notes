PREFIX   = /opt/casio
TARGET   = libustl.a
OBJECTS  = $(patsubst %.cc,%.o,$(wildcard */*.cc))
INCLUDES = -Iinclude -Iinternal -I$(PREFIX)/include
CXXFLAGS = -Os -mb -m4a-nofpu -mhitachi -std=c++98 -flto -ffreestanding -fno-strict-aliasing -fno-rtti -fno-exceptions
ARFLAGS  = cru
################################################################################
CXX      = sh3eb-elf-g++
AR       = sh3eb-elf-gcc-ar
RM       = rm -f
################################################################################
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo ">> Linking $@"
	@$(AR) $(ARFLAGS) $@ $^

%.o: %.cc
	@echo ">> Compiling $<"
	@$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<

clean:
	@echo ">> Cleaning..."
	@$(RM) $(OBJECTS)
	@$(RM) $(TARGET)
