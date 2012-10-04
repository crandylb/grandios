# makefile -- for grandios directory, CRB, Oct 1, 2012

grandios.o:	grandios.c grandios.h
	gcc -c -m32 -DWITHMAIN grandios.c -o grandios.o

fiotinc.o:	fiotinc.c grandios.h
	gcc -c -m32 fiotinc.c -o fiotinc.o

testfiotinc:	fiotinc.o grandios.o
	gcc -m32 grandios.o fiotinc.o -o testfiotinc

test:		testfiotinc
	echo "Press Ctrl-D to complete test (sends EOF to stdin)"
	./testfiotinc iotd.txt - fiot.ch3 fiot.ch4
# Press Ctrl-D to complete test (sends EOF to stdin)
