#!/bin/bash
sqlite3 test.db  "insert into HT 
				(
				Hashtag_Object_Primary     , Hashtag_Object_Optional    ,
				Hashtag_Adjective_Primary  , Hashtag_Adjective_Optional ,
				Hashtag_Adjective_LOD      , Hashtag_Adjective_MISC     )
				values 
				('Tree',
				 'Pine',
				 'White',
				 'Ghostly',
				 'High',
				 'Tall and Thick')"
				 
