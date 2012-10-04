/* grandios.h -- Stage2 I/O in C Header, CRB, Sep 30, 2012 */
// 12/13/1994 CRB Approximate date of original coding.
//

#define MAXCHAN   9	/* maximum channel number */
#define MAXLEN  120	/* length of LINE buffer */

struct CHAN {
    char r;		/* read access */
    char w;		/* write access */
    char o;		/* open access */
    char c;		/* control access */
    char s;		/* status */
    FILE* fp;		/* stream file pointer */
    char *pFile;	/* pointer to filename */
};

int ioop(int jop, int jch, char *jba);	/* I/O Operation Processor */
int iwrch(char ch);			/* write a character to LINE */
int iprnt(int jch);			/* print error message from MB */
int iread(int jch);			/* read input into LINE buffer */
int iwrite(int jch);			/* write out the LINE buffer */
int icntl(int jch);			// rewind
int iclose(int jch);			// close jch, or all if jch = -1
int iinit(int argc, char * argv[]);	// default initialization
