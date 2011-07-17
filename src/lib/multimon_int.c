#include "multimon_int.h"


void demod_init(struct demod_state *s, demod_callback_t callback,
        void *user_data)
{
    s->demod_callback = callback;
    s->user_data = user_data;
}
