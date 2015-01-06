<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          Rack Lin <racklin@gmail.com>                         |
  +------------------------------------------------------------------------+
*/

use Phalcon\Db\Column as Column;
use Phalcon\Db\Index as Index;
use Phalcon\Db\Reference as Reference;

class DbDialectTest extends PHPUnit_Framework_TestCase
{

	private function getColumns()
	{
		return array(
			'column1' => new Column("column1", array(
				'type' => Column::TYPE_VARCHAR,
				'size' => 10
			)),
			'column2' => new Column("column2", array(
				'type' => Column::TYPE_INTEGER,
				'size' => 18,
				'unsigned' => true,
				'notNull' => false
			)),
			'column3' => new Column("column3", array(
				'type' => Column::TYPE_DECIMAL,
				'size' => 10,
				'scale' => 2,
				'unsigned' => false,
				'notNull' => true
			)),
			'column4' => new Column("column4", array(
				'type' => Column::TYPE_CHAR,
				'size' => 100,
				'notNull' => true
			)),
			'column5' => new Column("column5", array(
				'type' => Column::TYPE_DATE,
				'notNull' => true
			)),
			'column6' => new Column("column6", array(
				'type' => Column::TYPE_DATETIME,
				'notNull' => true
			)),
			'column7' => new Column("column7", array(
				'type' => Column::TYPE_TEXT,
				'notNull' => true
			)),
			'column8' => new Column("column8", array(
				'type' => Column::TYPE_FLOAT,
				'size' => 10,
				'scale' => 2,
				'unsigned' => false,
				'notNull' => true
			))
		);
	}

	private function getIndexes()
	{
		return array(
			'index1' => new Index("index1", array('column1')),
			'index2' => new Index("index2", array('column1', 'column2')),
			'PRIMARY' => new Index("PRIMARY", array('column3')),
			'index4' => new Index("index4", array('column4'), 'UNIQUE'),
		);
	}

	private function getReferences()
	{
		return array(
			'fk1' => new Reference("fk1", array(
				'referencedTable' => 'ref_table',
				'columns' => array('column1'),
				'referencedColumns' => array('column2')
			)),
			'fk2' => new Reference("fk2", array(
				'referencedTable' => 'ref_table',
				'columns' => array('column3', 'column4'),
				'referencedColumns' => array('column5', 'column6')
			)),
		);
	}

