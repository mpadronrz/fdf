#include "../includes/fdf.h"

//void    rotate_iso_xy(t_data *fdf, int kc);

void    rotate_iso_z(t_data *fdf, int kc)
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
            y = fdf->pt[i][j].y;
            fdf->pt[i][j].x = x * cos(s * AL) + sqrt(3.0) * (fdf->z[i][j] * fdf->height - y) * sin(s * AL);
            fdf->pt[i][j].y = x * sin(s * AL) / sqrt(3.0) - (fdf->z[i][j] * fdf->height - y) * cos(s * AL) + fdf->z[i][j] * fdf->height;
            j ++;
        }
        i ++;
    }
}

void    rotate(t_data *fdf, int kc)
{
    //if (!fdf->view && (kc == KW || kc == KS))
        //rotate_iso_xy(fdf, kc);
    if (!fdf->view && (kc == KD || kc == KA))
        rotate_iso_z(fdf, kc);
    calculate_pixels(fdf);
}
