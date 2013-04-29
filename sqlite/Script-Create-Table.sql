#!/bin/bash
sqlite3 test.db  "
create table HT (
				id INTEGER PRIMARY KEY,
				Hashtag_Object_Primary     TEXT,
				Hashtag_Object_Optional    TEXT,
				Hashtag_Adjective_Primary  TEXT,
				Hashtag_Adjective_Optional TEXT,
				Hashtag_Adjective_LOD      TEXT,
				Hashtag_Adjective_MISC     TEXT);"
