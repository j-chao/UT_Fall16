# Populate Partner_Org_ETC Junction Table from ETC.csv
import pymysql
import csv
from db_connect import *

def import_Partner_Org_ETC():
    is_success = True
    insert_prefix = "INSERT INTO Partner_Org_ETC (etc_code, partner_org) VALUES ("

    try:
        rows = list(csv.reader(open('../Datasets/ETC.csv', 'rb'), delimiter=","))
        rows.remove(rows[0])
        code_partner_combos = []
        for row in rows:
            code = row[0]
            partner = row[4]
            code_partner = [code, partner]
            if len(code_partner[1]) != 0:
                code_partner_combos.append(code_partner)

        for i,row in enumerate(code_partner_combos):
            insert_stmt = insert_prefix
            
            for j,val in enumerate(row):
                if val:
                    if j==0:
                        insert_stmt += "'" + val + "', "
                    elif j==1:
                        insert_stmt += "'" + val + "'"

            insert_stmt += ");"
            insert_status = run_insert(insert_stmt)
            if insert_status is False:
                is_success = False
                return is_success

    except IOError as e:
        is_success = False
        print ("import Partner_Org_ETC Error: " + e.strerror)

    return is_success

# def main():
    # import_Partner_Org_ETC()
# main()
