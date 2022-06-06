CC=gcc
OBJDIR:=$(shell [ -d obj ] || mkdir obj && echo "obj")
CFLAGS=-Wall -Wextra -std=gnu11
LDFLAGS= -lcurl -lm
INCLUDE = -I curl-7.68.0/include
LIB = -L curl-7.68.0/lib/.libs/
 

TARGETS=hw0503 hw0501 hw0502  #hw0504
hw0501_OBJ=hw0501.o
hw0502_OBJ=hw0502.o
hw0503_OBJ=hw0503.o
#hw0404_OBJ=fun.o hw0404.o

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
	$(CC) $(CFLAGS) ${INCLUDE} ${LIB} -c -o $@ $<

clean:
	rm -rf $(TARGETS) obj