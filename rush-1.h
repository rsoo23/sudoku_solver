/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:07:04 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/19 17:07:04 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

#include <unistd.h>
#include <stdlib.h>

// main.c
int     main(int ac, char **av);
// ft_std.c
void    ft_putstr(char *str);
// ft_grid.c
char    **ft_gridmalloc(void);
void    ft_gridassign(char **grid, char **av);
void    ft_printgrid(char **grid);
char     **ft_makeflagemptygrid(char **grid);
int     *ft_findstart(char **grid);
// ft_solvegrid.c
void    ft_solvegrid(char dir, char num, char **grid, char **flag, int *startpoint, int r, int c);
void    ft_reachrowend(char **grid, char **flag, int *startpoint, int r, int c);
int     ft_isvalid(char n, char **grid, int r, int c);
int     ft_checkrow(char n, char **grid, int r, int c);
int     ft_checkcol(char n, char **grid, int r, int c);
int     ft_checksub(char n, char **grid, int r, int c);

// ft_errorhandling.c
int     ft_checkarglen(char **av);
int     ft_checkarg(int ac, char **av);

#endif
 
