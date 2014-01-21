//
//  main.c
//  bs_proc_89
//
//  Created by Markus Klemm on 21.01.14.
//  Copyright (c) 2014 net.markusklemm. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, const char * argv[])
{
    int gendepth = 3;
    int gencurr = gendepth;
    int i;
    
    for (i = 0; i < gendepth; i++) {
        pid_t mypid = fork();
        if (mypid == -1) {
            perror(NULL);
            exit(EXIT_FAILURE);
        }
        else if (mypid != 0)
        {
            //Parent
            break;
        }
        gencurr--;
        
    }
    wait(NULL);
    printf("%d ",gendepth-gencurr);
    
    
    

}

