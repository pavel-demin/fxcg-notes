TARGET   = libfxcg.a
SOURCES  = $(wildcard */*.S)
OBJECTS  = $(SOURCES:.S=.o)
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

%.o: %.S
	@echo ">> Compiling $<"
	@$(CC) -c -o $@ $<

clean:
	@echo ">> Cleaning..."
	@$(RM) $(OBJECTS)
	@$(RM) $(TARGET)
