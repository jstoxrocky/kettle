# -------- Config --------
CLANG_FORMAT ?= clang-format

# Find all matching files (only those that exist)
FORMAT_FILES := $(shell find src include lib -type f \( -name '*.cpp' -o -name '*.c' -o -name '*.h' \) 2>/dev/null)

PIO_ENV ?= nanoatmega328new

# -------- Targets --------
.PHONY: format check-format tidy build upload monitor clean

format:
	@echo "Formatting files..."
	@$(CLANG_FORMAT) -i $(FORMAT_FILES)

check-format:
	@echo "Checking format..."
	@$(CLANG_FORMAT) --dry-run --Werror $(FORMAT_FILES)

tidy:
	clang-tidy $(shell find src -name '*.cpp' 2>/dev/null) -- -Isrc -Iinclude -Ilib

build:
	pio run -e $(PIO_ENV)

upload:
	pio run -e $(PIO_ENV) -t upload

monitor:
	pio device monitor -b 115200

clean:
	pio run -e $(PIO_ENV) -t clean
