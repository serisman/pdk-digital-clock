# Name: Makefile
# Project: PDK-Digital-Clock
# Author: serisman <github@serisman.com>
# Creation Date: 2020-06-25
# License: GPLv3

# ---------------------------------------------------------------------

#DEVICE = PMS152
DEVICE = PFS154
#DEVICE = PFS173
#F_CPU = 65536
F_CPU = 524288
TARGET_VDD_MV = 4000
TARGET_VDD = 4.0
#DEBUG = 1

# ---------------------------------------------------------------------

OUTPUT_NAME = DigitalClock_$(DEVICE)
DEBUG ?= 0

ifeq ($(DEVICE), PFS154)
	ARCH = pdk14
else ifeq ($(DEVICE), PFS173)
	ARCH = pdk15
else ifeq ($(DEVICE), PMS152)
	ARCH = pdk14
else ifeq ($(DEVICE), PMS154C)
	ARCH = pdk14
endif

BUILD_DIR = .build
OUTPUT_DIR = .output

OUTPUT = $(OUTPUT_DIR)/$(OUTPUT_NAME)

SOURCES = main.c
OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.rel,$(SOURCES))

# http://sdcc.sourceforge.net/doc/sdccman.pdf
COMPILE = sdcc -m$(ARCH) -c --std-sdcc11 --opt-code-size -D$(DEVICE) -DF_CPU=$(F_CPU) -DTARGET_VDD_MV=$(TARGET_VDD_MV) -DDEBUG=$(DEBUG) -I.
LINK = sdcc -m$(ARCH)
EASYPDKPROG = easypdkprog

# symbolic targets:
all: size

print-%: ; @echo $* = $($*)

$(BUILD_DIR)/%.rel: %.c
	-mkdir -p $(dir $@)
	$(COMPILE) -o $@ $<

$(OUTPUT).ihx: $(OBJECTS)
	-mkdir -p $(dir $(OUTPUT))
	$(LINK) --out-fmt-ihx -o $(OUTPUT).ihx $(OBJECTS)

$(OUTPUT).bin: $(OUTPUT).ihx
	makebin -p $(OUTPUT).ihx $(OUTPUT).bin

build: $(OUTPUT).bin

size: build
	@echo '---------- Segments ----------'
	@egrep '(ABS,CON)|(REL,CON)' $(OUTPUT).map | gawk --non-decimal-data '{dec = sprintf("%d","0x" $$2); print dec " " $$0}' | /usr/bin/sort -n -k1 | cut -f2- -d' '
	@echo '------------------------------'
	@stat -L --printf "Size of $(OUTPUT_NAME).bin: %s bytes\n" $(OUTPUT).bin

program: size
	$(EASYPDKPROG) -n $(DEVICE) write $(OUTPUT).ihx
erase:
	$(EASYPDKPROG) -n $(DEVICE) erase
probe:
	$(EASYPDKPROG) probe
run:
	$(EASYPDKPROG) -r $(TARGET_VDD) start

clean:
	rm -r -f $(BUILD_DIR) $(OUTPUT_DIR)
