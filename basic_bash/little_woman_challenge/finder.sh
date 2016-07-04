list_of_names="Beth
Jo
Amy
Meg"

for name in $list_of_names
do
   grep $name LittleWoman.txt | wc -l
done
