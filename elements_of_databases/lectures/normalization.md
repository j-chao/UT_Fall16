%  Normalization
%  Elements of Databases
%  09-12-2016

# Unnormalized -> 1NF
    * A schema is in 1NF iff all attributes have scalar values
    * Functional Dependencies: 
        - if 2 records agree on attributes A1, then they must also agree on the
          attributes B1
        - one way relationship

# 1NF -> 2NF
    * 2NF iff it is in 1NF and there exists no partial Functional dependencies
      on the PK
    * FDs confirmed by business reqs. / someone who knows the datasets
    * may de-compile table to multiple tables
        - solve data inconsistency issues & redundancy
        - easier to update
        
# 2NF -> 3NF
    * 3NF iff it is in 2NF and there exists no non-key attributes that depend on
      other non-key attributes
