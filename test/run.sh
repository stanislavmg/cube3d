#!/bin/bash

if make -C .. MAIN=test/test.c && mv ../cub3D ./test ; then
	./test
else
	echo 'make error'
fi