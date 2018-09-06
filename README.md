# User restriction of Docker

Utilty to allow users to run Docker containers without being in docker group.

An suid wrapper allows users to launch specific templated "docker run" commands.

Utility consists of 2 parts:
 * Front-end script to parse command line, apply defaults
 * suid wrapper to run specific Docker commands

