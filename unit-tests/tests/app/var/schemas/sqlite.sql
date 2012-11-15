PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;

CREATE TABLE `customers` (
  `id` integer NOT NULL,
  `document_id` int(3) NOT NULL,
  `customer_id` char(15) NOT NULL,
  `first_name` varchar(100) DEFAULT NULL,
  `last_name` varchar(100) DEFAULT NULL,
  `phone` varchar(20) DEFAULT NULL,
  `email` varchar(70) NOT NULL,
  `instructions` varchar(100) DEFAULT NULL,
  `status` char(1) NOT NULL,
  `birth_date` date DEFAULT '1970-01-01',
  `credit_line` decimal(16,2) DEFAULT '0.00',
  `created_at` datetime NOT NULL,
  `created_at_user_id` int(10) DEFAULT '0',
  PRIMARY KEY (`id`)
);

CREATE TABLE `parts` (
  `id` integer NOT NULL,
  `name` varchar(70) NOT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `robots` (
  `id` integer NOT NULL,
  `name` varchar(70) NOT NULL,
  `type` varchar(32) NOT NULL,
  `year` int(11) NOT NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `robots_parts` (
  `id` integer NOT NULL,
  `robots_id` int(10) NOT NULL,
  `parts_id` int(10) NOT NULL,
  PRIMARY KEY (`id`)
);

COMMIT;