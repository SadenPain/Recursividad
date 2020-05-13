read -e -p "Enter filename, use tab for completion: " file
ls -l "$file"
gcc -Wshadow -Wall -o "a" "$file" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
