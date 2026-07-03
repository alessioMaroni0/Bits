#!/bin/bash

docker build -t bits-test .

docker run --rm bits-test