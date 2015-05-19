<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
			)),
			'column9' => new Column("column9", array(
				'type' => Column::TYPE_VARCHAR,
				'size' => 10,
				'default' => 'column9'
			)),
			'column10' => new Column("column10", array(
				'type' => Column::TYPE_INTEGER,
				'size' => 18,
				'unsigned' => true,
				'notNull' => false,
				'default' => 10,
			)),
			'column11' => new Column("column11", array(
				'type' => 'BIGINT',
				'typeReference' => Column::TYPE_INTEGER,
				'size' => 20,
				'unsigned' => true,
				'notNull' => false
			)),
			'column12' => new Column("column12", array(
				'type' => 'ENUM',
				'typeValues' => array('A', 'B', 'C'),
				'notNull' => true,
				'default' => 'A'
			)),
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
			'fk3' => new Reference("fk3", array(
				'referencedTable' => 'ref_table',
				'columns' => array('column1'),
				'referencedColumns' => array('column2'),
				'onDelete' => 'CASCADE',
			)),
			'fk4' => new Reference("fk4", array(
				'referencedTable' => 'ref_table',
				'columns' => array('column1'),
				'referencedColumns' => array('column2'),
				'onUpdate' => 'SET NULL',
			)),
			'fk5' => new Reference("fk5", array(
				'referencedTable' => 'ref_table',
				'columns' => array('column1'),
				'referencedColumns' => array('column2'),
				'onDelete' => 'CASCADE',
				'onUpdate' => 'NO ACTION',
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

		//Varchar column + default value
		$column9 = $columns['column9'];

		$this->assertEquals($column9->getName(), 'column9');
		$this->assertEquals($column9->getType(), Column::TYPE_VARCHAR);
		$this->assertEquals($column9->getSize(), 10);
		$this->assertEquals($column9->getScale(), 0);
		$this->assertFalse($column9->isUnsigned());
		$this->assertFalse($column9->isNotNull());
		$this->assertEquals($column9->getDefault(), 'column9');

		//Integer column + default value
		$column10 = $columns['column10'];

		$this->assertEquals($column10->getName(), 'column10');
		$this->assertEquals($column10->getType(), Column::TYPE_INTEGER);
		$this->assertEquals($column10->getSize(), 18);
		$this->assertEquals($column10->getScale(), 0);
		$this->assertTrue($column10->isUnsigned());
		$this->assertFalse($column10->isNotNull());
		$this->assertEquals($column10->getDefault(), '10');

		//Bigint column
		$column11 = $columns['column11'];

		$this->assertEquals($column11->getName(), 'column11');
		$this->assertEquals($column11->getType(), 'BIGINT');
		$this->assertEquals($column11->getTypeReference(), Column::TYPE_INTEGER);
		$this->assertEquals($column11->getSize(), 20);
		$this->assertEquals($column11->getScale(), 0);
		$this->assertTrue($column11->isUnsigned());
		$this->assertFalse($column11->isNotNull());

		//Enum column
		$column12 = $columns['column12'];

		$this->assertEquals($column12->getName(), 'column12');
		$this->assertEquals($column12->getType(), 'ENUM');
		$this->assertEquals($column12->getTypeReference(), -1);
		$this->assertEquals($column12->getTypeValues(), array('A', 'B', 'C'));
		$this->assertEquals($column12->getSize(), 0);
		$this->assertEquals($column12->getScale(), 0);
		$this->assertFalse($column12->isUnsigned());
		$this->assertTrue($column12->isNotNull());
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
		$this->assertEquals($reference1->getOnDelete(), NULL);
		$this->assertEquals($reference1->getOnUpdate(), NULL);

		$reference2 = $references['fk2'];
		$this->assertEquals($reference2->getName(), 'fk2');
		$this->assertEquals($reference2->getColumns(), array('column3', 'column4'));
		$this->assertEquals($reference2->getReferencedTable(), 'ref_table');
		$this->assertEquals($reference2->getReferencedColumns(), array('column5', 'column6'));
		$this->assertEquals($reference1->getOnDelete(), NULL);
		$this->assertEquals($reference1->getOnUpdate(), NULL);

		$reference3 = $references['fk3'];
		$this->assertEquals($reference3->getName(), 'fk3');
		$this->assertEquals($reference3->getColumns(), array('column1'));
		$this->assertEquals($reference3->getReferencedTable(), 'ref_table');
		$this->assertEquals($reference3->getReferencedColumns(), array('column2'));
		$this->assertEquals($reference3->getOnDelete(), 'CASCADE');
		$this->assertEquals($reference3->getOnUpdate(), NULL);

		$reference4 = $references['fk4'];
		$this->assertEquals($reference4->getName(), 'fk4');
		$this->assertEquals($reference4->getColumns(), array('column1'));
		$this->assertEquals($reference4->getReferencedTable(), 'ref_table');
		$this->assertEquals($reference4->getReferencedColumns(), array('column2'));
		$this->assertEquals($reference4->getOnDelete(), NULL);
		$this->assertEquals($reference4->getOnUpdate(), 'SET NULL');

		$reference5 = $references['fk5'];
		$this->assertEquals($reference5->getName(), 'fk5');
		$this->assertEquals($reference5->getColumns(), array('column1'));
		$this->assertEquals($reference5->getReferencedTable(), 'ref_table');
		$this->assertEquals($reference5->getReferencedColumns(), array('column2'));
		$this->assertEquals($reference5->getOnDelete(), 'CASCADE');
		$this->assertEquals($reference5->getOnUpdate(), 'NO ACTION');

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

    // Postgresql
    $dialect = new \Phalcon\Db\Dialect\Postgresql();

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
		$this->assertEquals($dialect->getColumnDefinition($columns['column9']), 'VARCHAR(10)');
		$this->assertEquals($dialect->getColumnDefinition($columns['column10']), 'INT(18) UNSIGNED');
		$this->assertEquals($dialect->getColumnDefinition($columns['column11']), 'BIGINT(20) UNSIGNED');
		$this->assertEquals($dialect->getColumnDefinition($columns['column12']), "ENUM(\"A\", \"B\", \"C\")");

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
		$this->assertEquals($dialect->addColumn('table', null, $columns['column9']), 'ALTER TABLE `table` ADD `column9` VARCHAR(10) DEFAULT "column9"');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column9']), 'ALTER TABLE `schema`.`table` ADD `column9` VARCHAR(10) DEFAULT "column9"');
		$this->assertEquals($dialect->addColumn('table', null, $columns['column10']), 'ALTER TABLE `table` ADD `column10` INT(18) UNSIGNED DEFAULT "10"');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column10']), 'ALTER TABLE `schema`.`table` ADD `column10` INT(18) UNSIGNED DEFAULT "10"');
		$this->assertEquals($dialect->addColumn('table', null, $columns['column11']), 'ALTER TABLE `table` ADD `column11` BIGINT(20) UNSIGNED');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column11']), 'ALTER TABLE `schema`.`table` ADD `column11` BIGINT(20) UNSIGNED');
		$this->assertEquals($dialect->addColumn('table', null, $columns['column12']), "ALTER TABLE `table` ADD `column12` ENUM(\"A\", \"B\", \"C\") DEFAULT \"A\" NOT NULL");
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column12']), "ALTER TABLE `schema`.`table` ADD `column12` ENUM(\"A\", \"B\", \"C\") DEFAULT \"A\" NOT NULL");

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
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column9']), 'ALTER TABLE `table` MODIFY `column9` VARCHAR(10) DEFAULT "column9"');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column9']), 'ALTER TABLE `schema`.`table` MODIFY `column9` VARCHAR(10) DEFAULT "column9"');
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column10']), 'ALTER TABLE `table` MODIFY `column10` INT(18) UNSIGNED DEFAULT "10"');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column10']), 'ALTER TABLE `schema`.`table` MODIFY `column10` INT(18) UNSIGNED DEFAULT "10"');
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column11']), 'ALTER TABLE `table` MODIFY `column11` BIGINT(20) UNSIGNED');
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column11']), 'ALTER TABLE `schema`.`table` MODIFY `column11` BIGINT(20) UNSIGNED');
		$this->assertEquals($dialect->modifyColumn('table', null, $columns['column12']), "ALTER TABLE `table` MODIFY `column12` ENUM(\"A\", \"B\", \"C\") DEFAULT \"A\" NOT NULL");
		$this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column12']), "ALTER TABLE `schema`.`table` MODIFY `column12` ENUM(\"A\", \"B\", \"C\") DEFAULT \"A\" NOT NULL");

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
		$this->assertEquals($dialect->addForeignKey('table', null, $references['fk1']), 'ALTER TABLE `table` ADD FOREIGN KEY `fk1`(`column1`) REFERENCES `ref_table`(`column2`)');
		$this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk1']), 'ALTER TABLE `schema`.`table` ADD FOREIGN KEY `fk1`(`column1`) REFERENCES `ref_table`(`column2`)');
		$this->assertEquals($dialect->addForeignKey('table', null, $references['fk2']), 'ALTER TABLE `table` ADD FOREIGN KEY `fk2`(`column3`, `column4`) REFERENCES `ref_table`(`column5`, `column6`)');
		$this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk2']), 'ALTER TABLE `schema`.`table` ADD FOREIGN KEY `fk2`(`column3`, `column4`) REFERENCES `ref_table`(`column5`, `column6`)');

		$this->assertEquals($dialect->addForeignKey('table', null, $references['fk3']), 'ALTER TABLE `table` ADD FOREIGN KEY `fk3`(`column1`) REFERENCES `ref_table`(`column2`) ON DELETE CASCADE');
		$this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk3']), 'ALTER TABLE `schema`.`table` ADD FOREIGN KEY `fk3`(`column1`) REFERENCES `ref_table`(`column2`) ON DELETE CASCADE');
		$this->assertEquals($dialect->addForeignKey('table', null, $references['fk4']), 'ALTER TABLE `table` ADD FOREIGN KEY `fk4`(`column1`) REFERENCES `ref_table`(`column2`) ON UPDATE SET NULL');
		$this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk4']), 'ALTER TABLE `schema`.`table` ADD FOREIGN KEY `fk4`(`column1`) REFERENCES `ref_table`(`column2`) ON UPDATE SET NULL');
		$this->assertEquals($dialect->addForeignKey('table', null, $references['fk5']), 'ALTER TABLE `table` ADD FOREIGN KEY `fk5`(`column1`) REFERENCES `ref_table`(`column2`) ON DELETE CASCADE ON UPDATE NO ACTION');
		$this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk5']), 'ALTER TABLE `schema`.`table` ADD FOREIGN KEY `fk5`(`column1`) REFERENCES `ref_table`(`column2`) ON DELETE CASCADE ON UPDATE NO ACTION');

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

		$definition['references'] = array(
			$references['fk3']
		);

		$expected  = "CREATE TABLE `table` (\n";
		$expected .= "	`column2` INT(18) UNSIGNED,\n";
		$expected .= "	`column3` DECIMAL(10,2) NOT NULL,\n";
		$expected .= "	`column1` VARCHAR(10),\n";
		$expected .= "	PRIMARY KEY (`column3`),\n";
		$expected .= "	CONSTRAINT `fk3` FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ON DELETE CASCADE\n";
		$expected .= ")";
		$this->assertEquals($dialect->createTable('table', null, $definition), $expected);

		$definition = array(
			'columns' => array(
				$columns['column9'],
				$columns['column10'],
			)
		);

		$expected  = "CREATE TABLE `table` (\n";
		$expected .= "	`column9` VARCHAR(10) DEFAULT \"column9\",\n";
		$expected .= "	`column10` INT(18) UNSIGNED DEFAULT \"10\"\n";
		$expected .= ")";
		$this->assertEquals($dialect->createTable('table', null, $definition), $expected);

		$definition = array(
			'columns' => array(
				$columns['column11'],
				$columns['column12'],
			)
		);

		$expected  = "CREATE TABLE `table` (\n";
		$expected .= "	`column11` BIGINT(20) UNSIGNED,\n";
		$expected .= "	`column12` ENUM(\"A\", \"B\", \"C\") DEFAULT \"A\" NOT NULL\n";
		$expected .= ")";
		$this->assertEquals($dialect->createTable('table', null, $definition), $expected);

	}

  public function testPostgresqlDialect()
  {

    $dialect = new \Phalcon\Db\Dialect\Postgresql();

    $columns = $dialect->getColumnList(array('column1', 'column2', 'column3'));
    $this->assertEquals($columns, "\"column1\", \"column2\", \"column3\"");

    $columns = $this->getColumns();

    //Column definitions
    $this->assertEquals($dialect->getColumnDefinition($columns['column1']), 'CHARACTER VARYING(10)');
    $this->assertEquals($dialect->getColumnDefinition($columns['column2']), 'INT');
    $this->assertEquals($dialect->getColumnDefinition($columns['column3']), 'NUMERIC(10,2)');
    $this->assertEquals($dialect->getColumnDefinition($columns['column4']), 'CHARACTER(100)');
    $this->assertEquals($dialect->getColumnDefinition($columns['column5']), 'DATE');
    $this->assertEquals($dialect->getColumnDefinition($columns['column6']), 'TIMESTAMP');
    $this->assertEquals($dialect->getColumnDefinition($columns['column7']), 'TEXT');
    $this->assertEquals($dialect->getColumnDefinition($columns['column8']), 'FLOAT');
    $this->assertEquals($dialect->getColumnDefinition($columns['column9']), 'CHARACTER VARYING(10)');
    $this->assertEquals($dialect->getColumnDefinition($columns['column10']), 'INT');
    $this->assertEquals($dialect->getColumnDefinition($columns['column11']), 'BIGINT');
    $this->assertEquals($dialect->getColumnDefinition($columns['column12']), "ENUM(\"A\", \"B\", \"C\")");

    //Add Columns
    $this->assertEquals($dialect->addColumn('table', null, $columns['column1']), 'ALTER TABLE "table" ADD COLUMN "column1" CHARACTER VARYING(10)');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column1']), 'ALTER TABLE "schema"."table" ADD COLUMN "column1" CHARACTER VARYING(10)');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column2']), 'ALTER TABLE "table" ADD COLUMN "column2" INT');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column2']), 'ALTER TABLE "schema"."table" ADD COLUMN "column2" INT');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column3']), 'ALTER TABLE "table" ADD COLUMN "column3" NUMERIC(10,2) NOT NULL');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column3']), 'ALTER TABLE "schema"."table" ADD COLUMN "column3" NUMERIC(10,2) NOT NULL');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column4']), 'ALTER TABLE "table" ADD COLUMN "column4" CHARACTER(100) NOT NULL');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column4']), 'ALTER TABLE "schema"."table" ADD COLUMN "column4" CHARACTER(100) NOT NULL');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column5']), 'ALTER TABLE "table" ADD COLUMN "column5" DATE NOT NULL');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column5']), 'ALTER TABLE "schema"."table" ADD COLUMN "column5" DATE NOT NULL');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column6']), 'ALTER TABLE "table" ADD COLUMN "column6" TIMESTAMP NOT NULL');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column6']), 'ALTER TABLE "schema"."table" ADD COLUMN "column6" TIMESTAMP NOT NULL');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column7']), 'ALTER TABLE "table" ADD COLUMN "column7" TEXT NOT NULL');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column7']), 'ALTER TABLE "schema"."table" ADD COLUMN "column7" TEXT NOT NULL');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column8']), 'ALTER TABLE "table" ADD COLUMN "column8" FLOAT NOT NULL');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column8']), 'ALTER TABLE "schema"."table" ADD COLUMN "column8" FLOAT NOT NULL');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column9']), 'ALTER TABLE "table" ADD COLUMN "column9" CHARACTER VARYING(10) DEFAULT "column9"');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column9']), 'ALTER TABLE "schema"."table" ADD COLUMN "column9" CHARACTER VARYING(10) DEFAULT "column9"');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column10']), 'ALTER TABLE "table" ADD COLUMN "column10" INT DEFAULT "10"');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column10']), 'ALTER TABLE "schema"."table" ADD COLUMN "column10" INT DEFAULT "10"');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column11']), 'ALTER TABLE "table" ADD COLUMN "column11" BIGINT');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column11']), 'ALTER TABLE "schema"."table" ADD COLUMN "column11" BIGINT');
    $this->assertEquals($dialect->addColumn('table', null, $columns['column12']), 'ALTER TABLE "table" ADD COLUMN "column12" ENUM("A", "B", "C") DEFAULT "A" NOT NULL');
    $this->assertEquals($dialect->addColumn('table', 'schema', $columns['column12']), 'ALTER TABLE "schema"."table" ADD COLUMN "column12" ENUM("A", "B", "C") DEFAULT "A" NOT NULL');

    //Modify Columns
    
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column1'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column1";ALTER TABLE "table" ALTER COLUMN "column1" TYPE CHARACTER VARYING(10);');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column1'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column1";ALTER TABLE "schema"."table" ALTER COLUMN "column1" TYPE CHARACTER VARYING(10);');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column2'],$columns['column1']), 'ALTER TABLE "table" RENAME COLUMN "column1" TO "column2";ALTER TABLE "table" ALTER COLUMN "column2" TYPE INT;');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column2'],$columns['column1']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column1" TO "column2";ALTER TABLE "schema"."table" ALTER COLUMN "column2" TYPE INT;');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column3'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column3";ALTER TABLE "table" ALTER COLUMN "column3" TYPE NUMERIC(10,2);ALTER TABLE "table" ALTER COLUMN "column3" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column3'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column3";ALTER TABLE "schema"."table" ALTER COLUMN "column3" TYPE NUMERIC(10,2);ALTER TABLE "schema"."table" ALTER COLUMN "column3" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column4'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column4";ALTER TABLE "table" ALTER COLUMN "column4" TYPE CHARACTER(100);ALTER TABLE "table" ALTER COLUMN "column4" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column4'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column4";ALTER TABLE "schema"."table" ALTER COLUMN "column4" TYPE CHARACTER(100);ALTER TABLE "schema"."table" ALTER COLUMN "column4" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column5'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column5";ALTER TABLE "table" ALTER COLUMN "column5" TYPE DATE;ALTER TABLE "table" ALTER COLUMN "column5" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column5'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column5";ALTER TABLE "schema"."table" ALTER COLUMN "column5" TYPE DATE;ALTER TABLE "schema"."table" ALTER COLUMN "column5" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column6'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column6";ALTER TABLE "table" ALTER COLUMN "column6" TYPE TIMESTAMP;ALTER TABLE "table" ALTER COLUMN "column6" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column6'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column6";ALTER TABLE "schema"."table" ALTER COLUMN "column6" TYPE TIMESTAMP;ALTER TABLE "schema"."table" ALTER COLUMN "column6" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column7'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column7";ALTER TABLE "table" ALTER COLUMN "column7" TYPE TEXT;ALTER TABLE "table" ALTER COLUMN "column7" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column7'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column7";ALTER TABLE "schema"."table" ALTER COLUMN "column7" TYPE TEXT;ALTER TABLE "schema"."table" ALTER COLUMN "column7" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column8'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column8";ALTER TABLE "table" ALTER COLUMN "column8" TYPE FLOAT;ALTER TABLE "table" ALTER COLUMN "column8" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column8'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column8";ALTER TABLE "schema"."table" ALTER COLUMN "column8" TYPE FLOAT;ALTER TABLE "schema"."table" ALTER COLUMN "column8" SET NOT NULL;');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column9'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column9";ALTER TABLE "table" ALTER COLUMN "column9" TYPE CHARACTER VARYING(10);ALTER TABLE "table" ALTER COLUMN "column9" SET DEFAULT "column9"');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column9'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column9";ALTER TABLE "schema"."table" ALTER COLUMN "column9" TYPE CHARACTER VARYING(10);ALTER TABLE "schema"."table" ALTER COLUMN "column9" SET DEFAULT "column9"');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column10'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column10";ALTER TABLE "table" ALTER COLUMN "column10" SET DEFAULT "10"');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column10'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column10";ALTER TABLE "schema"."table" ALTER COLUMN "column10" SET DEFAULT "10"');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column11'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column11";');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column11'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column11";');
    $this->assertEquals($dialect->modifyColumn('table', null, $columns['column12'],$columns['column2']), 'ALTER TABLE "table" RENAME COLUMN "column2" TO "column12";ALTER TABLE "table" ALTER COLUMN "column12" SET NOT NULL;ALTER TABLE "table" ALTER COLUMN "column12" SET DEFAULT "A"');
    $this->assertEquals($dialect->modifyColumn('table', 'schema', $columns['column12'],$columns['column2']), 'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column12";ALTER TABLE "schema"."table" ALTER COLUMN "column12" SET NOT NULL;ALTER TABLE "schema"."table" ALTER COLUMN "column12" SET DEFAULT "A"');

    //Drop Columns
    $this->assertEquals($dialect->dropColumn('table', null, 'column1'), 'ALTER TABLE "table"  DROP COLUMN "column1"');
    $this->assertEquals($dialect->dropColumn('table', 'schema', 'column1'), 'ALTER TABLE "schema"."table"  DROP COLUMN "column1"');

    $indexes = $this->getIndexes();

    //Add Index
    $this->assertEquals($dialect->addIndex('table', null, $indexes['index1']), 'CREATE INDEX "index1" ON "table" ("column1")');
    $this->assertEquals($dialect->addIndex('table', 'schema', $indexes['index1']), 'CREATE INDEX "index1" ON "schema"."table" ("column1")');
    $this->assertEquals($dialect->addIndex('table', null, $indexes['index2']), 'CREATE INDEX "index2" ON "table" ("column1", "column2")');
    $this->assertEquals($dialect->addIndex('table', 'schema', $indexes['index2']), 'CREATE INDEX "index2" ON "schema"."table" ("column1", "column2")');
    $this->assertEquals($dialect->addIndex('table', null, $indexes['PRIMARY']), 'ALTER TABLE "table" ADD CONSTRAINT "PRIMARY" PRIMARY KEY ("column3")');
    $this->assertEquals($dialect->addIndex('table', 'schema', $indexes['PRIMARY']), 'ALTER TABLE "schema"."table" ADD CONSTRAINT "PRIMARY" PRIMARY KEY ("column3")');
    $this->assertEquals($dialect->addIndex('table', null, $indexes['index4']), 'CREATE UNIQUE INDEX "index4" ON "table" ("column4")');
    $this->assertEquals($dialect->addIndex('table', 'schema', $indexes['index4']), 'CREATE UNIQUE INDEX "index4" ON "schema"."table" ("column4")');

    //Drop Index
    $this->assertEquals($dialect->dropIndex('table', null, 'index1'), 'DROP INDEX "index1"');
    $this->assertEquals($dialect->dropIndex('table', 'schema', 'index1'), 'DROP INDEX "index1"');

    //Add Primary 
    $this->assertEquals($dialect->addPrimaryKey('table', null, $indexes['PRIMARY']), 'ALTER TABLE "table" ADD CONSTRAINT "PRIMARY" PRIMARY KEY ("column3")');
    $this->assertEquals($dialect->addPrimaryKey('table', 'schema', $indexes['PRIMARY']), 'ALTER TABLE "schema"."table" ADD CONSTRAINT "PRIMARY" PRIMARY KEY ("column3")');

    //Drop Primary Key
    $this->assertEquals($dialect->dropPrimaryKey('table', null), 'ALTER TABLE "table" DROP CONSTRAINT "PRIMARY"');
    $this->assertEquals($dialect->dropPrimaryKey('table', 'schema'), 'ALTER TABLE "schema"."table" DROP CONSTRAINT "PRIMARY"');

    $references = $this->getReferences();

    //Add Foreign Key
    $this->assertEquals($dialect->addForeignKey('table', null, $references['fk1']), 'ALTER TABLE "table" ADD CONSTRAINT "fk1" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2")');
    $this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk1']), 'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk1" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2")');
    $this->assertEquals($dialect->addForeignKey('table', null, $references['fk2']), 'ALTER TABLE "table" ADD CONSTRAINT "fk2" FOREIGN KEY ("column3", "column4") REFERENCES "ref_table" ("column5", "column6")');
    $this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk2']), 'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk2" FOREIGN KEY ("column3", "column4") REFERENCES "ref_table" ("column5", "column6")');

    $this->assertEquals($dialect->addForeignKey('table', null, $references['fk3']), 'ALTER TABLE "table" ADD CONSTRAINT "fk3" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON DELETE CASCADE');
    $this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk3']), 'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk3" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON DELETE CASCADE');
    $this->assertEquals($dialect->addForeignKey('table', null, $references['fk4']), 'ALTER TABLE "table" ADD CONSTRAINT "fk4" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON UPDATE SET NULL');
    $this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk4']), 'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk4" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON UPDATE SET NULL');
    $this->assertEquals($dialect->addForeignKey('table', null, $references['fk5']), 'ALTER TABLE "table" ADD CONSTRAINT "fk5" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON DELETE CASCADE ON UPDATE NO ACTION');
    $this->assertEquals($dialect->addForeignKey('table', 'schema', $references['fk5']), 'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk5" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON DELETE CASCADE ON UPDATE NO ACTION');

    $this->assertEquals($dialect->dropForeignKey('table', null, 'fk1'), 'ALTER TABLE "table" DROP CONSTRAINT "fk1"');
    $this->assertEquals($dialect->dropForeignKey('table', 'schema', 'fk1'), 'ALTER TABLE "schema"."table" DROP CONSTRAINT "fk1"');

    //Create tables
    $definition = array(
      'columns' => array(
        $columns['column1'],
        $columns['column2'],
      )
    );

    $expected  = "CREATE TABLE \"table\" (\n";
    $expected .= "	\"column1\" CHARACTER VARYING(10),\n";
    $expected .= "	\"column2\" INT\n";
    $expected .= ");";
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

    $expected  = "CREATE TABLE \"table\" (\n";
    $expected .= "	\"column2\" INT,\n";
    $expected .= "	\"column3\" NUMERIC(10,2) NOT NULL,\n";
    $expected .= "	\"column1\" CHARACTER VARYING(10),\n";
    $expected .= "	CONSTRAINT \"PRIMARY\" PRIMARY KEY (\"column3\")\n";
    $expected .= ");";
    $this->assertEquals($dialect->createTable('table', null, $definition), $expected);

    $definition['references'] = array(
      $references['fk3']
    );

    $expected  = "CREATE TABLE \"table\" (\n";
    $expected .= "	\"column2\" INT,\n";
    $expected .= "	\"column3\" NUMERIC(10,2) NOT NULL,\n";
    $expected .= "	\"column1\" CHARACTER VARYING(10),\n";
    $expected .= "	CONSTRAINT \"PRIMARY\" PRIMARY KEY (\"column3\"),\n";
    $expected .= "	CONSTRAINT \"fk3\" FOREIGN KEY (\"column1\") REFERENCES \"ref_table\" (\"column2\") ON DELETE CASCADE\n";
    $expected .= ");";
    $this->assertEquals($dialect->createTable('table', null, $definition), $expected);

    $definition = array(
      'columns' => array(
        $columns['column9'],
        $columns['column10'],
      )
    );

    $expected  = "CREATE TABLE \"table\" (\n";
    $expected .= "	\"column9\" CHARACTER VARYING(10) DEFAULT \"column9\",\n";
    $expected .= "	\"column10\" INT DEFAULT \"10\"\n";
    $expected .= ");";
    $this->assertEquals($dialect->createTable('table', null, $definition), $expected);

    $definition = array(
      'columns' => array(
        $columns['column11'],
        $columns['column12'],
      )
    );

    $expected  = "CREATE TABLE \"table\" (\n";
    $expected .= "	\"column11\" BIGINT,\n";
    $expected .= "	\"column12\" ENUM(\"A\", \"B\", \"C\") DEFAULT \"A\" NOT NULL\n";
    $expected .= ");";
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
		$this->assertEquals($dialect->getColumnDefinition($columns['column9']), 'VARCHAR(10)');
		$this->assertEquals($dialect->getColumnDefinition($columns['column10']), 'INT');

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
		$this->assertEquals($dialect->addColumn('table', null,     $columns['column9']), 'ALTER TABLE "table" ADD COLUMN "column9" VARCHAR(10) DEFAULT "column9"');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column9']), 'ALTER TABLE "schema"."table" ADD COLUMN "column9" VARCHAR(10) DEFAULT "column9"');
		$this->assertEquals($dialect->addColumn('table', null,     $columns['column10']), 'ALTER TABLE "table" ADD COLUMN "column10" INT DEFAULT "10"');
		$this->assertEquals($dialect->addColumn('table', 'schema', $columns['column10']), 'ALTER TABLE "schema"."table" ADD COLUMN "column10" INT DEFAULT "10"');

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

  // Postgresql
    $dialect = new \Phalcon\Db\Dialect\Postgresql();

    $definition = array(
      'sql' => 'SELECT 1',
    );

    //Create View
    $this->assertEquals($dialect->createView('test_view', $definition, null), 'CREATE VIEW "test_view" AS SELECT 1');
    $this->assertEquals($dialect->createView('test_view', $definition, 'schema'), 'CREATE VIEW "schema"."test_view" AS SELECT 1');

    //Drop View
    $this->assertEquals($dialect->dropView('test_view', null, false), 'DROP VIEW "test_view"');
    $this->assertEquals($dialect->dropView('test_view', null, true), 'DROP VIEW IF EXISTS "test_view"');
    $this->assertEquals($dialect->dropView('test_view', 'schema', false), 'DROP VIEW "schema"."test_view"');
    $this->assertEquals($dialect->dropView('test_view', 'schema', true), 'DROP VIEW IF EXISTS "schema"."test_view"');
    
    $this->assertEquals($dialect->listViews(), 'SELECT viewname AS view_name FROM pg_views WHERE schemaname = \'public\' ORDER BY view_name');
    
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
