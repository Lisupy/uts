FROM ubuntu:18.04
LABEL maintianer="Lisupy"
LABEL description="This is the building docker images for uts"

RUN apt-get clean && apt-get update -y && \
    apt-get install -y build-essential cmake && \
    apt-get clean

RUN locale-gen en_US.UTF-8 && \
    echo 'export LANG=en_US.UTF-8' >> /root/.bashrc && \
    echo 'export LC_ALL=en_US.UTF-8' >> /root/.bashrc

ENTRYPOINT [ "/bin/bash" ]