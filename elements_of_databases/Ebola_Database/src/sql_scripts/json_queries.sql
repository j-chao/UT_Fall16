-- SQL queries on Tweet table in Ebola database
use ebola;

-- count number of tweets on Liberia
select count(*) as "Number of Tweets on Liberia" from Tweet
where country_name = "liberia";

-- list tweet_id by decreasing number of retweets
select tweet_id, retweet_count from Tweet
order by retweet_count desc;

-- list tweet_id with screen_name by decreasing number of followers_count
select tweet_id, screen_name, followers_count from Tweet
order by followers_count desc;

-- list tweets originating from Nepal with urban_pop of tweeted country
select tweet_id, origin, Tweet.country_name, urban_pop from Tweet
left outer join Country
on Country.country_name=Tweet.country_name
where origin = 'Nepal';

-- list tweets on a country whose health_exp is < 6
select tweet_id, Tweet.country_name, health_exp from Tweet
left outer join Country
on Country.country_name=Tweet.country_name
where health_exp < 6;

-- list content and retweet count of retweets, order by decreasing retweet count
select tweet_text, retweet_count from Tweet
where tweet_text like '%RT @%' 
order by retweet_count desc;

-- list tweets about Liberia with screen_name
select screen_name, tweet_text from Tweet
where tweet_text like '%liberia%';

-- list tweets about Sierra Leone with screen_name
select screen_name, tweet_text from Tweet
where tweet_text like '%sierraleone%';

-- list tweets about Guinea with screen_name
select screen_name, tweet_text from Tweet
where tweet_text like '%guinea%';
