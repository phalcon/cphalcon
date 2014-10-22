SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

CREATE DATABASE IF NOT EXISTS `phalcon_test` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
USE `phalcon_test`;

DROP TABLE IF EXISTS `ph_select`;
CREATE TABLE IF NOT EXISTS `ph_select` (
  `sel_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `sel_name` varchar(16) COLLATE utf8_unicode_ci NOT NULL,
  `sel_text` varchar(32) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`sel_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=9 ;

INSERT INTO `ph_select` (`sel_id`, `sel_name`, `sel_text`) VALUES
  (1, 'Sun', 'The one and only'),
  (2, 'Mercury', 'Cold and hot'),
  (3, 'Venus', 'Yeah baby she''s got it'),
  (4, 'Earth', 'Home'),
  (5, 'Mars', 'The God of War'),
  (6, 'Jupiter', NULL),
  (7, 'Saturn', 'A car'),
  (8, 'Uranus', 'Loads of jokes for this one');
