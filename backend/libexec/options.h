#ifdef USE_IPC_HOST
    "--ipc=host",
#else
    "--shm-size=1g",
#endif
    "--ulimit","memlock=-1","--ulimit","stack=67108864",
#ifdef USE_NET_HOST
    "--net=host",
#endif
#ifdef USE_PORTS
    "-p","1024-9999:1024-9999",
/*
    "-p","5901:5901",
    "-p","5902:5902",
    "-p","5903:5903",
    "-p","5904:5904",
    "-p","5905:5905",
    "-p","5906:5906",
    "-p","5907:5907",
    "-p","5908:5908",
    "-p","5909:5909",
    "-p","6006:6006",
    "-p","8888:8888",
*/
#endif
#ifdef USE_TTY
    "-t",
#endif
#ifdef USE_PID_HOST
    "--pid=host",
#endif
