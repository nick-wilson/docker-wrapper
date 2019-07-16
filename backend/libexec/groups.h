           ngroups = 20;

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

           sprintf(gidstr00,"%d",groups[0]);
           sprintf(gidstr01,"%d",groups[1]);
           sprintf(gidstr02,"%d",groups[2]);
           sprintf(gidstr03,"%d",groups[3]);
           sprintf(gidstr04,"%d",groups[4]);
           sprintf(gidstr05,"%d",groups[5]);
           sprintf(gidstr06,"%d",groups[6]);
           sprintf(gidstr07,"%d",groups[7]);
           sprintf(gidstr08,"%d",groups[8]);
           sprintf(gidstr09,"%d",groups[9]);
           sprintf(gidstr10,"%d",groups[10]);
           sprintf(gidstr11,"%d",groups[11]);
           sprintf(gidstr12,"%d",groups[12]);
           sprintf(gidstr13,"%d",groups[13]);
           sprintf(gidstr14,"%d",groups[14]);
           sprintf(gidstr15,"%d",groups[15]);
           sprintf(gidstr16,"%d",groups[16]);
           sprintf(gidstr17,"%d",groups[17]);
           sprintf(gidstr18,"%d",groups[18]);
           sprintf(gidstr19,"%d",groups[19]);
