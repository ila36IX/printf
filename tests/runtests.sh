echo "▄▄▄▄▄▄▄▄▄ ..▄▄ · ▄▄▄▄▄▪   ▐ ▄  ▄▄ •       "
sleep 0.05
echo "▀•██ ▀▀▄.▀·▐█ ▀. •██  ██ •█▌▐█▐█ ▀ ▪      "
sleep 0.04
echo "  ▐█.▪▐▀▀▪▄▄▀▀▀█▄ ▐█.▪▐█·▐█▐▐▌▄█ ▀█▄      "
sleep 0.03
echo "  ▐█▌·▐█▄▄▌▐█▄▪▐█ ▐█▌·▐█▌██▐█▌▐█▄▪▐█      "
sleep 0.02
echo "  ▀▀▀  ▀▀▀  ▀▀▀▀  ▀▀▀ ▀▀▀▀▀ █▪·▀▀▀▀ ▀ ▀ ▀ "
sleep 0.2
# Here where the linking to you libft library should be configured
libft="-Llibft/ -lft"

logDir="/tmp/print_logs"
clr_off='\033[0m'
green='\033[1;32m'
red='\033[1;31m'
red_small='\033[0;31m'
blue='\033[0;34m'
yellow='\033[0;33m'

# create the logs directory if it doesn't exists
[ ! -d "$logDir" ] && mkdir -p "$logDir"

find tests -type f -name "*.c" | sort | while read -r file; do
	you="$logDir/$(basename "$file" ".c").you"
	org="$logDir/$(basename "$file" ".c").org"
	gcc "$file" ft_printf.c helper_functions.c $libft -o run
	./run you > $you
	if [ $? -eq 139 ]; then
		echo "${red}Your code segFaults after:${clr_off}"
		echo "${red}gcc "$file" ft_printf.c helper_functions.c $libft -o run && ./run you${clr_off}"
		echo "segFault starts here" >> $you
	fi
	./run org > $org
	if [ $? -eq 139 ]; then
		echo "${red}Your code segFaults after:${clr_off}"
		echo "${red}gcc "$file" ft_printf.c helper_functions.c $libft -o run && ./run you${clr_off}"
		echo "segFault starts here" >> $you
	fi
	# test description
        test=$(head -1 "$file" | awk -F'*' '{print $2}')
	# if there is any diffs between the two outputs
	# the next if will be excuted
	diff_output=$(diff --color=auto  $you $org -y)
	if [ $? -ne 0 ]; then
		echo "${red}✗ FAIL${clr_off} $test\n"
		echo "${red_small}Test File:  $file$clr_off"
		echo ${yellow}
		# Print the function call
		grep "= f(" $file | awk -F= '{print $2}' 
		echo "${clr_off}"
		# Prit the difference between the files
		echo "${blue}$diff_output$clr_off"
		echo ""
    	else
        	echo "${green}✓ PASS${clr_off} $test"
    	fi
done
