grep -v '^#' /etc/passwd | awk -F: 'NR % 2 == 0 {print $1}' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | xargs echo | sed -e 's/ /, /g' | sed -e 's/$/./g' | tr -d '\n'