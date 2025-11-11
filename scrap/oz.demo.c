#include <stdio.h>
#include <unistd.h>
#include <time.h>

double get_time_diff(time_t t){
    time_t currentTime;
    time(&currentTime);

    return difftime(currentTime, t);
}

void print_time(){
    time_t currentTime;
    time(&currentTime);
    printf("It is %s now\n", ctime(&currentTime));
}

pid_t create_child(pid_t parent_pid){
    pid_t child = fork();
    if (child == 0) {
        //child of
        time_t currentTime;
        time(&currentTime);
        printf("child of pid id: %d\n", pid_t);
        printf("Today's time is %s\n", ctime(&currentTime))
    }else{
        printf("parent pid: %d created child pid: %d", parent_pid, child);
        printf("Today's time is %s\n", ctime(&currentTime));
        return child;
    }

    return parent_pid;
}

int main() {
    pid_t root;
    root = getpid();
    return 0;
}