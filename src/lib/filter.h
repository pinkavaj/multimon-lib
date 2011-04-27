/*
 *      filter.h -- optimized filter routines
 *
 *      Copyright (C) 1996  
 *          Thomas Sailer (sailer@ife.ee.ethz.ch, hb9jnx@hb9w.che.eu)
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef _FILTER_H
#define _FILTER_H

#ifdef ARCH_I386
#include "filter-i386.h"
#endif /* ARCH_I386 */

extern inline unsigned int hweight32(unsigned int w)
        __attribute__ ((unused));
extern inline unsigned int hweight16(unsigned short w)
        __attribute__ ((unused));
extern inline unsigned int hweight8(unsigned char w)
        __attribute__ ((unused));

extern inline unsigned int gcd(unsigned int x, unsigned int y)
        __attribute__ ((unused));
extern inline unsigned int lcm(unsigned int x, unsigned int y)
        __attribute__ ((unused));

#ifndef __HAVE_ARCH_MAC
extern inline float mac(const float *a, const float *b, unsigned int size);
#endif /* __HAVE_ARCH_MAC */

inline float fsqr(float f);

#endif /* _FILTER_H */
