CC      := gcc
CFLAGS  := -Wall -Wextra -Werror
BUILD   := build
SRC     := src
TARGETS := minils minicat miniecho minimkdir minitouch minirmdir minirm

all: $(BUILD) $(TARGETS)

$(BUILD):
	mkdir -p $(BUILD)

$(TARGETS): %: $(SRC)/%.c | $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $<

.PHONY: clean
clean:
	rm -rf $(BUILD)

.PHONY: all

