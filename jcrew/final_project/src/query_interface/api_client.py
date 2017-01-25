import json
import tweepy
import pymysql
from db_connect import *

# Our real keys and tokens
API_KEY = 'bOondRoF63msjOZn2MBltACwk'
API_SECRET = 'bQSHowUX8L2oQNvD3xzIpQzqhkdvrd7JCb20gC5iwn2KTSByjV'
TOKEN_KEY = '728312577080451072-8PeNy9HzQuSjgm7JZsUt3obZ1fpZS3c'
TOKEN_SECRET = 'Rmk3FcMEO1tCEjTgedGtRMCGjzvQnWrP182ulaY1hmNVB'

def get_api_instance():
  auth = tweepy.OAuthHandler(API_KEY, API_SECRET)
  auth.set_access_token(TOKEN_KEY, TOKEN_SECRET)
  api_inst = tweepy.API(auth)
  return api_inst

  
def do_data_pull(api_inst):

  sql_query = "select country_name from Country order by country_name"

  try: 
    conn = create_connection()
    db_cursor = conn.cursor()
    query_status = run_stmt(db_cursor, sql_query)
    resultset = db_cursor.fetchall()

    for record in resultset:
      country_name = record[0]

      ebola_query = "(#Ebola) AND "
      twitter_query = ebola_query + "'" + country_name + "'"
      print ("twitter_query: " + twitter_query)
      twitter_cursor = tweepy.Cursor(api_inst.search, q=twitter_query, lang="en")

      for page in twitter_cursor.pages():
        for item in page:
          json_str = json.dumps(item._json)
          print ("found a " + country_name + " + #Ebola tweet")
          insert_stmt = "insert into Tweet(tweet_doc, country_name) values(%s, %s)"
          run_prepared_stmt(db_cursor, insert_stmt, (json_str, country_name))
          do_commit(conn)

  except pymysql.Error as error:
    is_success = False
    print ("do_data_pull: " + e.strerror)

api_inst = get_api_instance()
do_data_pull(api_inst)
