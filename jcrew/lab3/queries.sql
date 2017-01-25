-- SQL Create Views and Queries for Ebola Database

---------------------- CREATE VIEWS ----------------------

-- create view from Survey_Respondent of gender, age, education, country_name
-- of survey respondents
CREATE VIEW SurveyResp_Country (gender, age, education, country_name) 
AS SELECT gender, age, education, country_name 
FROM Survey_Respondent;


-- create view from ETC and Partner_Orgs of etc_name, country_name, partner_org
CREATE VIEW ETC_limited (etc_name, country_name, partner_org) 
AS SELECT etc_name, country_name, partner_org 
FROM ETC, Partner_Orgs;


------------------------- QUERIES -------------------------

-- etc_open_beds()
-- show ETCs in a selected country that have greater than 
-- a selected number of open beds, ordered by open_beds
SELECT * 
FROM ETC 
WHERE country_name = ['Guinea'] 
HAVING beds_open > [50]
ORDER BY beds_open;

-- age_edu_sex_country()
-- show average age and average education level of a selected gender population
-- in a selected country
SELECT AVG(age) as avg_age, AVG(education) as avg_education 
FROM survey_respondent 
WHERE gender = ['M'] 
AND country_name = ['liberia'] 
AND (education != 88 OR education != NULL);

-- count_sex_educ()
-- count number of gender selected, survey respondents that have 
-- a selected educuation level or higher 
SELECT COUNT(education) as selected_educ_or_higher
FROM survey_respondent
WHERE education >= [6]
AND GENDER = ['F'];

-- partner_lat_long()
-- show Partner Orgs with their longitude/latitude coordinates
-- where coordinates are given
SELECT partner_org, latitude, longitude  
FROM Partner_orgs INNER JOIN ETC 
WHERE (latitude != 0 OR longitude != 0);

-- org_ETC_codes()
-- show ETCs by etc_code that selected Organization is working with, 
-- ordered by etc_code
SELECT org_name, etc_code  
FROM Country_Org INNER JOIN ETC 
WHERE org_name = ['UNMEER']
ORDER BY etc_code;

-- distinct_org_types()
-- show distinct organization types from Organization
SELECT DISTINCT org_type 
FROM Organization;

-- respondent_country_info()
-- joins country and respondent tables; makes a row for every respondent
-- including their personal info and their home country's info
SELECT * FROM Country 
LEFT OUTER JOIN Survey_Respondent 
on Country.country_name = Survey_Respondent.country_name 
WHERE gender = ['M'];

-- non_closed_ETC_partner()
-- joins ETC and Partner_org_ETC tables; makes a row for each ETC
-- displays ETC's info and its partner organization 
SELECT * FROM ETC 
LEFT OUTER JOIN Partner_org_ETC 
on ETC.etc_code=Partner_org_ETC.etc_code 
WHERE status='Open' or status='Under Construction';

-- country_gdp()
-- orders countries by gdp, ascending
SELECT * FROM Country
ORDER BY gdp_cap;

-- count_organized()
-- counts the number of respondents who felt their community was organized
-- based on gender, education, and country
SELECT COUNT(corganizedae) as count_organized
FROM Survey_Respondent
WHERE gender = ['M']
AND corganizedae = 1
AND education >= [3]
AND country_name = ['Liberia'];




--------------------- QUERIES BY VIEWS ---------------------

-- show surveyresp_country, ordered by increasing age of survey respondents
SELECT * 
FROM surveyresp_country 
ORDER BY age;

-- show etc_name and partner_org from etc_limited, ordered by etc_names
SELECT etc_name, partner_org 
FROM etc_limited 
ORDER BY etc_name;

-- show etc_name, partner_org, country_name, and gdp_cap
-- for selected  partner_org, ordered by country_name
SELECT etc_name, partner_org, country.country_name, gdp_cap  
FROM etc_limited INNER JOIN country 
WHERE partner_org = ['World Health Organization']
ORDER BY country.country_name;

-- show average age of selected gender of survey respondents
-- from surveyresp_country
SELECT gender, AVG(age) AS average_age 
FROM surveyresp_country 
GROUP BY gender 
HAVING gender = ['F'];

-- show average education level of selected gender of survey respondents
-- from surveyresp_country
SELECT gender, AVG(education) AS average_education
FROM surveyresp_country
GROUP BY gender
HAVING gender = ['M'];
