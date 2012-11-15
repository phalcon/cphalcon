-- User for the database
GRANT ALL PRIVILEGES ON phalcon_test.* TO phalcon_user@localhost IDENTIFIED BY '1234';

-- Table structure for table `customers`
DROP TABLE IF EXISTS `customers`;
CREATE TABLE `customers` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `document_id` int(3) unsigned NOT NULL,
  `customer_id` char(15) COLLATE utf8_unicode_ci NOT NULL,
  `first_name` varchar(100) COLLATE utf8_unicode_ci DEFAULT NULL,
  `last_name` varchar(100) COLLATE utf8_unicode_ci DEFAULT NULL,
  `phone` varchar(20) COLLATE utf8_unicode_ci DEFAULT NULL,
  `email` varchar(70) COLLATE utf8_unicode_ci NOT NULL,
  `instructions` varchar(100) COLLATE utf8_unicode_ci DEFAULT NULL,
  `status` enum('A','I','X') COLLATE utf8_unicode_ci NOT NULL,
  `birth_date` date DEFAULT '1970-01-01',
  `credit_line` decimal(16,2) DEFAULT '0',
  `created_at` datetime NOT NULL,
  `created_at_user_id` int(10) unsigned DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `document_id` (`document_id`),
  KEY `customer_id` (`customer_id`),
  KEY `status` (`status`,`last_name`,`first_name`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Table structure for table `parts`
DROP TABLE IF EXISTS `parts`;
CREATE TABLE `parts` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(70) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Table structure for table `robots`
DROP TABLE IF EXISTS `robots`;
CREATE TABLE `robots` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(70) COLLATE utf8_unicode_ci NOT NULL,
  `type` varchar(32) COLLATE utf8_unicode_ci NOT NULL,
  `year` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Table structure for table `robots_parts`
DROP TABLE IF EXISTS `robots_parts`;
CREATE TABLE `robots_parts` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `robots_id` int(10) unsigned NOT NULL,
  `parts_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `robots_id` (`robots_id`),
  KEY `parts_id` (`parts_id`),
  CONSTRAINT `robots_parts_ibfk_1` FOREIGN KEY (`robots_id`) REFERENCES `robots` (`id`),
  CONSTRAINT `robots_parts_ibfk_2` FOREIGN KEY (`parts_id`) REFERENCES `parts` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;


