#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

void make_child(int (*pipes)[2], int proc)
{
    int i;
    int j;
    int pid[proc];

    i = 0;
    j = 0;
    while (i < proc)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            j = 0;
            while (j < proc + 1)
            {
                if (j != i)
                    close(pipes[j][0]);
                if (j != i + 1)
                    close(pipes[j][1]);
                j++;
            }
            int x;
            read(pipes[i][0], &x, sizeof(int));
            x += 10;//manipulate av
            write(pipes[i + 1][1], &x, sizeof(int));
            close(pipes[i][0]);
            close(pipes[i + 1][1]);
            printf("Child %d-th wrote %d\n", i + 1, x);
            return;
        }
        i++;   
    }
    j = 0;
    while (j < proc + 1)
    {
        if (j != 0)
            close(pipes[j][1]);
        if (j != proc)
            close(pipes[j][0]);
        j++;
    }
    int y = 10;
    int sum;
    printf("Parent wrote %d\n", y);
    write(pipes[0][1], &y, sizeof(int)); //wirte av
    read(pipes[proc][0], &sum, sizeof(int));
    close(pipes[0][1]);
    close(pipes[proc][0]);
    i = 0;
    while (i < proc)
        waitpid(pid[i++], NULL, 0);
    printf("Total result : %d\n", sum);
}

int main(int ac, char *av[])
{
    int proc = ac - 3;
    int pipes[proc + 1][2];
    int pid[proc];
    int i;
    int j;

    proc = ac - 3;
    i = 0;
    while (i < proc + 1)
        pipe(pipes[i++]);
    make_child(&pipes[0], proc);
}