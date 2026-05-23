#!/bin/bash

find "$1" -type f | while read file; do
        checksum=$(md5sum $file | awk '{print $1}')
        if echo "$files" | grep -q "$checksum"; then
                echo "duplicate file $file"
        fi
        files+=" $checksum "
done











