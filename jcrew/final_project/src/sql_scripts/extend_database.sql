-- extend_database.sql for Ebola database
-- creates Tweet table if exists

use ebola;

DROP TABLE IF EXISTS Tweet;

CREATE TABLE Tweet (
  tweet_id varchar(32) generated always 
     as (json_unquote(json_extract(tweet_doc, '$.id_str'))) stored primary key,

  screen_name varchar(32) generated always 
     as (json_unquote(json_extract(tweet_doc, '$.user.screen_name'))) stored,
    
  followers_count integer generated always
     as (json_unquote(json_extract(tweet_doc, '$.user.followers_count'))) stored,

  created_at datetime generated always 
     as (str_to_date(json_unquote(json_extract(tweet_doc, '$.created_at')), 
     '%a %b %d %H:%i:%s +0000 %Y')) stored,

  retweet_count integer generated always
     as (json_unquote(json_extract(tweet_doc, '$.retweet_count'))) stored,

  language varchar(32) generated always
     as (json_unquote(json_extract(tweet_doc, '$.lang'))) stored,

  origin varchar(100) generated always
     as (json_unquote(json_extract(tweet_doc, '$.place.country'))) stored,
     
  tweet_text varchar(400) generated always
     as (json_unquote(json_extract(tweet_doc, '$.text'))) stored,


  tweet_doc json,

  country_name varchar(100),

  foreign key (country_name) references Country(country_name)
);
