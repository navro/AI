//
//  rational.h
//  Lab1
//
//  Created by Magnus Wallgren on 2016-04-01.
//  Copyright © 2016 Magnus Wallgren. All rights reserved.
//

#ifndef rational_h
#define rational_h

typedef struct rat
{
    int num; //täljare (uppe)
    int den; //nämnare (nere)
} rat;

void printRat(rat *r);
void reduce(rat *r);
rat* addRat(rat *r, rat *s);
void subRat(rat *out, rat *r, rat *s);
void mulRat(rat *out, rat *r, rat *s);
void divRat(rat *out, rat *r, rat *s);

#endif /* rational_h */
