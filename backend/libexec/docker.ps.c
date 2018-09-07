/* Requires suid as a user in the docker group for docker command to run */
/* Requires chown docker-user:docker and chmod ug+s to enable this */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
#ifdef DEBUG
   /* whoami */
   printf("uid=%d\n",getuid());
   printf("euid=%d\n",geteuid());
   printf("gid=%d\n",getgid());
   printf("egid=%d\n",getegid());
#endif

/* Run template docker command */
   execl("/usr/bin/docker","docker","ps",NULL);
   perror("docker command returned error");
   exit(EXIT_FAILURE);
}

