# Import Partner Orgs from ETC.csv

import pymysql
import csv
from db_connect import *

def import_Partner_Orgs():
    is_success = True
    insert_prefix = "INSERT INTO Partner_Orgs (partner_org) VALUES ("

    try:
        partners_used = list()
        rows = list(csv.reader(open('../Datasets/ETC.csv', 'rb'), delimiter=","))
        rows.remove(rows[0])
        unique_rows = list()
        for row in rows:
            partner = row[4]
            if len(partner) == 0:
                partners_used.append(partner)
            if partner not in partners_used:
                partners_used.append(row[4])
                unique_rows.append(row)

        for i, row in enumerate(unique_rows):
            insert_stmt = insert_prefix
            
            for j, val in enumerate(row):
                if val:
                    if j==4:
                        insert_stmt += "'" + val + "'"
                    else:
                        continue
            
            insert_stmt += ");"
            insert_status = run_insert(insert_stmt)
            if insert_status is False:
                is_success = False
                return is_success
                
    except IOError as e:
        is_success = False
        print ("import Partner_Orgs Error: " + e.strerror)

    return is_success

# def main():
    # import_Partner_Orgs()
# main()
