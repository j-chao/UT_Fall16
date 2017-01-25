# Populate Country_Org junction table from orgs_involved.csv
import pymysql
import csv 
from db_connect import *

def import_Country_Org():
    is_success = True
    insert_prefix = "REPLACE INTO Country_Org (country_name, org_name) VALUES ("

    try:
        rows = list(csv.reader(open('../Datasets/orgs_involved.csv', 'rb'), delimiter=","))
        rows.remove(rows[0])
        country_org_combos = []
        for row in rows:
            country = row[0]
            org = row[2]
            country_org = [country, org]

            if len(country_org[1]) != 0:
                country_org_combos.append(country_org)

        country_rows = list(csv.reader(open('../Datasets/CIA_World_Factbook.csv', 'rb'), delimiter=","))
        country_rows.remove(country_rows[0])
        country_names = []
        for row in country_rows:
            name = row[0]
            if name not in country_names:
                country_names.append(name)

        in_both = list()
        for combo in country_org_combos:
            if combo[0] in country_names:
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
        print ("import Country_Org Error: " + e.strerror)
    
    return is_success

# def main():
    # import_Country_Org()
# main()
