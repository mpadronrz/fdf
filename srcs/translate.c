#include "../includes/fdf.h"

void    set_params_iso(int kc, t_point *vec)
{
    if (kc == KAV || kc == KRE)
    {
        vec->x = 0;
        vec->y = 2 * (kc == KRE) - 1;
    }
    else if (kc == KUP || kc == KDOWN)
    {
        vec->x = (2 * (kc == KUP) - 1) * sqrt(3.0) / 2.0;
        vec->y = (2 * (kc == KUP) - 1) / 2.0;
    }
    else
    {
        vec->x = (2 * (kc == KRIGHT) - 1) * sqrt(3.0) / 2.0;
        vec->y = - (2 * (kc == KRIGHT) - 1) / 2.0;
    }
}

void    set_params_par(int kc, t_point *vec)
{
    if (kc == KAV || kc == KRE)
    {
        vec->x = 0;
        vec->y = 2 * (kc == KRE) - 1;
    }
    else if (kc == KUP || kc == KDOWN)
    {
        vec->x = (2 * (kc == KUP) - 1) * sqrt(2.0) / 2;
        vec->y = (2 * (kc == KUP) - 1) * sqrt(2.0) / 2;
    }
    else
    {
        vec->x = 2 * (kc == KRIGHT) - 1;
        vec->y = 0;
    }
}

void    set_params(t_data *fdf, int kc, t_point *vec)
{
    if (fdf->view)
        set_params_par(kc, vec);
    else
        set_params_iso(kc, vec);
}

void    translate(t_data *fdf, int kc)
{
    int i;
    int j;
    t_point vec;

    set_params(fdf, kc, &vec);
    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].x += vec.x;
            fdf->pt[i][j].y += vec.y;
            j ++;
        }
        i ++;
    }
    calculate_pixels(fdf);
}