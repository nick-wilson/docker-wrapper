/* Requires suid as a user in the docker group for nvidia-docker command to run */
/* Requires chown docker-user:docker and chmod ug+s to enable this */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
int main(int argc, char *argv[])
{
   char uidstr[128];
   char gidstr0[128];
   char gidstr1[128];
   char gidstr2[128];
   char gidstr3[128];
   char gidstr4[128];
   char gidstr5[128];
   char gidstr6[128];
   int j, ngroups;
   gid_t *groups;
   struct passwd *pw;
   int i;
   uid_t userid;
   char cont_name[128];
/*   clearenv();*/
   /* fail if image not specified */
   if (argc<2) {
    puts("Image not specified");
    exit(1);
   }
   if (argc<3) {
    puts("Container name not specified");
    exit(1);
   }
#ifdef USE_LUSTRE
   if (argc<4) {
    puts("Entrypoint not specified");
    exit(1);
   }
#endif

   /* put UID and GID of user calling command into format for argument for docker command */
   sprintf(uidstr,"%d:%d",getuid(),getgid());

   /* get list of supplementary groups */
#include "groups.h"

   /* Container name used to track username and job ID and so that docker inspect used by Lustre will work */
   sprintf(cont_name,"--name=%s",argv[2]);

/* Run template docker command */
   execl("/usr/bin/nvidia-docker","nvidia-docker","run",
    "-u",uidstr,
    "--group-add",gidstr0,
    "--group-add",gidstr1,
    "--group-add",gidstr2,
    "--group-add",gidstr3,
    "--group-add",gidstr4,
    "--group-add",gidstr5,
    "--group-add",gidstr6,
    "-v","/raid:/raid",
    "-v","/home:/home",
    "--rm","-i",
    cont_name,
#include "options.h"
#ifdef USE_LUSTRE
    "-v","DDN-Lustre-vol:/ddn",
    "--entrypoint=/ddn/scripts/entry_lustre.sh",
    "--net=host",
    argv[1],
    argv[3],
#else
    argv[1],
    "/bin/sh",
#endif
    NULL);
    perror("nvidia-docker command returned error");
    exit(EXIT_FAILURE);
}

/* TODO */
/* 1. Secondary groups with --group-add */
/* 2. Perform input validation */
/* 3. Allow user to set other parameters (--shm-size etc.) */
/* 4. Allow user to specify command to run rather than /bin/sh */
/* 5. Only use docker volumes for user's $HOME and project directories rather than mount all of home */
/* 6. logging who, when, what */
/* 7. export HOME, USER, LOGNAME and other environment variables */
