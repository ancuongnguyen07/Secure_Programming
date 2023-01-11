CFLAGS=-g -O0 -Wall -Wextra

all: demos_attacks

demos_attacks: overflow_attacks.c
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf demos_attacks*