//
//  main.c
//  bs_proc_89
//
//  Created by Markus Klemm on 21.01.14.
//  Copyright (c) 2014 net.markusklemm. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, const char * argv[])
{
    srandom(time(NULL));
    int processCount = atoi(argv[1]);
    
    int i;
    for (i=0; i < processCount; i++) {
        int forkreturn = fork();
        if (forkreturn == -1) {
            perror(NULL);
            exit(EXIT_FAILURE);
        }
        else if (forkreturn != 0)
        {
            //Parent process
            continue;
        }
        else
        {
            //Child
            printf("I'm a child!\n");
            sleep(10);
            printf("Child is sleepy\n");
            exit(EXIT_SUCCESS);
        }
        
        
    }
    
    sleep(20);
    printf("Parent is sleepy\n");
    
    return EXIT_SUCCESS;
}

