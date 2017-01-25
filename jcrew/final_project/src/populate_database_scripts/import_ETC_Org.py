# Populate ETC_Org Junction Table from ETC.csv and orgs_involved.csv
import pymysql
import csv
from db_connect import *

def import_ETC_Org():
    is_success = True
    insert_prefix = "INSERT INTO ETC_Org (etc_code, org_name) VALUES ("

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

        org_rows = list(csv.reader(open('../Datasets/orgs_involved.csv', 'rb'), delimiter=","))
        org_rows.remove(org_rows[0])
        org_names = []
        for row in org_rows:
            name = row[2]
            if name not in org_names:
                org_names.append(name)

        in_both = list()
        for combo in code_partner_combos:
            if combo[1] in org_names:
                in_both.append(combo)
                
        for i,row in enumerate(in_both):
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
        print ("import ETC_Org Error: " + e.strerror)

    return is_success

# def main():
    # import_ETC_Org()
# main()
