for i in `seq 1 1000`;
do
	last_number=`tail -1 num`
	last_number=$((last_number + 1))

	echo $last_number >> num
done
