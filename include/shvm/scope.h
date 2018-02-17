/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/scope.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_SCOPE_H
# define SHVM_SCOPE_H

# include <libft.h>

typedef struct	s_scope
{
	int			ac;
	char		*av[];
	int			status;
	pid_t		pid;
	t_bool		tty;
}				t_scope;

extern void		shvm_scopector(t_scope *scope, int fd, int ac, char *av[]);

#endif
