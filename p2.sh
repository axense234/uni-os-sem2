#!/bin/bash


find "$1" -name "*.c" | while read file; do
        lines=$(cat $file | wc -l)
        count=0
        if [ "$lines" -gt 500]; then
                count=$(expr $count + 1)
                echo "test"
        fi

        if ["$count" -eq 2]; then
                break
        fi

done














