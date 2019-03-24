if ln num num.lock
	then
		for i in `seq 1 1000`;
		do
			last_number=`tail -1 numbers`
			last_number=$((last_number + 1))

			echo $last_number >> num
		done
    rm num.lock
fi
