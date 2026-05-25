cc == gcc
CFLAGS = -Iinclude

SRC = src/*.c
OUT = inventory

all:
	$(cc) $(SRC) $(CFLAGS) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)

