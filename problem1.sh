#!/bin/bash

#USERS=$(who -u | cut -d' ' -f1)
USERS=$(cat who.fake | cut -d' ' -f1)
#PROCESSES=$(ps -e | cut -d' ' -f1)
PROCESSES=$(cat ps.fake | cut -d' ' -f1)

for USER in $USERS;do
        COUNT=0
        for PROCESS in $PROCESSES;do
                if test "$USER" = "$PROCESS";then
                        COUNT=$((COUNT + 1))
                fi

        done

        echo "$USER" "$COUNT"

done





