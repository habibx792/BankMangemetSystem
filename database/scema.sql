CREATE DATABASE Bank;
GO

USE Bank;
GO

CREATE TABLE personTb
( 
    personCnic VARCHAR(50) PRIMARY KEY,
    personName VARCHAR(50),
    personFatherName VARCHAR(50),
    personAge INT
);

CREATE TABLE personAdressTb
(
    addressId INT IDENTITY(1,1) PRIMARY KEY,
    personCnic VARCHAR(50),
    countryName VARCHAR(50),
    provisinceName VARCHAR(50),
    cityName VARCHAR(50),
    streetNo INT,
    postalCode INT,
    personType VARCHAR(50),
    CONSTRAINT fk_personAdressTb_personTb
        FOREIGN KEY (personCnic)
        REFERENCES personTb(personCnic)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE customerTb
(
    personCnic VARCHAR(50) PRIMARY KEY,
    customerAccountNo VARCHAR(50),
    customerAccountType VARCHAR(50),
    CONSTRAINT fk_customerTb_personTb
        FOREIGN KEY (personCnic)
        REFERENCES personTb(personCnic)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);


CREATE TABLE accountTb
(
    accountNo VARCHAR(50) PRIMARY KEY,
    personCnic VARCHAR(50) NOT NULL,
    accountType VARCHAR(50),
    accountStatus VARCHAR(50) DEFAULT 'block',
    currentAccountBalance FLOAT DEFAULT 0,
    CONSTRAINT fk_accountTb_personTb
        FOREIGN KEY (personCnic)
        REFERENCES personTb(personCnic)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE adminTb
(
    personCnic VARCHAR(50) PRIMARY KEY,
    CONSTRAINT fk_adminTb_personTb
        FOREIGN KEY (personCnic)
        REFERENCES personTb(personCnic)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE salaryTb
(   
    personCnic VARCHAR(50) PRIMARY KEY,
    employeeSalary FLOAT,
    monthlyBonus FLOAT,
    yearlyBonus FLOAT,
    yearlyIncreament FLOAT,
    CONSTRAINT fk_salaryTb_personTb
        FOREIGN KEY (personCnic)
        REFERENCES personTb(personCnic)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE ownerTb
(
    personCnic VARCHAR(50) PRIMARY KEY,
    CONSTRAINT fk_ownerTb_personTb
        FOREIGN KEY (personCnic)
        REFERENCES personTb(personCnic)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE transactionTb
(
    TrasactionId VARCHAR(50) PRIMARY KEY,
    tractsionType VARCHAR(50),
    dateTrac DATE,
    customerAccountNo VARCHAR(50),
    personCnic VARCHAR(50),
    CONSTRAINT fk_transactionTb_accountTb
        FOREIGN KEY (customerAccountNo)
        REFERENCES accountTb(accountNo)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    CONSTRAINT fk_transactionTb_personTb
        FOREIGN KEY (personCnic)
        REFERENCES personTb(personCnic)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE feedBackTb
(
    userName VARCHAR(50),
    issue VARCHAR(1000)
);

CREATE TABLE setMarkRateTb
(
    loanId INT IDENTITY(1,1) PRIMARY KEY,
    loanType VARCHAR(20),
    markUpRate FLOAT
);

CREATE TABLE loanaTb
(
    loanId INT IDENTITY(1,1) PRIMARY KEY, 
    customerAccountNo VARCHAR(50),
    personCnic VARCHAR(50),
    loanType VARCHAR(50),
    durationYear INT,
    loanAmount FLOAT,
    markUpRate FLOAT,
    loanIssueDate DATE DEFAULT GETDATE(),
    loanReturnDate DATE NOT NULL,
    totalMarkup FLOAT,
    CONSTRAINT fk_loanaTb_accountTb
        FOREIGN KEY (customerAccountNo)
        REFERENCES accountTb(accountNo)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    CONSTRAINT fk_loanaTb_personTb
        FOREIGN KEY (personCnic)
        REFERENCES personTb(personCnic)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);