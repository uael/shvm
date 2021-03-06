/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/bi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_BI_H
# define SHVM_BI_H

# include <libft.h>

typedef int		(t_bi)(int ac, char *av[], char *ev[]);

extern void		shvm_biregister(char const *name, t_bi *bi);

extern int		shvm_bibg(int ac, char **av, char **env);
extern int		shvm_bifg(int ac, char **av, char **env);
extern int		shvm_bijobs(int ac, char **av, char **env);

extern int		shvm_biunsetenv(int ac, char **av, char **env);
extern int		shvm_bienv(int ac, char **av, char **env);
extern int		shvm_bisetenv(int ac, char **av, char **env);
extern int		shvm_biunset(int ac, char **av);
extern int		shvm_biexport(int ac, char **av, char **env);

#endif
