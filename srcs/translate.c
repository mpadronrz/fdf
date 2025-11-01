#include "../includes/fdf.h"

void    translate_x(t_data *fdf, int dir)
{
    int i;
    int j;

    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].rx += dir;
            j ++;
        }
        i ++;
    }
}

void    translate_y(t_data *fdf, int dir)
{
    int i;
    int j;

    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].ry += dir;
            j ++;
        }
        i ++;
    }
}

void    translate_z(t_data *fdf, int dir)
{
    int i;
    int j;

    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].rz += dir;
            j ++;
        }
        i ++;
    }
}

void    translate(t_data *fdf, int kc)
{
    if (kc == KUP || kc == KDOWN)
        translate_x(fdf, 2 * (kc == KUP) - 1);
    if (kc == KRIGHT || kc == KLEFT)
        translate_y(fdf, 2 * (kc == KRIGHT) - 1);
    if (kc == KRE || kc == KAV)
        translate_z(fdf, 2 * (kc == KRE) - 1);
    if (!fdf->view)
        isometric(fdf);
    else
        paralel(fdf);
}