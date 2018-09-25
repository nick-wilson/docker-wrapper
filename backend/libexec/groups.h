           ngroups = 7;

           groups = malloc(ngroups * sizeof (gid_t));
           if (groups == NULL) {
               perror("malloc");
               exit(EXIT_FAILURE);
           }

           /* Fetch passwd structure (contains first group ID for user) */

           pw = getpwuid(getuid()); 
           if (pw == NULL) {
               perror("getpwnam");
               exit(EXIT_SUCCESS);
           }

           /* Initialise group list to all be GID*/
           for (j = 0; j < ngroups; j++) {groups[j]=pw->pw_gid;}

           /* Retrieve group list */
           if (getgrouplist(pw->pw_name, pw->pw_gid, groups, &ngroups) == -1) {
               fprintf(stderr, "getgrouplist() returned -1; ngroups = %d\n",
                       ngroups);
               exit(EXIT_FAILURE);
           }

           sprintf(gidstr0,"%d",groups[0]);
           sprintf(gidstr1,"%d",groups[1]);
           sprintf(gidstr2,"%d",groups[2]);
           sprintf(gidstr3,"%d",groups[3]);
           sprintf(gidstr4,"%d",groups[4]);
           sprintf(gidstr5,"%d",groups[5]);
           sprintf(gidstr6,"%d",groups[6]);
/*
           printf("%d\n", groups[0]);
           printf("%d\n", groups[1]);
           printf("%d\n", groups[2]);
           printf("%d\n", groups[3]);
           printf("%d\n", groups[4]);
           printf("%d\n", groups[5]);
           printf("%d\n", groups[6]);
*/
