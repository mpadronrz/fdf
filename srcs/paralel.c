#include "../includes/fdf.h"

static float   get_eff(float x)
{
    return (-x * x / 8100 + x / 60 + 1);
}

void    paralel(t_data *fdf)
{
    int i;
    int j;
    float   eff;
    float   c;
    float   s;

    i = 0;
    eff = get_eff(fdf->angle);
    c = ft_cos(45 - fdf->angle);
    s = ft_sin(45 - fdf->angle);
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].x = fdf->pt[i][j].ry - fdf->pt[i][j].rx * c;
            fdf->pt[i][j].y = fdf->pt[i][j].rz * eff - fdf->pt[i][j].rx * s;
            j ++;
        }
        i ++;
    }
    calculate_pixels(fdf);
}

void    begin_paralel(t_data *fdf)
{
    int i;
    int j;

    i = 0;
    fdf->view = 1;
    fdf->height = 1;
    fdf->angle = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].rx = i - fdf->rows / 2.0;
            fdf->pt[i][j].ry = j - fdf->cols / 2.0;
            fdf->pt[i][j].rz = fdf->z[i][j];
            j ++;
        }
        i ++;
    }
    fdf->zoom = 4 * 120 / ((fdf->cols + fdf->rows - 2) * sqrt(3.0));
    paralel(fdf);
}