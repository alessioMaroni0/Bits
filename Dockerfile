FROM alpine:latest

RUN apk add --no-cache clang make musl-dev build-base

WORKDIR /app

COPY . .

RUN make clean && make

CMD ["./build/main"]