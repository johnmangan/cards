#!/bin/bash   
tempTable=a$(uuidgen | tr -d 0-9-)
star='*'
sqlstatement="SELECT $star FROM HT WHERE Hashtag MATCH "
union=" UNION "
end=";"
sq="'"
sql=""
cat hashTagList.txt > tmp.txt
old_IFS=$IFS
IFS=' '
tag=($(cat tmp.txt)) 
IFS=$old_IFS

for ((j=0;j<${#tag[*]};j=j+2)); do
		sql=$sql$sqlstatement$sq${tag[j]}$sq
		k=${#tag[*]}
		
		#Still coming, add UNION 
		if [ $j -lt $[$k - 2] ]; then
		 sql=$sql$union			
        fi		    
done
#semicolon
sql=$sql$end

echo "$sql"
sqlite3 test.db "create virtual table $tempTable using fts3(Hashtag TEXT, File_Name TEXT,Vertices INTEGER,Score INTEGER);"
sqlite3 test.db "INSERT INTO $tempTable (hashtag, file_name, Vertices) $sql"
sqlite3 test.db " UPDATE $tempTable SET SCORE = 0 WHERE rowid >=0 ;"

for ((j=0;j<${#tag[*]};j=j+2)); do
		sqlite3 test.db " UPDATE $tempTable SET SCORE = SCORE + ${tag[$j+1]} WHERE hashtag MATCH $sq${tag[j]}$sq ;"
		echo " UPDATE $tempTable SET SCORE = SCORE + ${tag[$j+1]} WHERE hashtag MATCH $sq${tag[j]}$sq ;"
done

sqlite3 test.db "Select hashtag, file_name, max(score) from $tempTable;"
sqlite3 test.db "drop table $tempTable;"

rm tmp.txt
#grep "/OPT" TestData.txt > tmp.txt
#old_IFS=$IFS
#IFS=$'\n'
#optTag=($(cat tmp.txt)) # array
#IFS=$old_IFS

#sql=""
#echo ${optTag[i]} > temporaryFile
#read -a msgArr < temporaryFile
#for ((j=0;j<${#optTag[*]};j++)); do
#			sql=$sql$sqlstatement$sq${msgArr[j]}$sq
#		k=${#optTag[*]}
#		if [ $j -lt $[$k - 1] ]; then
#		 sql=$sql$union
			
#        fi		    
#done
#sql=$sql$end
#echo "$sql"
#sqlite3 test.db "create virtual table temp using fts3(Hashtag TEXT, File_Name TEXT,Score INTEGER);"
#sqlite3 test.db "INSERT INTO temp (hashtag, file_name) $sql"
