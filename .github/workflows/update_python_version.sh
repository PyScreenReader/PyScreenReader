#!/bin/bash

# Shell script to update python version used to build wheel artifact.
# This script lookups patterns of "python_version_string=[Python Version Number]" in the hardcoded file list
# below, and update them to the provided python version.

# Usage: ./update_python_version.sh 3.11

set -e

# List of files that contains python version number
FILES=("platforms/wheel_tags.bzl" "MODULE.bazel")

if [ -z "$1" ]; then
  echo "Usage: $0 <python_version>"
  exit 1
fi

PYTHON_VERSION="$1"

# Check if file exists
for FILE in "${FILES[@]}"; do
  if [ ! -f "$FILE" ]; then
    echo "File not found: $FILE"
    exit 1
  fi

  # Use `sed` to update python_version_string
  sed -i.bak -E "s/^(python_version_string = )\"[0-9]+\.[0-9]+\"/\1\"$PYTHON_VERSION\"/" "$FILE"

  echo "Updated python_version_string in $FILE to \"$PYTHON_VERSION\""
done
