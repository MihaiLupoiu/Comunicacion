#include "funcions.h"

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}

long long current_timestamp() {
    struct      timeval te;
    long long   milliseconds;

    gettimeofday(&te, NULL); // get current time
    milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // caculate milliseconds

    return milliseconds;
}

int playSuperWav() {

    pid_t pid=fork();
    if (pid==0) {
        char *args[] = {"./lib/sound/superwav5", (char *) 0 };
        execv("./lib/sound/superwav5", args);
        exit(-1);
    }
    else {
        waitpid(pid,0,0);
    }
    return 0;
}
/*
int main(int argc, char *argv[]) {

}*/