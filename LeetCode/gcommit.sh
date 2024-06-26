#!/bin/sh
LAST_ADDED_FILE=`ls -t | head -1`

echo $LAST_ADDED_FILE
COMMIT_MESSAGE=$1
echo $COMMIT_MESSAGE

git add $LAST_ADDED_FILE
git commit -m $COMMIT_MESSAGE
git push

echo "File $LAST_ADDED_FILE was pushed with commit message $COMMIT_MESSAGE"
