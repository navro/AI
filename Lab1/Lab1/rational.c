//
//  rational.c
//  Lab1
//
//  Created by Magnus Wallgren on 2016-04-01.
//  Copyright © 2016 Magnus Wallgren. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#include "rational.h"
#include <stdlib.h>
int main(int argc, char* argv[])
{
    rat r;
    rat s;
    rat out;
    //num/den
    r.num = 2;
    r.den = -3;
    s.num = 3;
    s.den = -5;
    
    printRat(&r);
    printf("+\n");
    printRat(&s);
    printf("=\n");
    rat* sum = addRat(&r,&s);
    printRat(sum);
    free(sum);
    printf("\n");
    
    printRat(&r);
    printf("-\n");
    printRat(&s);
    printf("=\n");
    subRat(&out,&r,&s);
    printRat(&out);
    printf("\n");
    
    printRat(&r);
    printf("*\n");
    printRat(&s);
    printf("=\n");
    mulRat(&out,&r,&s);
    printRat(&out);
    printf("\n");
    
    printRat(&r);
    printf("/\n");
    printRat(&s);
    printf("=\n");
    divRat(&out,&r,&s);
    printRat(&out);
    printf("\n");
    
    printRat(&s);
    printf("=\n");
    reduce(&s);
    printRat(&s);
    
    printf("%zu",sizeof(rat));
    
    return 0;
}

void printRat(rat* r)
{
    printf("%d/%d\n",r->num,(*r).den);
}

void reduce(rat* r)
{
    if(r->den < 0)
    {
        r->den *= -1;
        r->num *= -1;
    }
    for(int i = 2; i<=(*r).den; i++)
    {
        if(r->num%i == 0 && r->den%i == 0)
        {
            r->num /= i;
            r->den /= i;
            i--;
        }
    }
}

rat* addRat(rat *r, rat *s)
{
    rat* out = malloc(sizeof(rat));
    out->den = r->den * s->den;
    out->num = r->num * s->den + s->num * r->den;
    reduce(out);
    return(out);
}

void subRat(rat* out, rat* r, rat* s)
{
    out->den = r->den * s->den;
    out->num = r->num * s->den - s->num * r->den;
    reduce(out);
}

void mulRat(rat* out, rat* r, rat* s)
{
    out->num = r->num * s->num;
    out->den = r->den * s->den;
    reduce(out);
}

void divRat(rat *out, rat *r, rat *s)
{
    out->num = r->num * s->den;
    out->den = r->den * s->num;
    reduce(out);
}



