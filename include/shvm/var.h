/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/var.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_VAR_H
# define SHVM_VAR_H

# include <libft.h>

extern char		*shvm_varget(char const *var, char **ev);
extern void		shvm_varset(char const *var, char const *val);
extern t_bool	shvm_varunset(char const *var);
extern int		shvm_vardump(int fd, char **ev);

#endif
