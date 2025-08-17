#!/bin/bash

# Shell script to update the release version used to build the project.
# This script looks for patterns like "release_version = [Version Number]" in a hardcoded list of files
# and updates them to the provided version.

# Usage: update_release_version.sh 1.2.3

set -e

# List of files that contain release version
FILES=("platforms/wheel_tags.bzl")

if [ -z "$1" ]; then
  echo "Usage: $0 <release_version>"
  exit 1
fi

RELEASE_VERSION="$1"

# Check if file exists and update release_version
for FILE in "${FILES[@]}"; do
  if [ ! -f "$FILE" ]; then
    echo "File not found: $FILE"
    exit 1
  fi

  # Use `sed` to update release_version
  sed -i.bak "s/release_version = \"dev\"/release_version = \"$RELEASE_VERSION\"/" "$FILE"

  echo "Updated release_version in $FILE to \"$RELEASE_VERSION\""
done
