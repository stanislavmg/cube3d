#!/bin/bash

if cd .. && make MAIN=test/test.c && mv cub3D test/test ; then
	cd test
	./test
else
	echo 'make error'
fi