   /* hack to add project groups */
    sprintf(g1,"%d",41000001);
    sprintf(g2,"%d",getgid());
    sprintf(g3,"%d",getgid());
    sprintf(g4,"%d",getgid());
    sprintf(g5,"%d",getgid());
    sprintf(g6,"%d",getgid());
    sprintf(g7,"%d",getgid());
    userid=getuid();
#ifdef DEBUG
   printf("userid: %d\n",userid);
#endif


    if (userid==20888) {
#ifdef DEBUG
   printf("add group 114034(h-precision) to 20888(seramani)\n");
#endif
     sprintf(g2,"%d",114034);
    }
    if (userid==21525) {
#ifdef DEBUG
   printf("add group 11000481 to 21525(e0021555)\n");
#endif
     sprintf(g2,"%d",11000481);
    }
    if (userid==21505) {
#ifdef DEBUG
   printf("add group 11000481 to 21505(elenguy)\n");
#endif
     sprintf(g2,"%d",11000481);
    }
    if (userid==23066) {
#ifdef DEBUG
   printf("add group 13000026 to 23066(foocs)\n");
#endif
     sprintf(g2,"%d",13000026);
    }
    if (userid==21287) {
#ifdef DEBUG
   printf("add group 115034 to 21287(liuyong)\n");
#endif
     sprintf(g2,"%d",115034);
     sprintf(g3,"%d",13000026);
     sprintf(g4,"%d",14000374);
    }
    if (userid==21750) {
#ifdef DEBUG
   printf("add group 14000374 to 21750(dujw)\n");
#endif
     sprintf(g2,"%d",14000374);
    }
    if (userid==10285) {
#ifdef DEBUG
   printf("add group 11001045 to 10285(ngiamky)\n");
#endif
     sprintf(g2,"%d",11001045);
    }
    if (userid==22050) {
#ifdef DEBUG
   printf("add group 11001045 to 22050(surmsf)\n");
#endif
     sprintf(g2,"%d",11001045);
    }

    if (userid==10714) {
#ifdef DEBUG
   printf("add non-stakeholder and group 11001045 to 10714(yuwono)\n");
#endif
     sprintf(g1,"%d",22270170);
     sprintf(g2,"%d",11001045);
    }
    if (userid==10716) {
#ifdef DEBUG
   printf("add non-stakeholder group to 10716(dso_01)\n");
#endif
     sprintf(g1,"%d",22270170);
    }

    if (userid==11013) {
#ifdef DEBUG
   printf("add group 110029(nscc-proj) and 21170165(datathon) to 11013(fsg3)\n");
#endif
     sprintf(g2,"%d",110029);
     sprintf(g3,"%d",21170165);
    }
    if (userid==22892) {
#ifdef DEBUG
   printf("add group 110029(nscc-proj) and 21170165(datathon) to 22892(chiapi)\n");
#endif
     sprintf(g2,"%d",110029);
     sprintf(g3,"%d",21170165);
    }
    if (userid==22610) {
#ifdef DEBUG
   printf("add group 110029(nscc-proj) and 21170165(datathon) to 22610(jamesche)\n");
#endif
     sprintf(g2,"%d",110029);
     sprintf(g3,"%d",21170165);
    }
    if (userid==20762) {
#ifdef DEBUG
   printf("add group 110029(nscc-proj) and 21170165(datathon) to 20762(hiewnh)\n");
#endif
     sprintf(g2,"%d",110029);
     sprintf(g3,"%d",21170165);
    }


    if (userid==20806) {
#ifdef DEBUG
   printf("add datathon group and 11000727 to 20806(bchbhkk)\n");
#endif
     sprintf(g2,"%d",21170165);
     sprintf(g3,"%d",11000727);
    }


    if (userid==10655) {
#ifdef DEBUG
   printf("remove default pilot group from 10655(pengzhiz)\n");
#endif
     sprintf(g1,"%d",getgid());
    }

    if (userid==23721) {
#ifdef DEBUG
   printf("add datathon group to 23721(e0179756)\n");
#endif
     sprintf(g2,"%d",21170165);
    }
    if (userid==23753) {
#ifdef DEBUG
   printf("add datathon group to 23753(e0267385)\n");
#endif
     sprintf(g2,"%d",21170165);
    }


    if (userid==21399) {
#ifdef DEBUG
   printf("add groups 11000727(11000727) for user 21399(e0056351)\n");
#endif
     sprintf(g2,"%d",11000727);
    }

    if (userid==20825) {
#ifdef DEBUG
   printf("add groups 100000(gpu-gromacs),13000289(13000289),13000391(13000391),13000394(13000394),14000702(14000702),13000751(13000751) to 20825(zidarj)\n");
#endif
     sprintf(g2,"%d",100000);
     sprintf(g3,"%d",13000289);
     sprintf(g4,"%d",13000391);
     sprintf(g5,"%d",13000394);
     sprintf(g6,"%d",14000702);
     sprintf(g7,"%d",13000751);
    }