	public function testDbColumn()
	{

		$columns = $this->getColumns();

		//Varchar column
		$column1 = $columns['column1'];

		$this->assertEquals($column1->getName(), 'column1');
		$this->assertEquals($column1->getType(), Column::TYPE_VARCHAR);
		$this->assertEquals($column1->getSize(), 10);
		$this->assertEquals($column1->getScale(), 0);
		$this->assertFalse($column1->isUnsigned());
		$this->assertFalse($column1->isNotNull());

		//Integer column
		$column2 = $columns['column2'];

		$this->assertEquals($column2->getName(), 'column2');
		$this->assertEquals($column2->getType(), Column::TYPE_INTEGER);
		$this->assertEquals($column2->getSize(), 18);
		$this->assertEquals($column2->getScale(), 0);
		$this->assertTrue($column2->isUnsigned());
		$this->assertFalse($column2->isNotNull());

		//Decimal column
		$column3 = $columns['column3'];

		$this->assertEquals($column3->getName(), 'column3');
		$this->assertEquals($column3->getType(), Column::TYPE_DECIMAL);
		$this->assertEquals($column3->getSize(), 10);
		$this->assertEquals($column3->getScale(), 2);
		$this->assertFalse($column3->isUnsigned());
		$this->assertTrue($column3->isNotNull());

		//Char column
		$column4 = $columns['column4'];

		$this->assertEquals($column4->getName(), 'column4');
		$this->assertEquals($column4->getType(), Column::TYPE_CHAR);
		$this->assertEquals($column4->getSize(), 100);
		$this->assertEquals($column4->getScale(), 0);
		$this->assertFalse($column4->isUnsigned());
		$this->assertTrue($column4->isNotNull());

		//Date column
		$column5 = $columns['column5'];

		$this->assertEquals($column5->getName(), 'column5');
		$this->assertEquals($column5->getType(), Column::TYPE_DATE);
		$this->assertEquals($column5->getSize(), 0);
		$this->assertEquals($column5->getScale(), 0);
		$this->assertFalse($column5->isUnsigned());
		$this->assertTrue($column5->isNotNull());

		//Datetime column
		$column6 = $columns['column6'];

		$this->assertEquals($column6->getName(), 'column6');
		$this->assertEquals($column6->getType(), Column::TYPE_DATETIME);
		$this->assertEquals($column6->getSize(), 0);
		$this->assertEquals($column6->getScale(), 0);
		$this->assertFalse($column6->isUnsigned());
		$this->assertTrue($column6->isNotNull());

		//Text column
		$column7 = $columns['column7'];

		$this->assertEquals($column7->getName(), 'column7');
		$this->assertEquals($column7->getType(), Column::TYPE_TEXT);
		$this->assertEquals($column7->getSize(), 0);
		$this->assertEquals($column7->getScale(), 0);
		$this->assertFalse($column7->isUnsigned());
		$this->assertTrue($column7->isNotNull());

		//Float column
		$column8 = $columns['column8'];

		$this->assertEquals($column8->getName(), 'column8');
		$this->assertEquals($column8->getType(), Column::TYPE_FLOAT);
		$this->assertEquals($column8->getSize(), 10);
		$this->assertEquals($column8->getScale(), 2);
		$this->assertFalse($column8->isUnsigned());
		$this->assertTrue($column8->isNotNull());
	}

	public function testIndexes()
	{

		$indexes = $this->getIndexes();

		$index1 = $indexes['index1'];
		$this->assertEquals($index1->getName(), 'index1');
		$this->assertEquals($index1->getColumns(), array('column1'));

		$index2 = $indexes['index2'];
		$this->assertEquals($index2->getName(), 'index2');
		$this->assertEquals($index2->getColumns(), array('column1', 'column2'));

		$index3 = $indexes['PRIMARY'];
		$this->assertEquals($index3->getName(), 'PRIMARY');
		$this->assertEquals($index3->getColumns(), array('column3'));

		$index4 = $indexes['index4'];
		$this->assertEquals($index4->getName(), 'index4');
		$this->assertEquals($index4->getColumns(), array('column4'));
		$this->assertEquals($index4->getType(), 'UNIQUE');

	}

	public function testReferences()
	{

		$references = $this->getReferences();

		$reference1 = $references['fk1'];
		$this->assertEquals($reference1->getName(), 'fk1');
		$this->assertEquals($reference1->getColumns(), array('column1'));
		$this->assertEquals($reference1->getReferencedTable(), 'ref_table');
		$this->assertEquals($reference1->getReferencedColumns(), array('column2'));

		$reference2 = $references['fk2'];
		$this->assertEquals($reference2->getName(), 'fk2');
		$this->assertEquals($reference2->getColumns(), array('column3', 'column4'));
		$this->assertEquals($reference2->getReferencedTable(), 'ref_table');
		$this->assertEquals($reference2->getReferencedColumns(), array('column5', 'column6'));

	}

