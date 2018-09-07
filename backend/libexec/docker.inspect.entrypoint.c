/* Requires suid as a user in the docker group for docker command to run */
/* Requires chown docker-user:docker and chmod ug+s to enable this */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
   int i;
   uid_t userid;
/* docker inspect -f '{{.Config.Entrypoint}}' $IMAGE  */

   /* fail if image name not specified */
   if (argc<2) {
    puts("Image name not specified");
    exit(1);
   }

/* Run template docker command */
   execl("/usr/bin/docker","docker","inspect",
    "-f","{{.Config.Entrypoint}}",
    argv[1],
    NULL);
    perror("docker command returned error");
    exit(EXIT_FAILURE);
}
