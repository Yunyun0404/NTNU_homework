CC=gcc
OBJDIR:=$(shell [ -d obj ] || mkdir obj && echo "obj")
CFLAGS=-Wall -Wextra -std=gnu11
LDFLAGS=-lm

TARGETS=hw0205 #hw0401 hw0402 hw0403 hw0404 hw0405
hw0205_OBJ=myvector.o hw0205.o

.PHONY: all

all: CFLAGS:=$(CFLAGS) -O2
all: $(TARGETS)

debug: CFLAGS:=$(CFLAGS) -g -DDEBUG -fsanitize=leak -fsanitize=undefined
debug: LDFLAGS:=$(LDFLAGS) -fsanitize=address -lubsan -lasan
debug: $(TARGETS)

dev: CFLAGS:=$(CFLAGS) -g -DDEBUG
dev: LDFLAGS:=$(LDFLAGS)
dev: $(TARGETS)


.SECONDEXPANSION:
$(TARGETS): $$(patsubst %, $(OBJDIR)/%, $$($$@_OBJ))
	$(CC) $(filter %.o, $^) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(TARGETS) obj