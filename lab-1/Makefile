CC	= arm-linux-gnueabihf-gcc
CFLAGS	= -O1 -Wall
LDFLAGS = -fno-stack-protector

objects	= fibseq.o fib_tail.o

default: fibseq

.PHONY: default clean qemu

fibseq: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^

fib_tail.o: fib_tail.s
fibseq.o: fibseq.c

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

%.o: %.s
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) fibseq timing.txt output.png

sh:fibseq
	@sh cmd
qemu: fibseq
	@bash unitest.sh
	@yes 30 | $(EXEC_ARM) ./fibseq &

Fibtime:fibseq
	@$(EXEC_ARM) ./fibseq 2 &

draw:fibseq timing.txt
	@gnuplot draw.gp
