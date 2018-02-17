/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/exe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_EXE_H
# define SHVM_EXE_H

# include <libft.h>

# define PROC_NOTFOUND (127)
# define PROC_NORIGHTS (126)
# define PROC_ISDIR (1)

extern int	shvm_exelookup(char *ev[], char *exe, char const *path, char *buf);

#endif
