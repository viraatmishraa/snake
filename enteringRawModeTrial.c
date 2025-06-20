#include <stdio.h>
#include <unistd.h>

        /*mod 2 turning off echoing*/
        #include<termios.h>
            /*mod 3 disabling raw mode, nothing complicated*/

            #include<stdlib.h>
char function();

            struct termios orig_termios;
            void disableRawMode() {
            tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
            }
            /*mod 3 disabling raw mode, nothing complicated*/

void enableRawMode(){

            tcgetattr(STDIN_FILENO, &orig_termios);
            atexit(disableRawMode);
/*These two lines ensure:

You save the current terminal settings.

You automatically restore them when the program ends.*/




    /*tcgetattr() — to get current terminal settings

tcsetattr() — to set new settings

termios struct — to modify flags like ECHO*/
        struct termios raw=orig_termios;
                raw.c_lflag &= ~(ECHO | ICANON);//comment line 46,47 for this to work
/*
struct termios {
    tcflag_t c_iflag;     // Input modes
    tcflag_t c_oflag;     // Output modes
    tcflag_t c_cflag;     // Control modes
    tcflag_t c_lflag;     // Local modes
    cc_t     c_line;      // Line discipline (obsolete)
    cc_t     c_cc[NCCS];  // Control characters
    speed_t  c_ispeed;    // Input speed
    speed_t  c_ospeed;    // Output speed
};*/
        //tcgetattr(STDIN_FILENO,&raw);
        //raw.c_lflag &= ~(ECHO);
/*
Explanation:
------------
raw           : a struct termios variable holding terminal settings.
.             : structure member access.
c_lflag       : local flags field in termios (controls local terminal behavior).
&=            : bitwise AND assignment (keeps other bits unchanged).
~(ECHO)       : bitwise NOT of ECHO — flips the ECHO bit to 0.
ECHO is a bitflag, defined as 00000000000000000000000000001000 in binary. We use the bitwise-NOT operator (~) on this value to get 11111111111111111111111111110111. We then bitwise-AND this value with the flags field, which forces the fourth bit in the flags field to become 0, and causes every other bit to retain its current value. Flipping bits like this is common in C.
Effect:
-------
This clears the ECHO bit in c_lflag, disabling input character echoing.
Useful for password input or raw mode configurations.
*/
        tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
/*TCSANOW – Apply changes immediately.

TCSADRAIN – Apply changes after all output is written.

TCSAFLUSH – Apply changes after flushing both input and output buffers.*/
} 
/*mod 2 turning off echoing*/


int main(){
char c;
char ch;
/*
int read(int fileDescriptor, void *buffer, size_t bytesToRead)

It takes in three arguments which are described below:

fileDescriptor: We need to provide the function with an integer file descriptor for the opened file, which the open() function returns when opening a file.

buffer: This pointer points to a buffer where data that is read will be stored.

bytesToRead: Here, we provide an unsigned integer variable that specifies the maximum number of bytes we want to read from the file.
The function, when executed, returns an integer value that refers to the number of bytes read.*/
        enableRawMode();//mod 2
while(1)printf("%c maja mali\n",function());

}

char function()
{ char ch,c;
        while(read(STDIN_FILENO,&c,1)==1/*mod 1*/&&c!='q'&&(ch=c)/*read below*/)
/*In C, the && (logical AND) operator has lower precedence than the assignment operator =.

But the compiler doesn't know that ch = c is meant to be grouped together as a single expression unless you tell it explicitly.*/
{
    return ch;
}

}