astyle --options=./rope.astylerc --recursive "src/*.h" "src/*.c"

find . -name "*.orig" -exec rm {} \;
