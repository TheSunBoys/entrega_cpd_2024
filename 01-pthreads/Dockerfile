FROM docker.io/gcc:latest
WORKDIR /app
COPY main_pthreads.c /app
COPY ../web-Google.txt.gz /app

RUN apt-get update && apt-get install -y zlib1g-dev && \
    gcc -o main_pthreads main_pthreads.c -lpthread -lz

CMD ["./main_pthreads", "web-Google.txt.gz"]

