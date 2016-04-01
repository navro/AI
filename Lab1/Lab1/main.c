//
//  main.c
//  Lab1
//
//  Created by Magnus Wallgren on 2016-04-01.
//  Copyright © 2016 Magnus Wallgren. All rights reserved.
//

#include <stdio.h>

int main(int argc, char* argv[])
{
    int	a;
//  int	b;
    int	c;
    int i;
    
    //printf("Please enter two numbers: ");
    c = 0;
    fflush(stdout);
    for(i = 1; i<argc; i++)
    {
        sscanf(argv[i],"%d",&a);
        //printf("argument number %d is %s\n", i, argv[i]);
        c += a;
    }
    //sscanf(argv[1],"%d",&a);
    //sscanf(argv[2],"%d",&b);
    //c = a + b;
    //printf("%d + %d = %d\n", a, b, c);
    //printf("sum of arguments is %d\n",c);
    
    FILE *f;
    f = fopen("sum","w");
    if(f != NULL)
    {
        fprintf(f,"sum of arguments is %d\n",c);
        fclose(f);
    }
    return 0;
}
