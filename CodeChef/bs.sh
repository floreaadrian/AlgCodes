#/usr/bin/bash

for f in *; do
  if [ -d $f ]
  then
    echo "File -> $f"
    mv "./$f/main.cpp" "$f.cpp"
  fi
done
