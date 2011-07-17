#ifndef __MULTIMON_INT_H__
#define __MULTIMON_INT_H__

#include "multimon.h"

void demod_init(struct demod_state *s, demod_callback_t callback,
        void *user_data);

#endif
