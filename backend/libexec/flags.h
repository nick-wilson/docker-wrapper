#ifdef USE_LUSTRE
flags[0]='1';
#else
flags[0]='0';
#endif
#ifdef USE_TTY
flags[1]='1';
#else
flags[1]='0';
#endif
#ifdef USE_NET_HOST
flags[2]='1';
#else
flags[2]='0';
#endif
#ifdef USE_IPC_HOST
flags[3]='1';
#else
flags[3]='0';
#endif
#ifdef USE_PORTS
flags[4]='1';
#else
flags[4]='0';
#endif
#ifdef USE_PID_HOST
flags[5]='1';
#else
flags[5]='0';
#endif
flags[6]='\0';
