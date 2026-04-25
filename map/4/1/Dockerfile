FROM ubuntu:16.04
COPY . /app
WORKDIR /app
RUN apt update
RUN apt install -y g++ nano
RUN g++ main.cpp -o test
CMD ["./test"]
