/*
 *      multimon.h -- Monitor for many different modulation formats
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

#ifndef _MULTIMON_H
#define _MULTIMON_H

/* ---------------------------------------------------------------------- */

extern const float costabf[0x400];
#define COS(x) costabf[(((x)>>6)&0x3ffu)]
#define SIN(x) COS((x)+0xc000)

/* ---------------------------------------------------------------------- */

typedef void (*demod_callback_t)(char val, int err, void *data) ;

struct demod_state {
	const struct demod_param *dem_par;
    /** Call back function and user data. */
    demod_callback_t demod_callback;
    void *user_data;
	union {
		struct l1_state_dtmf {
			unsigned int ph[8];
			float energy[4];
			float tenergy[4][16];
			int blkcount;
			int lastch;
		} dtmf;

		struct l1_state_zvei {
			unsigned int ph[16];
			float energy[4];
			float tenergy[4][32];
			int blkcount;
			int lastch;
		} zvei;
	} l1;
};

struct demod_param {
	const char *name;
	unsigned int samplerate;
	unsigned int overlap;
	void (*init)(struct demod_state *s, demod_callback_t callback,
            void *user_data);
	void (*demod)(struct demod_state *s, float *buffer, int length);
};

/* ---------------------------------------------------------------------- */

extern const struct demod_param demod_dtmf;
extern const struct demod_param demod_zvei;

#define ALL_DEMOD &demod_dtmf, &demod_zvei

/* ---------------------------------------------------------------------- */

void verbprintf(int verb_level, const char *fmt, ...);

/* ---------------------------------------------------------------------- */
#endif /* _MULTIMON_H */
