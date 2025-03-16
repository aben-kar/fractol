#include "fractol.h"

double  ft_atof(char *s)
{
    double  ret;
    char    **sn;
    
    ret = 0.0;
    if (!s)
        return (0);
    if (!ft_strchr(s, '.'))
        return (ft_atoi(s));
    sn = ft_split(s, '.');
    if (sn[0][0] != '-')
        ret = ft_atoi(sn[0]) + (ft_atoi(sn[1]) / pow(10, ft_strlen(sn[1])));
    else if (sn[0][0] == '-')
        ret = ft_atoi(sn[0]) - (ft_atoi(sn[1]) / pow(10, ft_strlen(sn[1])));
    free(sn[0]);
    free(sn[1]);
    free(sn);
    return (ret);
}

void event_julia(t_fractol *fractol)
{
    mlx_hook(fractol->cree_wind, 02, 1L<<0, key_handel_julia, fractol);
    mlx_hook(fractol->cree_wind, 04, 1L<<2, mouse_handel_julia, fractol);
    mlx_hook(fractol->cree_wind, 17, 1L<<17, close_handel_julia, fractol);
}