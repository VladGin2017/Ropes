astyle --options=./librecad.astylerc --recursive  "*.c" "*.h"

find . -name "*.orig" -exec rm {} \;
