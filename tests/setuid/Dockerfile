FROM ubuntu:18.04

COPY bash-root.c /

RUN DEBIAN_FRONTEND=noninteractive apt update && \
	DEBIAN_FRONTEND=noninteractive apt install -y gcc && \
	gcc -o /bash-root /bash-root.c && \
	chmod +s /bash-root
