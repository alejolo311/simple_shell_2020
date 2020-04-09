# Make file for Building the New Shell Project
# Author: Alejo lópez

# Variables

CFLAGS = -Wall -Werror -Wextra -pedantic
SRC := src
HEADERSRC := $(SRC)/headers
READSRC := $(SRC)/read
READHELPERSRC := $(SRC)/read/helpers
PARSESRC := $(SRC)/parse
EXECUTESRC := $(SRC)/execute
ERRORSRC := $(SRC)/errorHandler
GARBAGESRC := $(SRC)/garbageCollector
BUILD := build
BINARY := newShell

# Make folders

$(shell   mkdir -p $(BUILD)/read/helpers \
				   $(BUILD)/parse/helpers \
				   $(BUILD)/execute/helpers \
				   $(BUILD)/error/helpers \
				   $(BUILD)/garbageCollector/helpers)

# default command

all: newShell

# define sources

SOURCES := $(wildcard $(SRC)/*.c) \
		   $(wildcard $(READSRC)/*.c) \
		   $(wildcard $(PARSESRC)/*.c) \
		   $(wildcard $(EXECUTESRC)/*.c) \
		   $(wildcard $(ERRORSRC)/*.c) \
		   $(wildcard $(GARBAGESRC)/*.c) \
		   $(wildcard $(READSRC)/helpers/*.c) \
		   $(wildcard $(PARSESRC)/helpers/*.c) \
		   $(wildcard $(EXECUTESRC)/helpers/*.c) \
		   $(wildcard $(ERRORSRC)/helpers/*.c) \
		   $(wildcard $(GARBAGESRC)/helpers/*.c)

OBJECTS := $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SOURCES))

# compile to object

$(BUILD)/%.o: $(SRC)/%.c
	$(CC) -I $(HEADERSRC) $(CFLAGS) -c $< -o $@

# compile the final binary

newShell: $(OBJECTS)
	$(CC) $^ -o $@

clean:
	@rm -rf build
	@rm -rf $(BINARY)
	
style: style
	betty ./src/headers/*.h
	betty ./src/*.c
	betty ./src/read/*.c
	betty ./src/read/helpers/*.c
	betty ./src/parse/*.c
	betty ./src/parse/helpers/*.c
	betty ./src/execute/*.c
	betty ./src/execute/helpers/*.c
	betty ./src/errorHandler/*.c
	betty ./src/errorHandler/helpers/*.c
	betty ./src/garbageCollector/*.c
	betty ./src/garbageCollector/helpers/*.c