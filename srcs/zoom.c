#include "../includes/fdf.h"

void    zoom(t_data *fdf, int t)
{
    if (fdf->zoom < 1000 && t)
    {
        if (fdf->zoom < 10)
            fdf->zoom ++;
        else
            fdf->zoom *= 1.2;
        calculate_pixels(fdf);
    }
    else if (fdf->zoom > 1 && !t)
    {
        fdf->zoom /= 1.2;
        calculate_pixels(fdf);
    }
}