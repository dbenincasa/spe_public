#!/bin/bash
for i in `seq 1 10`;
do
    VAR=$(date +%s | shasum | base64 | head -c 32) # watch out no spaces in the =
    # on linux sha256sum 
    echo $VAR > $VAR
    if [ "$i" = 3 ]; then
       echo "cazzo"
    fi
    echo "sleeping a while..."
    sleep 1
done
