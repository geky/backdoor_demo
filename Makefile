LTARGET = login
ATARGET = adduser

LSRC += login.c
LSRC += input.c
LSRC += string.c

ASRC += adduser.c
ASRC += input.c

CC = ../tcc/tcc
#CC = tcc
LFLAGS += -lcrypt

TARGET = $(LTARGET) $(ATARGET)
SRC = $(LSRC) $(RSRC)


all: $(TARGET)

$(LTARGET): $(LSRC:.c=.o)
	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@

$(ATARGET): $(ASRC:.c=.o)
	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm $(SRC:.c=.o)
	-rm $(TARGET)
