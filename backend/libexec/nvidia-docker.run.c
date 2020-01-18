/* Requires suid as a user in the docker group for nvidia-docker command to run */
/* Requires chown docker-user:docker and chmod ug+s to enable this */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
int main(int argc, char *argv[])
{
   char uidstr[128];
   char gidstr00[128];
   char gidstr01[128];
   char gidstr02[128];
   char gidstr03[128];
   char gidstr04[128];
   char gidstr05[128];
   char gidstr06[128];
   char gidstr07[128];
   char gidstr08[128];
   char gidstr09[128];
   char gidstr10[128];
   char gidstr11[128];
   char gidstr12[128];
   char gidstr13[128];
   char gidstr14[128];
   char gidstr15[128];
   char gidstr16[128];
   char gidstr17[128];
   char gidstr18[128];
   char gidstr19[128];
   int j, ngroups;
   gid_t *groups;
   struct passwd *pw;
   int i;
   uid_t userid;
   char cont_name[128];
   char nvidia_devices[1024];
   FILE *LOGFILE;
   time_t t;
   struct tm *tmp;
   char timestr[200];
   char flags[10];
   char hostname[1024];
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
   if (argc<4) {
    puts("Devices not specified");
    exit(1);
   }
#ifdef USE_LUSTRE
   if (argc<5) {
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

   /* Pass visible devices to Docker so they match inside and outside container */
   sprintf(nvidia_devices,"NVIDIA_VISIBLE_DEVICES=%s",argv[3]);

  /* log details */
#include "flags.h"
  LOGFILE=fopen("/var/log/container","a");
  if (LOGFILE!=NULL){
    t=time(NULL);
    tmp=localtime(&t);
    strftime(timestr, sizeof(timestr),"%Y-%m-%d %H:%M:%S",tmp);
    gethostname(hostname,sizeof(hostname));
    fprintf(LOGFILE,"%s %s %s %s %s %s\n",timestr,hostname,pw->pw_name,argv[1],argv[2],flags);
    fclose(LOGFILE);
  }

/* Run template docker command */
   execl("/usr/bin/docker","docker","run",
    "--runtime=nvidia",
    "-e",nvidia_devices,
    "-u",uidstr,
    "--group-add",gidstr00,
    "--group-add",gidstr01,
    "--group-add",gidstr02,
    "--group-add",gidstr03,
    "--group-add",gidstr04,
    "--group-add",gidstr05,
    "--group-add",gidstr06,
    "--group-add",gidstr07,
    "--group-add",gidstr08,
    "--group-add",gidstr09,
    "--group-add",gidstr10,
    "--group-add",gidstr11,
    "--group-add",gidstr12,
    "--group-add",gidstr13,
    "--group-add",gidstr14,
    "--group-add",gidstr15,
    "--group-add",gidstr16,
    "--group-add",gidstr17,
    "--group-add",gidstr18,
    "--group-add",gidstr19,
    "-v","/raid:/raid",
    "-v","/home:/home",
#ifndef USE_LUSTRE
    "-v","/scratch:/scratch",
#endif
    "-v","/var/run/etc.passwd:/etc/passwd:ro",
    "-v","/var/run/etc.group:/etc/group:ro",
    "-v","/etc/localtime:/etc/localtime:ro",
    "--rm","-i",
    "--cap-drop","all",
    cont_name,
#include "options.h"
#ifdef USE_LUSTRE
    "-v","DDN-Lustre-vol:/ddn:ro",
    "--device=/dev/lnet:/dev/lnet",
    "--entrypoint=/ddn/scripts/entry_lustre.sh",
    "--net=host",
    argv[1],
    "1",
    argv[4],
#else
    argv[1],
#endif
    NULL);
    perror("docker command returned error");
    exit(EXIT_FAILURE);
}

/* TODO */
/* 1. Improve secondary groups to allow arbitrary number */
/* 2. Perform input validation */
/* 3. Allow user to set other parameters (--shm-size etc.) */
/* 4. Allow user to specify command to run rather than /bin/sh */
/* 5. Only use docker volumes for user's $HOME and project directories rather than mount all of home */
