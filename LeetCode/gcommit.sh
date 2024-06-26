#!/bin/sh

if [ -z "$1" ]; then
  echo "Коміт-меседж не заданий. Використання: ./gcommit.sh \"commit message\""
  exit 1
fi

LAST_ADDED_FILE=$(ls -t | head -1)

if [ -z "$LAST_ADDED_FILE" ]; then
  echo "Файл для додавання не знайдено."
  exit 1
fi

echo "Останній доданий файл: $LAST_ADDED_FILE"

COMMIT_MESSAGE="$1"
echo "Commit message: $COMMIT_MESSAGE\n"

git add "$LAST_ADDED_FILE"
git commit -m "$COMMIT_MESSAGE"
git push

echo "Файл $LAST_ADDED_FILE був доданий і запушений з коміт-меседжем: $COMMIT_MESSAGE"
