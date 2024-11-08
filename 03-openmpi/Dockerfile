FROM docker.io/openmpi/openmpi:latest
WORKDIR /app
COPY ./main_openmpi.c /app
COPY ../web-Google.txt.gz /app

RUN apt-get update && apt-get install -y zlib1g-dev && \
    mpicc -o main_openmpi main_openmpi.c -lz

CMD ["mpirun", "-np", "4", "./main_openmpi", "web-Google.txt.gz"]

