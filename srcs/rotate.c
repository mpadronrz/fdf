#include "../includes/fdf.h"

void    rotate_z(t_data *fdf, int s)
{
    float   x;
    float   y;
    int     i;
    int     j;

    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            x = fdf->pt[i][j].rx;
            y = fdf->pt[i][j].ry;
            fdf->pt[i][j].rx = x * cos(s * AL) - y * sin(s * AL);
            fdf->pt[i][j].ry = x * sin(s * AL) + y * cos(s * AL);
            j ++;
        }
        i ++;
    }
}

void    rotate(t_data *fdf, int kc)
{
    if (kc == KA || kc == KD)
        rotate_z(fdf, 2 * (kc == KD) - 1);
    if (kc == KW && fdf->angle < 30)
        fdf->angle += 5;
    if (kc == KS && fdf->angle > -15)
        fdf->angle -= 5;
    if (fdf->view)
    {
        if (kc == KW && fdf->angle < 45)
            fdf->angle += 5;
        if (kc == KS && fdf->angle > -45)
            fdf->angle -= 5;
        paralel(fdf);
    }
    if (!fdf->view)
    {
        if (kc == KW && fdf->angle < 30)
            fdf->angle += 5;
        if (kc == KS && fdf->angle > -15)
            fdf->angle -= 5;
        isometric(fdf);
    }
}
