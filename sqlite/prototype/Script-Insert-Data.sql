#!/bin/bash
uuid1=$(uuidgen)
uuid2=$(uuidgen)
uuid3=$(uuidgen)
uuid4=$(uuidgen)
uuid5=$(uuidgen)
uuid6=$(uuidgen)
uuid7=$(uuidgen)
echo $uuid
sqlite3 test.db  \
"insert into HT values ('Tree Pine White Ghostly High Tall Thick','$uuid1',0); 
 insert into HT values ('Tree Pine White Ghostly High Tall','$uuid2',0);
 insert into HT values ('Tree Pine White Ghostly High','$uuid3',0);
 insert into HT values ('Tree Pine White Ghostly','$uuid4',0);
 insert into HT values ('Tree Pine White','$uuid5',0);
 insert into HT values ('Tree Pine','$uuid6',0);
 insert into HT values ('Tree','$uuid7',0); "
