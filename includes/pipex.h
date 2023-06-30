/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:32:16 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/30 18:36:32 by plertsir         ###   ########.fr       */
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
void	get_path(char **envp, char **split_av);
char	**get_cmd(char *av);
void	free_2d(char **ptr);
void	int_free_2d(int **ptr, int size);
void	go_exec(char *path, char **split_av, char **envp);
void	cmd_err(char *split_av);
void	param_error(char **split_av);
void	open_file(int proc_id, char **av, int ac);
void	data_status(t_data *data, int nb_proc, int ac);
void	close_infile(t_data *data, int id);
void	close_child(t_data *data, int id);
void	close_outfile(t_data *data, int id);
void	close_pipe_main(t_data *data);
void	infile_error(char *in_file);
void	path_error(char *path);
void	free_mem(t_data *data);
void	fork_error(t_data *data);

#endif