CREATE TABLE `table` (
	`column2` INT(18) UNSIGNED NULL,
	`column3` DECIMAL(10,2) NOT NULL,
	`column1` VARCHAR(10) NULL,
	PRIMARY KEY (`column3`),
	CONSTRAINT `fk3` FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ON DELETE CASCADE
)
