# Populate ETC Table from ETC.csv
import pymysql
import csv
from db_connect import *

def import_ETC():
    is_success = True
    insert_prefix = "INSERT INTO ETC (etc_code,	etc_name, status, beds_open, latitude, longitude, lab_present, country_name) VALUES ("

    try:
        codes_used = list()
        rows = list(csv.reader(open('../Datasets/ETC.csv', 'rb'), delimiter=','))
        rows.remove(rows[0]) 
        unique_rows = list() 

        for row in rows:
            code = row[0]  
            if code not in codes_used:
                codes_used.append(row[0])
                unique_rows.append(row) #create subset of unique rows where each etc_code only appears once

        for i, row in enumerate(unique_rows):
            insert_stmt = insert_prefix

            for j, val in enumerate(row):
                if j==4: continue
                if val:
                    if j==0 or j==1 or j==2 or j==7:
                        insert_stmt += "'" + val + "', "
                    elif j==3 or j==5 or j==6:
                        insert_stmt += val + ", "
                    else:
                        insert_stmt += "'" + val + "'"
                else:
                    if j==8:
                        insert_stmt += "NULL"
                    else:
                        insert_stmt += "NULL" + ", "
            insert_stmt += ");"
            insert_status = run_insert(insert_stmt)
            if insert_status is False:
                is_success = False
                return is_success
                
    except IOError as e:
        is_success = False
        print ("import ETC Error: " + e.strerror)
    
    return is_success

# def main():
    # import_ETC()
# main()
