# LISTING OF DATASETS
* This listing is copied in data_sources.txt.
* Countries of interest: Guinea, Liberia, Sierra Leone.
* Datasets have been cleaned for better integration into a database. 
Original datasets from sources can be found in the original_datasets directory.


---
## Comprehensive Dataset  
### files: comprehensive_dataset.xlsx
This excel file is a comprehensive spreadsheet containing all used datasets in
their own respective sheet.  


---
## Ebola Treatment Centers or Units (ETCs or ETUs)
### source: https://data.humdata.org/dataset/ebola-treatment-centers
### files: ETC.csv
This dataset represents the best-known collection of status and location of the
facilities known as Ebola Treatment Centers or Ebola Treatment Units in Guinea,
Liberia and Sierra Leone, with relevant attributes and information. Please
forward any mistakes or requested changes to unmeer.im@gmail.com. Updated
frequently.

#### METADATA
Source: UNMEER (United Nations Mission for Ebola Emergency Response)    
Contributor: UNMEER     
Date of Dataset: Dec 30, 2014    
Location: Guinea,  Liberia,  Sierra Leone  
Visibility: Public  
License: Creative Commons Attribution for Intergovernmental Organisations  
Methodology: Direct Observational Data/Anecdotal Data    
Caveats / Comments: Data may have inaccuracies and will be updated as soon as possible with newly-provided information.  

* ATTRIBUTES OF INTEREST: Country, ECF_Code, Status, Partner, Latitude, Longitude  


---
## Data for Ebola Recovery
### source: https://data.humdata.org/dataset/data-for-ebola-recovery
### files: data_survey.csv , survey_ref.xlsx
Data on health, economic livelihoods, food security, and ebola vigilance from
representative survey of Monrovia conducted in December 2014, March 2015, and
June 2015. Full details, results and analysis can be found at
data4ebolarecovery.org

The December survey was conducted from December 6, 2014 to January 7, 2015 by
our implementing partner, Parley, a Liberian NGO. Enumerators conducted surveys
in person using handheld devices operating the Pendragon Survey Software.
Follow-up surveys in March and June were conducted by phone.

The selection of respondents followed a three-stage sampling procedure. In the
the first stage, 77 communities were randomly selected from all of Monrovia’s
fifteen administrative wards in proportion to their population size. In the
second stage, twenty households were randomly selected within each community
following a random-walk procedure. Within each household, a single adult
respondent was randomly selected for the survey. The response rate was 95%.

The survey covered outreach efforts, attitudes toward survivors, knowledge of
Ebola symptoms and transmission paths, uptake of Ebola prevention practices,
Ebola incidence histories, health outcomes, food security, economic outcomes,
and social outcomes. The survey lasted about 45 minutes on average.

#### METADATA
Source: MIT Governance Lab  
Contributor: MIT Governance Lab  
Date of Dataset: Dec 04, 2014 - Jan 07, 2015   
Location: Liberia   
Visibility: Public  
License: Creative Commons Attribution for Intergovernmental Organisations    
Methodology: Sample Survey   
Caveats / Comments: Data is only available for Liberia.

* ATTRIBUTES OF INTEREST: Country, Respid, Gender, Age, Educ, Corganizedae   


---
## 3W Dataset on the Organizations Involved in the Response to the Ebola Crisis
### source: https://data.humdata.org/dataset/3w-dataset-on-the-organizations-involved-in-the-response-to-the-ebola-crisis
### files: orgs_involved.csv
Who, What, Where (3W) dataset on the Ebola response effort. Some entries have a
maximum level of desegregation up to administrative level 3. The dataset
contains data from Guinea, Liberia, Sierra Leone, and Nigeria.

This dataset is updated weekly. Last Update 17 Nov. 2014

Note: If your humanitarian organization would like to make a correction or
update the dataset, please contact the OCHA focal point for the respective
country. Contacts can be found at
https://wca.humanitarianresponse.info/fr/emergencies/virus-ebola

#### METADATA
Source: UNOCHA ROWCA    
Contributor: OCHA ROWCA  
Date of Dataset: Dec 05, 2014  
Location: Guinea,  Liberia,  Nigeria,  Sierra Leone  
Visibility: Public  
License: Public Domain / No Restrictions 
Methodology: Census  
Caveats / Comments: Data includes Nigeria, which will be omitted.

* ATTRIBUTES OF INTEREST: Country, Acronym, Organization, Type   


---
## Data on Country Statistics
### source: https://www.cia.gov/library/publications/the-world-factbook/
### files: CIA_World_Factbook.csv
Dataset on statistics for Liberia, Sierra Leone, and Guinea.
Includes: what percentage of the country’s population is urban, health expenditures as a percentage of GDP, and GDP per capita in US dollars.

Note: We pulled the data from the website for our 3 countries of interest, as there wasn’t a file to download.

* ATTRIBUTES OF INTEREST: Country, Urban_pop, Health_exp, GDP_cap   


---
## ANOMALIES  
Note: Our survey dataset only includes respondents from Liberia.
      Data from the CIA World Facebook is scraped from the site.
