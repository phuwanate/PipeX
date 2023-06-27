/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:32:16 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/23 17:48:17 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_data
{
	int			**pipes;
	int			*pid;
	int			pipe_nb;
	int			proc;
	int			status;
}				t_data;

int		find_path(const char *s1);
void	force_quit(int nb);
char	**split_path(char *str, char c);
void	get_path(char **envp, char **split_av)
char	**get_cmd(char *av);
void	free_2d(char **ptr);
void	go_exec(char *path, char **split_av, char **envp);
void	cmd_err(char *split_av);
void	param_error(char **split_av);
void	open_file(int proc_id, char *av, t_data *data);
void	data_status(t_data *data, int nb, int ac);

#endif