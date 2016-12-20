CC=gcc -m32
ESBDIR=$(HOME)/cJson
LIBDIR=$(ESBDIR)/lib
INCDIR=$(ESBDIR)/inc
MODDIR=$(ESBDIR)/module
INCLUDE=-I$(INCDIR)
LINKLIB=-L$(LIBDIR)
LIB_FILE=libcjson.a

LIBS= $(LIBDIR)/libttsys.a -ldl -lm

EXEC=cjson
PROBJ=cJSON.o cJSON_API.o cjson_test2.o
PROBJ1=cJSON.o cJSON_API.o

all: $(EXEC)
all: $(LIB_FILE)

.c.o:
	@echo "Compiling $< ..."
	$(CC) $(INCLUDE) -c -O2 $<

libcjson.a:$(PROBJ1)
	ar rcs $@ $?

$(EXEC):$(PROBJ)
	@echo "making $@ ..."
	$(CC) -o $@ $(PROBJ) $(LIBS)

install:
	make all
	@echo "Install ..."
	cp $(LIB_FILE) $(MODDIR)
clean:
	rm -f core $(EXEC) $(PROBJ) $(LIB_FILE)
