CREATE TABLE "table" (
	`column2` INTEGER,
	`column3` NUMERIC(10,2) NOT NULL,
	`column1` VARCHAR(10),
	PRIMARY KEY ("column3"),
	CONSTRAINT `fk3` FOREIGN KEY ("column1") REFERENCES `ref_table`("column2") ON DELETE CASCADE
)
