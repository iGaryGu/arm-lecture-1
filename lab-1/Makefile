CC	= arm-linux-gnueabihf-gcc
CFLAGS	= -O1 -Wall
LDFLAGS = -fno-stack-protector

objects	= fibseq.o fib.o
objects_low= fibseq_low.o fib.o
objects_high = fibseq_high.o fib.o

default: fibseq fibseq_high fibseq_low

.PHONY: default clean qemu

fibseq: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^

fibseq_low: $(objects_low)
	$(CC) $(LDFLAGS) -o $@ $^

fibseq_high: $(objects_high)
	$(CC) $(LDFLAGS) -o $@ $^

fib.o: fib.s
fibseq.o: fibseq.c
fibseq_low.o: fibseq_low.c
fibseq_high.o: fibseq_high.c

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

%.o: %.s
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) $(objects_high) $(objects_low) fibseq fibseq_high fibseq_low

sh:fibseq
	@sh cmd
qemu: fibseq
	@bash unitest.sh
	@yes 30 | $(EXEC_ARM) ./fibseq &
