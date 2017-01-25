-- create_tables.sql for Ebola database

DROP DATABASE IF EXISTS Ebola;
CREATE DATABASE IF NOT EXISTS Ebola;
USE Ebola;

SELECT 'CREATING DATABASE STRUCTURE' as 'INFO';

DROP TABLE IF EXISTS    Country,
                        ETC,
                        Partner_Orgs,
                        Partner_Org_ETC,
                        Survey_Respondent,
                        Organization,
                        ETC_Org,
                        Country_Org;

set default_storage_engine = InnoDB;

select CONCAT('storage engine: ', @@default_storage_engine) as INFO;

CREATE TABLE Country (
    country_name        VARCHAR(100)    NOT NULL,
    health_exp          FLOAT           NOT NULL,
    gdp_cap             INTEGER         NOT NULL,
    urban_pop           FLOAT           NOT NULL,
    PRIMARY KEY (country_name)
);

CREATE TABLE ETC (
    etc_code            CHAR(100)       PRIMARY KEY,
    country_name        VARCHAR(100),
    etc_name            VARCHAR(100),
    latitude            FLOAT,
    longitude           FLOAT,
    lab_present         CHAR(1)         CHECK (lab_present = Y or N),
    status              VARCHAR(100),
    beds_open           INTEGER,
    FOREIGN KEY (country_name)  REFERENCES Country (country_name)    ON DELETE CASCADE
);

CREATE TABLE Partner_Orgs (
    partner_org         VARCHAR(100)    PRIMARY KEY
);

CREATE TABLE Partner_Org_ETC (
    etc_code            CHAR(100)       NOT NULL,
    partner_org         VARCHAR(100)    NOT NULL,
    CONSTRAINT PK_Partner_Org_ETC PRIMARY KEY
    (
        etc_code,
        partner_org
    ),
    FOREIGN KEY (etc_code) REFERENCES ETC (etc_code),
    FOREIGN KEY (partner_org) REFERENCES Partner_Orgs (partner_org)
);

CREATE TABLE Survey_Respondent (
    respid              INTEGER         PRIMARY KEY,
    country_name        VARCHAR(100),
    gender              CHAR(1)         CHECK (gender = M or F or NULL),
    age                 INTEGER,
    education           INTEGER,
    corganizedae        INTEGER,
    FOREIGN KEY (country_name)  REFERENCES Country (country_name)    ON DELETE CASCADE
);

CREATE TABLE Organization (
    org_name            VARCHAR(100)    NOT NULL,
    country_name        VARCHAR(100)    NOT NULL,
    org_acronym         VARCHAR(100),
    org_type            VARCHAR(100),
    PRIMARY KEY (org_name),
    FOREIGN KEY (country_name)  REFERENCES Country (country_name)    ON DELETE CASCADE
);

CREATE TABLE ETC_Org (
    etc_code            CHAR(100)       NOT NULL,
    org_name            VARCHAR(100)    NOT NULL,
    CONSTRAINT PK_ETC_Org PRIMARY KEY
    (
        etc_code,
        org_name
    ),
    FOREIGN KEY (etc_code) REFERENCES ETC (etc_code),
    FOREIGN KEY (org_name) REFERENCES Organization (org_name)
);

CREATE TABLE Country_Org (
    country_name        CHAR(100)       NOT NULL,
    org_name            VARCHAR(100)    NOT NULL,
    CONSTRAINT PK_Country_Org PRIMARY KEY
    (
        country_name,
        org_name
    ),
    FOREIGN KEY (country_name) REFERENCES Country (country_name),
    FOREIGN KEY (org_name) REFERENCES Organization (org_name)
);
