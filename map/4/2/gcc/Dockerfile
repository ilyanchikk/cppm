FROM ubuntu:latest
COPY . /app
WORKDIR /app
RUN apt update
RUN apt install -y g++
RUN g++ main.cpp -o test
CMD ["./test"]
