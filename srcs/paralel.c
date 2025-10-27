#include "../includes/fdf.h"

void    paralel(t_data *fdf)
{
    int i;
    int j;

    i = 0;
    fdf->view = 1;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].x = j - i * sqrt(2.0) / 2;
            fdf->pt[i][j].y = fdf->z[i][j] - i * sqrt(2.0) / 2.0;
            j ++;
        }
        i ++;
    }
    fdf->mid.x = (fdf->cols - 1) / 2.0 - (fdf->rows - 1) * sqrt(2.0) / 4.0;
    fdf->mid.y = - (fdf->rows - 1) * sqrt(2.0) / 4.0;
    fdf->zoom = 4 * 120 / ((fdf->cols + fdf->rows - 2) * sqrt(3.0));
    if (fdf->zoom > -270 / fdf->mid.y)
        fdf->zoom = -65 / fdf->mid.y;
    calculate_pixels(fdf);
}