	public function testSavepoints()
	{
	// MySQL
		$dialect = new \Phalcon\Db\Dialect\Mysql();

		$this->assertEquals($dialect->createSavepoint('PHALCON_SAVEPOINT_1'), 'SAVEPOINT PHALCON_SAVEPOINT_1');
		$this->assertEquals($dialect->releaseSavepoint('PHALCON_SAVEPOINT_1'), 'RELEASE SAVEPOINT PHALCON_SAVEPOINT_1');
		$this->assertEquals($dialect->rollbackSavepoint('PHALCON_SAVEPOINT_1'), 'ROLLBACK TO SAVEPOINT PHALCON_SAVEPOINT_1');
		$this->assertTrue($dialect->supportsSavepoints());
		$this->assertTrue($dialect->supportsReleaseSavepoints());

	// SQLite
		$dialect = new \Phalcon\Db\Dialect\Sqlite();

		$this->assertEquals($dialect->createSavepoint('PHALCON_SAVEPOINT_1'), 'SAVEPOINT PHALCON_SAVEPOINT_1');
		$this->assertEquals($dialect->releaseSavepoint('PHALCON_SAVEPOINT_1'), 'RELEASE SAVEPOINT PHALCON_SAVEPOINT_1');
		$this->assertEquals($dialect->rollbackSavepoint('PHALCON_SAVEPOINT_1'), 'ROLLBACK TO SAVEPOINT PHALCON_SAVEPOINT_1');
		$this->assertTrue($dialect->supportsSavepoints());
		$this->assertTrue($dialect->supportsReleaseSavepoints());
	}

