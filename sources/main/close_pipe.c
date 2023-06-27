#include "pipex.h"
#include <unistd.h>

void close_infile(t_data *data, int i)
{
    int j;

    j = 0;
    while(j < data->pipe_nb)
    {
        if(j != 0)
            close(data->pipes[j][1]);
        close(data->pipes[j][0]);
        j++;
    }
}

void close_child(t_data *data, int i)
{
    int j;

    j = 0;
    while(j < data->pipe_nb)
    {
        if(j != i - 1)
            close(data->pipes[j][0]);
        if(j != i + 1)
            close(data->pipes[j][1]);
        j++;
    }
}

void close_outfile(t_data *data, int i)
{
    int j;

    j = 0;
    while(j < data->pipe_nb)
    {
        if(j != i - 1)
            close(data->pipes[j][0]);
        close(data->pipes[j][1]);
        j++;
    }
}