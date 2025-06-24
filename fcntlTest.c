#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>

void disableRawMode();
void enableRawMode();

struct termios orig_termios;
struct termios orig_termios;

void disableRawMode() {
tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode()
{
            tcgetattr(STDIN_FILENO, &orig_termios);
            atexit(disableRawMode);
                    struct termios raw=orig_termios;
                raw.c_lflag &= ~(ECHO | ICANON);//
                        tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
}


int main() {
    enableRawMode();
    // Set STDIN to non-blocking mode
    int flags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    char buf[100];
    int n;

    printf("Start typing (press 'q' to quit):\n");

    while (1) {
        n = read(STDIN_FILENO, buf, sizeof(buf));
        fflush(stdout);
        if (n > 0) {
            write(STDOUT_FILENO, buf, n);

            // Optional: check if user typed 'q' to quit
            for (int i = 0; i < n; i++) {
                if (buf[i] == 'q') {
                    printf("\nQuit signal received.\n");
                    return 0;
                }
            }
        }

        else printf("lottery");

        // Small pause to avoid CPU overuse
        usleep(100000); // 100 ms
    }

    return 0;
}
