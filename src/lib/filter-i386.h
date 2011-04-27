/*
 *      filter-i386.h -- optimized filter routines
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

/* ---------------------------------------------------------------------- */

#ifndef _FILTER_I386_H
#define _FILTER_I386_H

/* ---------------------------------------------------------------------- */

#define __HAVE_ARCH_MAC
#define mac(a,b,size) \
(__builtin_constant_p(size) ? __mac_c((a),(b),(size)) : __mac_g((a),(b),(size)))

#include <stdio.h>

inline float __mac_g(const float *a, const float *b, unsigned int size);
inline float __mac_c(const float *a, const float *b, unsigned int size);

#endif /* _FILTER_I386_H */




