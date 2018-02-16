/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/env.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_ENV_H
# define SHVM_ENV_H

# include <libft.h>

extern char		*shvm_envget(char const *var);
extern void		shvm_envset(char const *var, char const *val);
extern t_bool	shvm_envunset(char const *var);
extern void		shvm_envdump(int fd);

#endif
