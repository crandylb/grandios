README.txt -- For grandios repository on GitHub, CRB, Oct 3, 2012
03/24/2013 CRB Correct make testfiotinc and added -fsigned-char.

Files in this directory:

grandios.c    Grand I/O system in C for Stage2
grandios.h    include file for grandios
makefile      make file for grandios and its test program
fiotinc.c     test program for grandios as used in stage2
iotd.txt      test data for fiotinc
fiot	      subdirectory containing test output:
  fiot.ch3      test output on channel 3
  fiot.ch4      test output on channel 4
grandios.odt  document describing the Grand I/O system
README.txt    this file

grandios.c and grandios.h:

See the document grandios.odt for a description of the Grand I/O system
implementation written in standard C. Grandios is the I/O system used by
Stage2 and should compile on any C compiler that comforms to the standard.

makefile:

Use:
	make grandios.o
to make the object module to be linked with stage2 or the fiotinc test
program. Note that makefile uses:
	gcc -c -m32 -DWITHMAIN -fsigned-char grandios.c
where -m32 specifies 32-bit object format for x86 systems, and -DWITHMAIN
defines WITHMAIN so that grandios contains the C main() program. This main()
program initializes the I/O system and calls the application program via
progr(). The -fsigned-char forces gcc to allow -1 to be recognized as
end-of-line on ARM which otherwise uses unsigned char as default.

Use:
	make testfiotinc
to compile and link the test program. Then run the test program with:
   	make test
The test program will read the test data file iotd.tst on channel 1 and write
two output files: fiot.ch3 and fiot.ch4.
IMPORTANT NOTE: To complete the test press Ctrl-D. This sends an end-of-file
to standard input.

Contents of fiot.ch3:
MOBILE PROGRAMMING SYSTEM I/O TEST - CHANNEL 3 OUTPUT

Contents of fiot.ch4:
MOBILE PROGRAMMING SYSTEM I/O TEST - CHANNEL 4 OUTPUT

1)  IF THIS APPEARS TWICE, THE CHANNEL IS NOT BEING CLEARED PROPERLY.
2)
3)  IF THIS LINE IS OK, THEN TWO BUFFER AREAS DO NOT INTERACT.
4)  IF THIS LINE IS OK, THEN THE BASE OF THE ARRAY CAN BE OFFSET.

If grandios and the test program are working properly the contents of your
fiot file should be identical to the example files in the fiot subdirectory.

When you are satisfied with the test output leave the grandios.o object module
in your grandios directory where it will be used to link with stage2.
