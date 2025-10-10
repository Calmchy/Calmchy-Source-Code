#!/bin/bash

# Ask for files to add
read -p "git add : " files

# Ask for commit message
read -p "git commit -m : " msg

# Confirm push (and only then run everything)
read -p "Enter to push (Y/N): " confirm

if [[ "$confirm" == "Y" || "$confirm" == "y" ]]; then
    git add $files
    git commit -m "$msg"
    git push
else
    echo "Skipped: No add, no commit, no push."
fi

clear;fastfetch;ls;./git.sh
