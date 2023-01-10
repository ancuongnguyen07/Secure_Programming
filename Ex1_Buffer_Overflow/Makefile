CFLAGS=-g -O0 -Wall -Wextra

all: buffer_overflow

buffer_overflow: bo.c
	$(CC) $(CFLAGS) -o $@ $^
	./$@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf buffer_overflow*