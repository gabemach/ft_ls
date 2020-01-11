/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:53:30 by gmachado          #+#    #+#             */
/*   Updated: 2020/01/09 15:59:08 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "dirent.h"
# include "sys/stat.h"
# include "sys/types.h"

typedef struct  s_dir
{
    char            *name;
    struct s_dir    *next;    
}               t_dir;

typedef struct  s_ls
{
    char        *flags;
    char        active[5];
    char        *name;
    int         longest;
}               t_ls;

void    diver(t_ls *ls, struct dirent *dp);

#endif