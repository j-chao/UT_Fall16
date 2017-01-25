#!/bin/bash
# Build Ebola Database and execute Command Line Interface

# PROGRAM START
echo "=============== Building Ebola Database from datasets ==============="
echo

# Create tables for database
echo "=============== Creating tables..."
echo
mysql -u "root" -p "" < ../src/sql_scripts/create_tables.sql

# Extend database with Tweet table 
echo
echo "=============== Creating Tweet table..."
echo
mysql -u "root" < ../src/sql_scripts/extend_database.sql

# Populate tables from datasets  
echo
echo "=============== Populating tables from included datasets..."
echo
cd ../src/populate_database_scripts
python2 populate_database.py
cd ../../bin

# Run Twitter API and populate Tweet table
echo
echo "=============== Populating tweets using Twitter API..."
echo
python2 ../src/query_interface/api_client.py

# Start Command Line Interaface
echo
echo "=============== Starting Command Line Interface..."
echo
python2 ../src/query_interface/extended_query_interface.py


# Clean Up
echo
echo "=============== Cleaning up compiled files..."
echo
find .. -name \*.pyc -type f -delete 


# END PROGRAM
echo
echo "============================== END PROGRAM =============================="
echo
