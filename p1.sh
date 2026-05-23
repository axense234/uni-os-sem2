#!/bin/bash

cat who.fake | awk '{print $1}' | sort | uniq | while read user; do
        NB_PROCESSES=$(cat ps.fake | grep -E $user | wc -l)
        echo "for user $user nb of processes $NB_PROCESSES"
done














