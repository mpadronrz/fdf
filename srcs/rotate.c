#include "../includes/fdf.h"

void    rotate_par(t_data *fdf, int kc)
{
    float   x;
    float   y;
    int     s;
    int     i;
    int     j;

    s = 2 * (kc == KD) - 1;
    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            x = 2 * (fdf->z[i][j] * fdf->height - fdf->pt[i][j].y) / sqrt(2.0);
            y = fdf->pt[i][j].x + sqrt(2.0) * x / 2.0;
            fdf->pt[i][j].x = sin(s * AL) * (x + sqrt(2.0) * y / 2) + cos(s * AL) * (y - sqrt(2.0) * x / 2);
            fdf->pt[i][j].y = fdf->z[i][j] * fdf->height + sin(s * AL) * sqrt(2.0) * y / 2 - cos(s * AL) * sqrt(2.0) * x / 2;
            j ++;
        }
        i ++;
    }
}

void    rotate_iso(t_data *fdf, int kc)
{
    float   x;
    float   y;
    int     s;
    int     i;
    int     j;

    s = 2 * (kc == KD) - 1;
    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            x = fdf->pt[i][j].x;
            y = fdf->z[i][j] * fdf->height - fdf->pt[i][j].y;
            fdf->pt[i][j].x = x * cos(s * AL) + sqrt(3.0) * y * sin(s * AL);
            fdf->pt[i][j].y = x * sin(s * AL) / sqrt(3.0) - y * cos(s * AL) + fdf->z[i][j] * fdf->height;
            j ++;
        }
        i ++;
    }
}

void    rotate(t_data *fdf, int kc)
{
    if (fdf->view)
        rotate_par(fdf, kc);
    if (!fdf->view)
        rotate_iso(fdf, kc);
    calculate_pixels(fdf);
}
