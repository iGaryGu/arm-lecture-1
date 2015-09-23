CC	= arm-linux-gnueabihf-gcc
CFLAGS	= -O1 -Wall
LDFLAGS = -fno-stack-protector -lrt

objects	= fibseq.o fib.o

default: fibseq

.PHONY: default clean qemu

fibseq: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^

fib.o: fib.s
fibseq.o: fibseq.c

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

%.o: %.s
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) fibseq timing.txt output.png

sh: fibseq
	@sh cmd

Fibtime: fibseq
	@$(EXEC_ARM) ./fibseq 1 &

qemu: fibseq
	@bash unitest.sh
	@yes 20 | $(EXEC_ARM) ./fibseq 0 &

draw: fibseq timing.txt
	@gnuplot draw.gp
