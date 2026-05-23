#!/bin/bash



find "$1" -name "*.log" | while read file; do
        sort --output $file $file
done









