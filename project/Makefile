# makfile configuration
COMMON_OBJECTS  = buzzer.o main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ./h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy-c.elf 

#additional rules for files
toy-c.elf: ${COMMON_OBJECTS} ./lib/libTimer.a Dim25Green-c.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

toy-m.elf: ${COMMON_OBJECTS} ./lib/libTimer.a Dim25Green-s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load-c: toy-c.elf
	msp430loader.sh $^

load-s: toy-m.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

