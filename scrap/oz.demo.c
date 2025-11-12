#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <time.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define RESET "\x1B[0m"

void create_three_gens(){
    pid_t grand_parent = getpid();
    time_t start_time;
    time(&start_time);
    printf(ANSI_COLOR_YELLOW"starting to create child and grand child for pid %d at %s \n"RESET, grand_parent, ctime(&start_time));

    pid_t parent = fork();
    if(parent == 0){
        pid_t parents_name = getpid();
        time_t time_after_parent;
        time(&time_after_parent);
        printf(ANSI_COLOR_GREEN"Grand parent with pid %d created parent with pid %d at %s \n"RESET, parents_name, grand_parent, ctime(&time_after_parent));
        printf(ANSI_COLOR_GREEN"It has been %f since the creation process started\n"RESET, difftime(time_after_parent, start_time));
        
        pid_t child = fork();
        if(child == 0){
            pid_t childs_name = getpid();
            time_t time_after_child;
            time(&time_after_child);
            printf(ANSI_COLOR_BLUE"parent with pid %d created child with pid %d at %s \n"RESET, parents_name, childs_name, ctime(&time_after_child));
            printf(ANSI_COLOR_BLUE"It has been %f since the creation process started\n"RESET, difftime(time_after_child, start_time));
            
            int count = 0;
            while(getppid() != 1){
                time_t adopted_time;
                if(count % 1000000 == 0){
                    printf("waiting to get adopted =(\n");
                    time(&adopted_time);
                    printf("It has been %f since the creation process started\n", difftime(adopted_time, start_time));
                }

                count++;
            }
        }else{
            time(&time_after_parent);
            printf(ANSI_COLOR_GREEN"parent pid %d is going to sleep at %s"RESET, parents_name, ctime(&time_after_parent));
            printf(ANSI_COLOR_GREEN"It has been %f since the creation process started\n"RESET, difftime(time_after_parent, start_time));
            sleep(3);
            time(&time_after_parent);
            printf(ANSI_COLOR_GREEN"parent pid %d woke up at %s"RESET, parents_name, ctime(&time_after_parent));
            printf(ANSI_COLOR_GREEN"It has been %f since the creation process started\n"RESET, difftime(time_after_parent, start_time));
        }
    }else{
        time_t time_wait;
        time(&time_wait);
        printf(ANSI_COLOR_YELLOW"grand parent pid %d is going to sleep at %s"RESET, grand_parent, ctime(&time_wait));
        printf(ANSI_COLOR_YELLOW"It has been %f since the creation process started\n"RESET, difftime(time_wait, start_time));
        sleep(6);
        time(&time_wait);
        printf(ANSI_COLOR_YELLOW"grand parent pid %d woke up at %s"RESET, grand_parent, ctime(&time_wait));
        printf(ANSI_COLOR_YELLOW"It has been %f since the creation process started\n"RESET, difftime(time_wait, start_time));
        
        printf(ANSI_COLOR_YELLOW"grand parent pid %d is waiting for pid %d finish at %s\n"RESET, grand_parent, parent,  ctime(&time_wait));
        printf(ANSI_COLOR_YELLOW"It has been %f since the creation process started\n"RESET, difftime(time_wait, start_time));
        wait(NULL);
        time(&time_wait);
        printf(ANSI_COLOR_YELLOW"grand parent pid %d reaped pid %d\n finished!! at %s\n"RESET, grand_parent, parent, ctime(&time_wait));
    }

}

int main() {
    create_three_gens();
    return 0;
}