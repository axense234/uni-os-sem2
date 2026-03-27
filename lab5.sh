#!/bin/bash

GIVEN_DIR=$1

# see if argument is provided
if test -z "$GIVEN_DIR" ;then
    echo "No argument provided."
    exit
fi


# see if it's a directory
if test ! -d "$GIVEN_DIR" ;then
    echo "Directory does not exist."
    exit
fi


while true; do

    CONTENT=""
    for FILE in $(find "$GIVEN_DIR"); do
        CONTENT="$CONTENT"$(echo "$FILE" | sha1sum)
    done

    #echo "$CONTENT"

    if test -n "$PREV_CONTENT" && test "$PREV_CONTENT" != "$CONTENT";then
        echo "Change detected"
        exit
    fi

    PREV_CONTENT="$CONTENT"

    sleep 1
done