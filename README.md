# PipeX
pipex is about creating pipe, the programe behave exactly the same as the shell command:  
**`$> < file1 cmd1 | cmd2 > file2`** 

## to compile the program follow the steps:  
1. Clone this repository to your working directory.  
2. Use 'make' : compile the mandatory part (1 pipe).  
3. Use 'make bonus' : compile the bonus part (multiple pipes). 

## execute the program as follow:

### This:
**`$> ./pipex file1 cmd(1) cmd(2) cmd(3) ... cmd(n) file2`**

### Behave like this:
**`$> < file1 cmd(1) | cmd(2) | cmd(3) | ... | cmd(n) > file2`**

### Support parameters << and >> when the first parameter is "here_doc":
**`$> ./pipex here_doc LIMITER cmd(1) cmd(2) cmd(3) ... cmd(n) file`**

### Behave like this:
**`$> cmd(1) << LIMITER | cmd(2) | cmd(3) ... | cmd(n) >> file`**





