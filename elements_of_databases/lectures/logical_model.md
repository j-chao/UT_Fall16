%  Logical Relationship Model
%  Elements of Databases
%  09-07-2016

---
header-includes:
    - \usepackage{chemfig}
    - \usepackage[version=3]{mhchem}
---
---

## Quiz
        * Which of the following should not be implemented as tables in logical
          databse model?
            - One-to-many relationships

## Conceptual Model
        * highest level organization
        * not concerned with primary/foreign keys

## Logical Relationship Model
        * Junction table req. for many-many relationships
        * Relational Databse:  no lists/complex types allowed, only scalar
          values
        * should be close to table structure
        * trace dependencies by starting with FK, and finding dependent tables

## Foreign Key 
        > A foreign key (FK) is a column or combination of columns that is used
        > to establish and enforce a link between the data in two tables to
        > control the data that can be stored in the foreign key table.  In a
        > foreign key reference, a link is created between two tables when the
        > column or columns that hold the primary key value for one table are
        > referenced by the column or columns in another table.  This column
        > becomes a foreign key in the second table.  For example, the
        > Sales.SalesOrderHeader table has a foreign key link to the
        > Sales.SalesPerson table because there is a logical relationship
        > between sales orders and salespeople. The SalesPersonID column in the
        > SalesOrderHeader table matches the primary key column of the
        > SalesPerson table. The SalesPersonID column in the SalesOrderHeader
        > table is the foreign key to the SalesPerson table. By creating this
        > foreign key relationship, a value for SalesPersonID cannot be inserted
        > into the SalesOrderHeader table if it does not already exist in the
        > SalesPerson table.

## Supertype / Subtype
        * DBMS doesn't differentiate b/w supertype and subtype
        * these relationships are only for our design reference/concept
        * FK should point back to immediate parent table, not root
