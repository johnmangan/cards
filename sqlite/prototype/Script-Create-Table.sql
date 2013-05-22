#!/bin/bash
sqlite3 test.db  "create virtual table HT using fts3(Hashtag TEXT, File_Name TEXT, Default_Score INTEGER);"
