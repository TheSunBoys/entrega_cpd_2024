FROM docker.io/gcc:latest
WORKDIR /app
COPY ./main_openmp.c /app
COPY ../web-Google.txt.gz /app

RUN apt-get update && apt-get install -y zlib1g-dev && \
    gcc -o main_openmp main_openmp.c -fopenmp -lz

CMD ["./main_openmp", "web-Google.txt.gz"]

