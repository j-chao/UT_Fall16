# Populate Survey_Respondent from data_survey.csv
import pymysql
import csv
from db_connect import *

def import_Survey_Respondent():
    is_success = True
    insert_prefix = "INSERT INTO Survey_Respondent (country_name, respid, gender, age, education, corganizedae) VALUES ("

    try:
        csvfile = open('../Datasets/data_survey.csv', 'rb')
        reader = csv.reader(csvfile)

        for i, row in enumerate(reader):
            if i==0: continue                               # skip column names row      
            insert_stmt = insert_prefix
            
            for j, val in enumerate(row):
                if val:
                    if j==0 or j==2:
                        insert_stmt += "'" + val + "', "
                    elif j==1 or j==3 or j==4:              # handles numeric types
                        insert_stmt += val + ", "
                    else:                                   # handles last/numeric value
                        insert_stmt += val
                else:                                       # handles null
                    if j == 5:
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
        print ("import Survey_Respondent Error: " + e.strerror)

    return is_success

# def main():
    # import_Survey_Respondent()
# main()
