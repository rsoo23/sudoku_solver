/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:34:05 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/19 23:34:05 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-1.h"

char    **ft_gridmalloc(void)
{
    char    **grid;
    int     y;

    y = 0;
    grid = malloc(sizeof(char*) * 10);
    while (y < 9)
    {
        grid[y] = malloc(sizeof(char) * 10);
        y++;
    }
    return (grid);
}

void    ft_freegrids(char **grid, char **flag)
{
    int     y;

    y = 0;
    while (y < 9)
    {
        free(grid[y]);
        free(flag[y]);
        y++;
    }
}

void    ft_gridassign(char **grid, char **av)
{
    int     x;
    int     y;

    y = 0;
    while (y < 9)
    {
        x = 0;
        while (x < 9)
        {
            grid[y][x] = av[y + 1][x];
            x++;
        }
        y++;
    }
}

char **ft_makeflagemptygrid(char **grid)
{
    char **flag;
    int y;
    int x;
    
    y = 0;
    flag = ft_gridmalloc();
    while (y < 9)
    {
        x = 0;
        while (x < 9)
        {
            if (grid[y][x] == '.')
                flag[y][x] = '1';
            else
                flag[y][x] = '0';
            x++;
        }
        y++;
    }
    return (flag);
}

void    ft_printgrid(char **grid)
{
    int x;
    int y;

    y = 0;
    while (y < 9)
    {
        x = 0;
        while (x < 9)
        {
            write(1, &grid[y][x], 1);
            write(1, " ", 1);
            x++;
        }
        write(1, "\n", 1);
        y++;
    }
}
