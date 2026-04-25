FROM ubuntu:latest
COPY . /app
WORKDIR /app
RUN apt update
RUN apt install -y clang
RUN clang++ main.cpp -o test
CMD ["./test"]
