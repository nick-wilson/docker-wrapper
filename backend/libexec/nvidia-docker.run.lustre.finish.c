/* Requires suid as a user in the docker group for nvidia-docker command to run */
/* Requires chown docker-user:docker and chmod ug+s to enable this */

/* docker run --rm --privileged --pid=host -v $VOLUME:/ddn --entrypoint=/ddn/scripts/nsenter.sh $IMAGE $cont_pid /ddn/scripts/finish_lustre_when_done.sh */
/* /usr/local/sbin/nvidia-docker.run.lustre.finish $IMAGE $cont_pid */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
   int i;
   uid_t userid;
   char cont_name[128];

   /* fail if image not specified */
   if (argc<2) {
    puts("Image not specified");
    exit(1);
   }

   if (argc<3) {
    puts("Container name not specified");
    exit(1);
   }

   if (argc<4) {
    puts("Container PID not specified");
    exit(1);
   }
   /* Container name used to track username and job ID and so that docker inspect used by Lustre will work */
   sprintf(cont_name,"--name=%s",argv[2]);

/* Run template docker command */
   execl("/usr/bin/docker","docker","run",
    "--rm",
    "--privileged",
    "--pid=host",
    "-v","DDN-Lustre-vol:/ddn",
    "--entrypoint=/ddn/scripts/nsenter.sh",
    cont_name,
    argv[1],
    argv[3],
    "/ddn/scripts/finish_lustre_when_done.sh",
    NULL);
    perror("docker command returned error");
    exit(EXIT_FAILURE);
}
