/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

#include "shvm/exe.h"
#include "shvm/vm.h"

static int	exetest(char *exe)
{
	struct stat s;

	if (!*exe || lstat(exe, &s) < 0)
		return (PROC_NOTFOUND);
	if (!(s.st_mode & (S_IFREG | S_IXUSR)))
		return (PROC_NOTFOUND);
	if (S_ISDIR(s.st_mode))
		return (PROC_ISDIR);
	if (access(exe, X_OK) != 0)
		return (PROC_NORIGHTS);
	return (YEP);
}

static int	exelookuppath(char *pvar, char *exe, int rights, char *buf)
{
	char		*sep;
	size_t		len;
	uint32_t	i;
	int			st;

	while (1)
	{
		sep = ft_strchr(pvar, ':');
		len = sep ? (size_t)(sep - pvar) : ft_strlen(pvar);
		ft_strncpy(buf, pvar, len)[len] = '\0';
		if (!(st = exetest(ft_pathcat(buf, exe))) || st == PROC_NORIGHTS ||
			st == PROC_ISDIR)
		{
			ft_mapput(&g_shvm->binaries, ft_strdup(exe), &i);
			((char **)g_shvm->binaries.vals)[i] = ft_strdup(buf);
			return (st);
		}
		if (!sep)
			break ;
		pvar = sep + 1;
	}
	return (rights ? PROC_NORIGHTS : PROC_NOTFOUND);
}


int			shvm_exelookup(char *ev[], char *exe, char const *path, char *buf)
{
	int			st;
	int			rights;
	char		*beg;
	uint32_t	i;

	st = 0;
	if (ft_strlen(exe) > PATH_MAX)
		return (PROC_NOTFOUND);
	if (ft_strchr(exe, '/'))
		return (exetest(ft_strcpy(buf, exe)));
	beg = ft_getenv(ev, path);
	if (beg && !ft_strlen(beg) && !(st = exetest(ft_strcpy(buf, exe))))
		return (st);
	rights = st == PROC_NORIGHTS;
	if (!beg)
		return (PROC_NOTFOUND);
	if (ft_mapget(&g_shvm->binaries, exe, &i))
	{
		if (!(st = exetest(ft_strcpy(buf, ((char **)g_shvm->binaries.vals)[i])))
			|| st == PROC_NORIGHTS)
			return (st);
	}
	return (exelookuppath(beg, exe, rights, buf));
}
