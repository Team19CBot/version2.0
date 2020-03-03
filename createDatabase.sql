CREATE DATABASE cbot_users;
USE cbot_users;

CREATE TABLE teachers 
(
userName varchar(40) NOT NULL,
userPassword varchar(40) NOT NULL,  
PRIMARY KEY (Username)
);

CREATE TABLE the_admin 
(
userName varchar(40) NOT NULL,
userPassword varchar(40) NOT NULL,
PRIMARY KEY (Username)
);

INSERT INTO teachers (userName, userPassword)
VALUES ('scyym2', 'scyym2');
INSERT INTO teachers (userName, userPassword)
VALUES ('zy22133', 'zy22133');
INSERT INTO teachers (userName, userPassword)
VALUES ('scyxx1', 'scyxx1');
INSERT INTO teachers (userName, userPassword)
VALUES ('slyht1', 'slyht1');
INSERT INTO teachers (userName, userPassword)
VALUES ('scyzx1', 'scyzx1');

INSERT INTO the_admin (userName, userPassword)
VALUES ('admin', 'admin');