/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvegrid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:48:26 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/19 23:48:26 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-1.h"
// #include <stdio.h>
// printf("flag: %c, dir: %c, num: %c, grid: %c, r: %d, c: %d\n", flag[r][c], dir, num, grid[r][c], r, c);

void    ft_solvegrid(char dir, char num, char **grid, char **flag, int *startpoint, int r, int c)
{
    while (r < 9)
    {
        if (flag[r][c] == '1')
        {
            num = ft_testnum(dir, num, grid, r, c);
            if (num == '0')
                ft_backtrack(&dir, &num, grid, flag, startpoint, &r, &c);
            else
                ft_updategrid(&dir, &num, grid, flag, &r, &c);
        }
        else if (flag[r][c] == '0')
        {
            if (dir == '-')
                ft_backtrack(&dir, &num, grid, flag, startpoint, &r, &c);
            else
                ft_updategrid(&dir, &num, grid, flag, &r, &c);
        }
        if (c == 9)
        {
            r++;
            c = 0;
        }
    }
    ft_printgrid(grid);
}

char    ft_testnum(char dir, char num, char **grid, int r, int c)
{
    if (dir == '-')
        num++;
    while (num <= '9')
    {
        if (ft_isvalid(num, grid, r, c))
            return (num);
        num++;
    }
    return ('0');
}

void    ft_updategrid(char *dir, char *num, char **grid, char **flag, int *r, int *c)
{
    if (flag[*r][*c] == '1')
        grid[*r][*c] = *num;
    *dir = '+';
    *num = '1';
    (*c)++;
}

void    ft_backtrack(char *dir, char *num, char **grid, char **flag, int *startpoint, int *r, int *c)
{            
    if (*r == startpoint[0] && *c == startpoint[1] && *num == '0')
    {
        ft_putstr("No existing solution");
        exit(0);
    }
    else
    {
        if (flag[*r][*c] == '1')
            grid[*r][*c] = '.';
        if (*c == 0 && *r != 0)
        {
            (*r)--;
            *c = 8;
        }
        else
            (*c)--;
        *num = grid[*r][*c];
        *dir = '-';
    }
}

int *ft_findstart(char **grid)
{
    int     y;
    int     x;
    int     *startpoint;

    y = 0;
    startpoint = malloc(sizeof(int) * 2);
    while (y < 9)
    {
        x = 0;
        while (x < 9)
        {
            if (grid[y][x] == '.')
            {
                startpoint[0] = y;
                startpoint[1] = x;
                return (startpoint);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int     ft_isvalid(char n, char **grid, int r, int c)
{
    if (!ft_checkcol(n, grid, r, c))
        return (0);
    if (!ft_checkrow(n, grid, r, c))
        return (0);
    if (!ft_checksub(n, grid, r, c))
        return (0);
    return (1);
}

int     ft_checkcol(char n, char **grid, int r, int c)
{
    int count;

    count = 0;
    while (count < 9)
    {
        if (grid[count][c] == n && count != r)
            return (0);
        count++;
    }
    return (1);
}

int     ft_checkrow(char n, char **grid, int r, int c)
{
    int count;

    count = 0;
    while (count < 9)
    {
        if (grid[r][count] == n && count != c)
            return (0);
        count++;
    }
    return (1);
}

int     ft_checksub(char n, char **grid, int r, int c)
{
    int r_start;
    int c_start;
    int r_end;
    int c_end;

    r_start = (r / 3) * 3;
    c_start = (c / 3) * 3;
    r_end = r_start + 3;
    c_end = c_start + 3;
    while (r_start < r_end)
    {
        c_start = (c / 3) * 3;
        while(c_start < c_end)
        {
            if (grid[r_start][c_start] == n && r_start != r && c_start != c)
                return (0);
            c_start++;
        }
        r_start++;
    }
    return (1);
}
