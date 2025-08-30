#include "../Inc/philosophers.h"

/* ===== debug.c ===== */
#include <stdio.h>    /* [ADDED] fprintf */
#include <stdlib.h>   /* [ADDED] getenv */

/* [ADDED] Estado global de debug: -1 = auto (lee PHILO_DEBUG), 0 = off, 1 = on */
static int  g_debug = -1;

/* [ADDED] Setter público: permite activar o desactivar en runtime */
void    set_debug(int on)
{
    g_debug = (on != 0);
}

/* [ADDED] Helper interno: decide si está activo (lee env la primera vez) */
static int is_debug(void)
{
    const char  *v;

    if (g_debug == -1)
    {
        v = getenv("PHILO_DEBUG");
        g_debug = (v && *v) ? 1 : 0;
    }
    return (g_debug);
}

/* [ADDED] Evento por filósofo: imprime a stderr datos clave del estado actual */
void    dbg_event(t_philosopher *p, const char *evt)
{
    long    now;
    long    last;
    int     meals;

    if (!is_debug() || !p || !p->table)
        return;
    now = get_time();
    pthread_mutex_lock(&p->meal_mutex);
    last = p->last_meal;
    meals = p->meals_eaten;
    pthread_mutex_unlock(&p->meal_mutex);
    /* Nota: usamos stderr para no ensuciar la salida que miran los testers */
    fprintf(stderr, "[DBG] %ld id=%d %s  since_last=%ld  meals=%d\n",
        now - p->table->start_time, p->id + 1, evt, now - last, meals);
}

/* [ADDED] Foto global: comidas y ms desde última comida de todos los filósofos */
void    dbg_snapshot(t_philosopher *ph, t_table *t, const char *tag)
{
    int     i;
    long    now;
    long    last;
    int     meals;

    if (!is_debug() || !ph || !t)
        return;
    now = get_time();
    fprintf(stderr, "[DBG] SNAP %s @%ldms\n", tag, now - t->start_time);
    i = 0;
    while (i < t->num_philosophers)
    {
        pthread_mutex_lock(&ph[i].meal_mutex);
        last = ph[i].last_meal;
        meals = ph[i].meals_eaten;
        pthread_mutex_unlock(&ph[i].meal_mutex);
        fprintf(stderr, "  ph%02d  meals=%d  since_last=%ld\n",
            ph[i].id + 1, meals, now - last);
        i++;
    }
}
