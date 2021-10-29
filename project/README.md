## Description and how to use
This toy can play the Mario theme song if you hold the switch 1 in the green
board. Along with been able to turn both the green and red LEDs on the main
board and be able to control how dim or bright each LED is! So when both LEDs
are on, pressing switch 2 will make the green LED dimmer and you can keep
pressing switch 2 multiple times to make it even more dimmer until you reach a
botton press that resets the LED back to being fully bright. The same can be
done for the red LED but you must use switch 3 instead. Lastly, switch 4 will
turn off both LEDs once you are tired of messing around with the LEDs.

## Compiling, loading, and cleaning

The Makefile provided within the project folder has commands to compile and
run the toy on the msp430. The make load-c will uploud the version of the toy
that contains a no assembly implementation of the toy, while the load-s will
upload the version of the toy that uses an assembly file to execute the
Dim25Green that dims the green LED to 25%. There's also a make clean command
that removes all object files along with the .elf file that is produced by the
make load-c or load-s command.
