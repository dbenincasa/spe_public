#!/bin/bash
KEY=$(( $RANDOM % 10 ))
for i in `seq 1 10`;
do
    VAR=$(date +%s | shasum | base64 | head -c 32) # watch out no spaces in the =
    # on linux sha256sum 
    mkdir $VAR
    if [ "$i" = "$KEY" ]; then
       echo candy > "$VAR/candy"
    fi
    echo "sleeping a while..."
    sleep 1
done
