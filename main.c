/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:07:11 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/19 17:07:11 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-1.h"

int main(int ac, char **av)
{
    char    **grid;
    char    **flag;
    int     *startpoint;
    if (ft_checkarg(ac, av))
    {
        grid = ft_gridmalloc();
        ft_gridassign(grid, av);
        flag = ft_makeflagemptygrid(grid);
        startpoint = ft_findstart(grid);
        ft_solvegrid('+', '1', grid, flag, startpoint, 0, 0);
        free(startpoint);
        ft_freegrids(grid, flag);
    }
    return (0);
}
