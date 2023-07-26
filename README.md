# PipeX
Pipex is about creating pipe, the programe behave exactly the same as the shell command:  
**`$> < file1 cmd1 | cmd2 > file2`** 

## Follow the steps below:  
1. Clone this repository to your working directory.  
2. Use `make` to compile the mandatory part (support 1 pipe).  
3. Use `make bonus` to compile the bonus part (support multiple pipes). 

## Execute the program as follow:

### This:
**`$> ./pipex file1 cmd(1) cmd(2) cmd(3) ... cmd(n) file2`**

### Behave like this:
**`$> < file1 cmd(1) | cmd(2) | cmd(3) | ... | cmd(n) > file2`**

### Support parameters << and >> when the first parameter is "here_doc":
**`$> ./pipex here_doc LIMITER cmd(1) cmd(2) cmd(3) ... cmd(n) file`**

### Behave like this:
**`$> cmd(1) << LIMITER | cmd(2) | cmd(3) ... | cmd(n) >> file`**





