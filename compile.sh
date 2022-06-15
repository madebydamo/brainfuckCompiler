gcc ./compiler.c -o translator
./translator $1
if [ "$2" = "" ]
  then
    OUTPUT=out
  else
    OUTPUT=$2
fi
gcc ./skellet.c -o $OUTPUT
rm ./translator
rm ./out.c