	public function testMysqlDialect()
	{

		$dialect = new \Phalcon\Db\Dialect\Mysql();

		$columns = $dialect->getColumnList(array('column1', 'column2', 'column3'));
		$this->assertEquals($columns, "`column1`, `column2`, `column3`");

		$columns = $this->getColumns();

		//Column definitions
		$this->assertEquals($dialect->getColumnDefinition($columns['column1']), 'VARCHAR(10)');
		$this->assertEquals($dialect->getColumnDefinition($columns['column2']), 'INT(18) UNSIGNED');
		$this->assertEquals($dialect->getColumnDefinition($columns['column3']), 'DECIMAL(10,2)');
		$this->assertEquals($dialect->getColumnDefinition($columns['column4']), 'CHAR(100)');
		$this->assertEquals($dialect->getColumnDefinition($columns['column5']), 'DATE');
		$this->assertEquals($dialect->getColumnDefinition($columns['column6']), 'DATETIME');
		$this->assertEquals($dialect->getColumnDefinition($columns['column7']), 'TEXT');
		$this->assertEquals($dialect->getColumnDefinition($columns['column8']), 'FLOAT(10,2)');

		//Add Columns
		$this->assertEquals($dialect->addColumn('table', null, $columns['column1']), 'ALTER TABLE `table` ADD `column1` VARCHAR(10)');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column1']), 'ALTER TABLE `schema`.`table` ADD `column1` VARCHAR(10)');
		$this->assertEquals($dialect->addColumn('table', null, $columns['column2']), 'ALTER TABLE `table` ADD `column2` INT(18) UNSIGNED');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column2']), 'ALTER TABLE `schema`.`table` ADD `column2` INT(18) UNSIGNED');
		$this->assertEquals($dialect->addColumn('table', null, $columns['column3']), 'ALTER TABLE `table` ADD `column3` DECIMAL(10,2) NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column3']), 'ALTER TABLE `schema`.`table` ADD `column3` DECIMAL(10,2) NOT NULL');
		$this->assertEquals($dialect->addColumn('table', null, $columns['column4']), 'ALTER TABLE `table` ADD `column4` CHAR(100) NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column4']), 'ALTER TABLE `schema`.`table` ADD `column4` CHAR(100) NOT NULL');
		$this->assertEquals($dialect->addColumn('table', null, $columns['column5']), 'ALTER TABLE `table` ADD `column5` DATE NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column5']), 'ALTER TABLE `schema`.`table` ADD `column5` DATE NOT NULL');
		$this->assertEquals($dialect->addColumn('table', null, $columns['column6']), 'ALTER TABLE `table` ADD `column6` DATETIME NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column6']), 'ALTER TABLE `schema`.`table` ADD `column6` DATETIME NOT NULL');
		$this->assertEquals($dialect->addColumn('table', null, $columns['column7']), 'ALTER TABLE `table` ADD `column7` TEXT NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column7']), 'ALTER TABLE `schema`.`table` ADD `column7` TEXT NOT NULL');
		$this->assertEquals($dialect->addColumn('table', null, $columns['column8']), 'ALTER TABLE `table` ADD `column8` FLOAT(10,2) NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column8']), 'ALTER TABLE `schema`.`table` ADD `column8` FLOAT(10,2) NOT NULL');
		//Modify Columns
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column1']), 'ALTER TABLE `table` MODIFY `column1` VARCHAR(10)');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column1']), 'ALTER TABLE `schema`.`table` MODIFY `column1` VARCHAR(10)');
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column2']), 'ALTER TABLE `table` MODIFY `column2` INT(18) UNSIGNED');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column2']), 'ALTER TABLE `schema`.`table` MODIFY `column2` INT(18) UNSIGNED');
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column3']), 'ALTER TABLE `table` MODIFY `column3` DECIMAL(10,2) NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column3']), 'ALTER TABLE `schema`.`table` MODIFY `column3` DECIMAL(10,2) NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column4']), 'ALTER TABLE `table` MODIFY `column4` CHAR(100) NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column4']), 'ALTER TABLE `schema`.`table` MODIFY `column4` CHAR(100) NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column5']), 'ALTER TABLE `table` MODIFY `column5` DATE NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column5']), 'ALTER TABLE `schema`.`table` MODIFY `column5` DATE NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column6']), 'ALTER TABLE `table` MODIFY `column6` DATETIME NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column6']), 'ALTER TABLE `schema`.`table` MODIFY `column6` DATETIME NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column7']), 'ALTER TABLE `table` MODIFY `column7` TEXT NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column7']), 'ALTER TABLE `schema`.`table` MODIFY `column7` TEXT NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column8']), 'ALTER TABLE `table` MODIFY `column8` FLOAT(10,2) NOT NULL');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column8']), 'ALTER TABLE `schema`.`table` MODIFY `column8` FLOAT(10,2) NOT NULL');

		//Drop Columns
		$this->assertEquals($dialect->dropColumn('table', null, 'column1'), 'ALTER TABLE `table` DROP COLUMN `column1`');
		$this->assertEquals($dialect->dropColumn('table', 'schema', 'column1'), 'ALTER TABLE `schema`.`table` DROP COLUMN `column1`');

		$indexes = $this->getIndexes();

		//Add Index
		$this->assertEquals($dialect->addIndex('table', null, $indexes['index1']), 'ALTER TABLE `table` ADD INDEX `index1` (`column1`)');
		$this->assertEquals($dialect->addIndex('table', 'schema', $indexes['index1']), 'ALTER TABLE `schema`.`table` ADD INDEX `index1` (`column1`)');
		$this->assertEquals($dialect->addIndex('table', null, $indexes['index2']), 'ALTER TABLE `table` ADD INDEX `index2` (`column1`, `column2`)');
		$this->assertEquals($dialect->addIndex('table', 'schema', $indexes['index2']), 'ALTER TABLE `schema`.`table` ADD INDEX `index2` (`column1`, `column2`)');
		$this->assertEquals($dialect->addIndex('table', null, $indexes['PRIMARY']), 'ALTER TABLE `table` ADD INDEX `PRIMARY` (`column3`)');
		$this->assertEquals($dialect->addIndex('table', 'schema', $indexes['PRIMARY']), 'ALTER TABLE `schema`.`table` ADD INDEX `PRIMARY` (`column3`)');
		$this->assertEquals($dialect->addIndex('table', null, $indexes['index4']), 'ALTER TABLE `table` ADD UNIQUE INDEX `index4` (`column4`)');
		$this->assertEquals($dialect->addIndex('table', 'schema', $indexes['index4']), 'ALTER TABLE `schema`.`table` ADD UNIQUE INDEX `index4` (`column4`)');

		//Drop Index
		$this->assertEquals($dialect->dropIndex('table', null, 'index1'), 'ALTER TABLE `table` DROP INDEX `index1`');
		$this->assertEquals($dialect->dropIndex('table', 'schema', 'index1'), 'ALTER TABLE `schema`.`table` DROP INDEX `index1`');

		//Add Primary Key
		$this->assertEquals($dialect->addPrimaryKey('table', null, $indexes['PRIMARY']), 'ALTER TABLE `table` ADD PRIMARY KEY (`column3`)');
		$this->assertEquals($dialect->addPrimaryKey('table', 'schema', $indexes['PRIMARY']), 'ALTER TABLE `schema`.`table` ADD PRIMARY KEY (`column3`)');

		//Drop Primary Key
		$this->assertEquals($dialect->dropPrimaryKey('table', null), 'ALTER TABLE `table` DROP PRIMARY KEY');
		$this->assertEquals($dialect->dropPrimaryKey('table', 'schema'), 'ALTER TABLE `schema`.`table` DROP PRIMARY KEY');

		$references = $this->getReferences();

		//Add Foreign Key
		$this->assertEquals($dialect->addForeignKey('table', null, $references['fk1']), 'ALTER TABLE `table` ADD CONSTRAINT `fk1` FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`)');
		$this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk1']), 'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk1` FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`)');
		$this->assertEquals($dialect->addForeignKey('table', null, $references['fk2']), 'ALTER TABLE `table` ADD CONSTRAINT `fk2` FOREIGN KEY (`column3`, `column4`) REFERENCES `ref_table`(`column5`, `column6`)');
		$this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk2']), 'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk2` FOREIGN KEY (`column3`, `column4`) REFERENCES `ref_table`(`column5`, `column6`)');

		$this->assertEquals($dialect->dropForeignKey('table', null, 'fk1'), 'ALTER TABLE `table` DROP FOREIGN KEY `fk1`');
		$this->assertEquals($dialect->dropForeignKey('table', 'schema', 'fk1'), 'ALTER TABLE `schema`.`table` DROP FOREIGN KEY `fk1`');

		//Create tables
		$definition = array(
			'columns' => array(
				$columns['column1'],
				$columns['column2'],
			)
		);

		$expected  = "CREATE TABLE `table` (\n";
		$expected .= "	`column1` VARCHAR(10),\n";
		$expected .= "	`column2` INT(18) UNSIGNED\n";
		$expected .= ")";
		$this->assertEquals($dialect->createTable('table', null, $definition), $expected);

		$definition = array(
			'columns' => array(
				$columns['column2'],
				$columns['column3'],
				$columns['column1'],
			),
			'indexes' => array(
				$indexes['PRIMARY']
			)
		);

		$expected  = "CREATE TABLE `table` (\n";
		$expected .= "	`column2` INT(18) UNSIGNED,\n";
		$expected .= "	`column3` DECIMAL(10,2) NOT NULL,\n";
		$expected .= "	`column1` VARCHAR(10),\n";
		$expected .= "	PRIMARY KEY (`column3`)\n";
		$expected .= ")";
		$this->assertEquals($dialect->createTable('table', null, $definition), $expected);

	}

	public function testSQLiteDialect()
	{

		$dialect = new \Phalcon\Db\Dialect\Sqlite();

		$columns = $dialect->getColumnList(array('column1', 'column2', 'column3'));
		$this->assertEquals($columns, '"column1", "column2", "column3"');

		$columns = $this->getColumns();

		//Column definitions
		$this->assertEquals($dialect->getColumnDefinition($columns['column1']), 'VARCHAR(10)');
		$this->assertEquals($dialect->getColumnDefinition($columns['column2']), 'INT');
		$this->assertEquals($dialect->getColumnDefinition($columns['column3']), 'NUMERIC(10,2)');
		$this->assertEquals($dialect->getColumnDefinition($columns['column4']), 'CHARACTER(100)');
		$this->assertEquals($dialect->getColumnDefinition($columns['column5']), 'DATE');
		$this->assertEquals($dialect->getColumnDefinition($columns['column6']), 'TIMESTAMP');
		$this->assertEquals($dialect->getColumnDefinition($columns['column7']), 'TEXT');
		$this->assertEquals($dialect->getColumnDefinition($columns['column8']), 'FLOAT');

		//Add Columns
		$this->assertEquals($dialect->addColumn('table', null,     $columns['column1']), 'ALTER TABLE "table" ADD COLUMN "column1" VARCHAR(10)');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column1']), 'ALTER TABLE "schema"."table" ADD COLUMN "column1" VARCHAR(10)');
		$this->assertEquals($dialect->addColumn('table', null,     $columns['column2']), 'ALTER TABLE "table" ADD COLUMN "column2" INT');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column2']), 'ALTER TABLE "schema"."table" ADD COLUMN "column2" INT');
		$this->assertEquals($dialect->addColumn('table', null,     $columns['column3']), 'ALTER TABLE "table" ADD COLUMN "column3" NUMERIC(10,2) NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column3']), 'ALTER TABLE "schema"."table" ADD COLUMN "column3" NUMERIC(10,2) NOT NULL');
		$this->assertEquals($dialect->addColumn('table', null,     $columns['column4']), 'ALTER TABLE "table" ADD COLUMN "column4" CHARACTER(100) NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column4']), 'ALTER TABLE "schema"."table" ADD COLUMN "column4" CHARACTER(100) NOT NULL');
		$this->assertEquals($dialect->addColumn('table', null,     $columns['column5']), 'ALTER TABLE "table" ADD COLUMN "column5" DATE NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column5']), 'ALTER TABLE "schema"."table" ADD COLUMN "column5" DATE NOT NULL');
		$this->assertEquals($dialect->addColumn('table', null,     $columns['column6']), 'ALTER TABLE "table" ADD COLUMN "column6" TIMESTAMP NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column6']), 'ALTER TABLE "schema"."table" ADD COLUMN "column6" TIMESTAMP NOT NULL');
		$this->assertEquals($dialect->addColumn('table', null,     $columns['column7']), 'ALTER TABLE "table" ADD COLUMN "column7" TEXT NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column7']), 'ALTER TABLE "schema"."table" ADD COLUMN "column7" TEXT NOT NULL');
		$this->assertEquals($dialect->addColumn('table', null,     $columns['column8']), 'ALTER TABLE "table" ADD COLUMN "column8" FLOAT NOT NULL');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column8']), 'ALTER TABLE "schema"."table" ADD COLUMN "column8" FLOAT NOT NULL');

		//Modify Columns
		try {
			$dialect->modifyColumn('table', null, $columns['column1']);
			$this->assertTrue(false);
		}
		catch (Phalcon\Db\Exception $ex) {
			$this->assertTrue(true);
		}
		catch (Exception $e) {
			$this->assertTrue(false);
		}

		//Drop Columns
		try {
			$dialect->dropColumn('table', null, 'column1');
			$this->assertTrue(false);
		}
		catch (Phalcon\Db\Exception $ex) {
			$this->assertTrue(true);
		}
		catch (Exception $e) {
			$this->assertTrue(false);
		}

		$indexes = $this->getIndexes();

		//Add Index
		$this->assertEquals($dialect->addIndex('table', null,     $indexes['index1']),  'CREATE INDEX "index1" ON "table" ("column1")');
		$this->assertEquals($dialect->addIndex('table', 'schema', $indexes['index1']),  'CREATE INDEX "schema"."index1" ON "table" ("column1")');
		$this->assertEquals($dialect->addIndex('table', null,     $indexes['index2']),  'CREATE INDEX "index2" ON "table" ("column1", "column2")');
		$this->assertEquals($dialect->addIndex('table', 'schema', $indexes['index2']),  'CREATE INDEX "schema"."index2" ON "table" ("column1", "column2")');

		//Drop Index
		$this->assertEquals($dialect->dropIndex('table', null, 'index1'), 'DROP INDEX "index1"');
		$this->assertEquals($dialect->dropIndex('table', 'schema', 'index1'), 'DROP INDEX "schema"."index1"');

		//Add Primary Key
		try {
			$dialect->addPrimaryKey('table', null, $indexes['PRIMARY']);
			$this->assertTrue(false);
		}
		catch (Phalcon\Db\Exception $ex) {
			$this->assertTrue(true);
		}
		catch (Exception $e) {
			$this->assertTrue(false);
		}

		//Drop Primary Key
		try {
			$dialect->dropPrimaryKey('table', null);
			$this->assertTrue(false);
		}
		catch (Phalcon\Db\Exception $ex) {
			$this->assertTrue(true);
		}
		catch (Exception $e) {
			$this->assertTrue(false);
		}

		$references = $this->getReferences();

		//Add Foreign Key
		try {
			$dialect->addForeignKey('table', null, $references['fk1']);
			$this->assertTrue(false);
		}
		catch (Phalcon\Db\Exception $ex) {
			$this->assertTrue(true);
		}
		catch (Exception $e) {
			$this->assertTrue(false);
		}

		try {
			$dialect->dropForeignKey('table', null, 'fk1');
			$this->assertTrue(false);
		}
		catch (Phalcon\Db\Exception $ex) {
			$this->assertTrue(true);
		}
		catch (Exception $e) {
			$this->assertTrue(false);
		}

		//Create tables
		// Not implemented yet
	}

	public function testViews()
	{
	// MySQL
		$dialect = new \Phalcon\Db\Dialect\Mysql();

		$definition = array(
			'sql' => 'SELECT 1',
		);

		//Create View
		$this->assertEquals($dialect->createView('test_view', $definition, null), 'CREATE VIEW `test_view` AS SELECT 1');
		$this->assertEquals($dialect->createView('test_view', $definition, 'schema'), 'CREATE VIEW `schema`.`test_view` AS SELECT 1');

		//Drop View
		$this->assertEquals($dialect->dropView('test_view', null, false), 'DROP VIEW test_view');
		$this->assertEquals($dialect->dropView('test_view', null, true), 'DROP VIEW IF EXISTS test_view');
		$this->assertEquals($dialect->dropView('test_view', 'schema', false), 'DROP VIEW schema.test_view');
		$this->assertEquals($dialect->dropView('test_view', 'schema', true), 'DROP VIEW IF EXISTS schema.test_view');

		$this->assertEquals($dialect->listViews(), 'SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` ORDER BY view_name');

	// SQLite
		$dialect = new \Phalcon\Db\Dialect\Sqlite();

		//Create View
		$this->assertEquals($dialect->createView('test_view', $definition, null), 'CREATE VIEW "test_view" AS SELECT 1');
		$this->assertEquals($dialect->createView('test_view', $definition, 'schema'), 'CREATE VIEW "schema"."test_view" AS SELECT 1');

		//Drop View
		$this->assertEquals($dialect->dropView('test_view', null, false), 'DROP VIEW "test_view"');
		$this->assertEquals($dialect->dropView('test_view', null, true), 'DROP VIEW IF EXISTS "test_view"');
		$this->assertEquals($dialect->dropView('test_view', 'schema', false), 'DROP VIEW "schema"."test_view"');
		$this->assertEquals($dialect->dropView('test_view', 'schema', true), 'DROP VIEW IF EXISTS "schema"."test_view"');

		$this->assertEquals($dialect->listViews(), "SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name");
	}

}
