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

class DbDescribeTest extends PHPUnit_Framework_TestCase
{

	public function getExpectedColumnsMysql()
	{
		return array(
			0 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'cedula',
				'_schemaName' => NULL,
				'_type' => 5,
				'_isNumeric' => false,
				'_size' => 15,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_primary' => true,
				'_first' => true,
				'_after' => NULL,
				'_bindType' => 2,
			)),
			1 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'tipo_documento_id',
				'_schemaName' => NULL,
				'_type' => 0,
				'_isNumeric' => true,
				'_size' => 3,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => true,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'cedula',
				'_bindType' => 1,
			)),
			2 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'nombres',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 100,
				'_scale' => 0,
				'_default' => '',
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'tipo_documento_id',
				'_bindType' => 2,
			)),
			3 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'telefono',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 20,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'nombres',
				'_bindType' => 2,
			)),
			4 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'direccion',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 100,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'telefono',
				'_bindType' => 2,
			)),
			5 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'email',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 50,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'direccion',
				'_bindType' => 2,
			)),
			6 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'fecha_nacimiento',
				'_schemaName' => NULL,
				'_type' => 1,
				'_isNumeric' => false,
				'_size' => 0,
				'_scale' => 0,
				'_default' => '1970-01-01',
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'email',
				'_bindType' => 2,
			)),
			7 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'ciudad_id',
				'_schemaName' => NULL,
				'_type' => 0,
				'_isNumeric' => true,
				'_size' => 10,
				'_scale' => 0,
				'_default' => '0',
				'_unsigned' => true,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'fecha_nacimiento',
				'_bindType' => 1,
			)),
			8 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'creado_at',
				'_schemaName' => NULL,
				'_type' => 1,
				'_isNumeric' => false,
				'_size' => 0,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'ciudad_id',
				'_bindType' => 2,
			)),
			9 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'cupo',
				'_schemaName' => NULL,
				'_type' => 3,
				'_isNumeric' => true,
				'_size' => 16,
				'_scale' => 2,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'creado_at',
				'_bindType' => 32,
			)),
			10 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'estado',
				'_schemaName' => NULL,
				'_type' => 5,
				'_isNumeric' => false,
				'_size' => 0,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'cupo',
				'_bindType' => 2,
			))
		);
	}

	public function getExpectedColumnsPostgresql()
	{
		return array(
			0 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'cedula',
				'_schemaName' => NULL,
				'_type' => 5,
				'_isNumeric' => false,
				'_size' => 15,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_primary' => true,
				'_first' => true,
				'_after' => NULL,
				'_bindType' => 2,
			)),
			1 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'tipo_documento_id',
				'_schemaName' => NULL,
				'_type' => 0,
				'_isNumeric' => true,
				'_size' => 32,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'cedula',
				'_bindType' => 1,
			)),
			2 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'nombres',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 100,
				'_scale' => 0,
				'_default' => '',
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'tipo_documento_id',
				'_bindType' => 2,
			)),
			3 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'telefono',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 20,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'nombres',
			)),
			4 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'direccion',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 100,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'telefono',
				'_bindType' => 2,
			)),
			5 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'email',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 50,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'direccion',
				'_bindType' => 2,
			)),
			6 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'fecha_nacimiento',
				'_schemaName' => NULL,
				'_type' => 1,
				'_isNumeric' => false,
				'_size' => 0,
				'_scale' => 0,
				'_default' => '1970-01-01',
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'email',
				'_bindType' => 2,
			)),
			7 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'ciudad_id',
				'_schemaName' => NULL,
				'_type' => 0,
				'_isNumeric' => true,
				'_size' => 32,
				'_scale' => 0,
				'_default' => '0',
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'fecha_nacimiento',
				'_bindType' => 1,
			)),
			8 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'creado_at',
				'_schemaName' => NULL,
				'_type' => 1,
				'_isNumeric' => false,
				'_size' => 0,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'ciudad_id',
				'_bindType' => 2,
			)),
			9 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'cupo',
				'_schemaName' => NULL,
				'_type' => 3,
				'_isNumeric' => true,
				'_size' => 16,
				'_scale' => 2,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'creado_at',
				'_bindType' => 32,
			)),
			10 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'estado',
				'_schemaName' => NULL,
				'_type' => 5,
				'_isNumeric' => false,
				'_size' => 1,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'cupo',
				'_bindType' => 2,
			)),
		);

	}

	public function getExpectedColumnsSqlite()
	{
		return array(
			0 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'cedula',
				'_schemaName' => NULL,
				'_type' => 5,
				'_isNumeric' => false,
				'_size' => 15,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_primary' => true,
				'_first' => true,
				'_after' => NULL,
				'_bindType' => 2,
			)),
			1 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'tipo_documento_id',
				'_schemaName' => NULL,
				'_type' => 0,
				'_isNumeric' => true,
				'_size' => 3,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'cedula',
				'_bindType' => 1,
			)),
			2 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'nombres',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 100,
				'_scale' => 0,
				'_default' => '',
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'tipo_documento_id',
				'_bindType' => 2,
			)),
			3 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'telefono',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 20,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'nombres',
				'_bindType' => 2,
			)),
			4 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'direccion',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 100,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'telefono',
				'_bindType' => 2,
			)),
			5 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'email',
				'_schemaName' => NULL,
				'_type' => 2,
				'_isNumeric' => false,
				'_size' => 50,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'direccion',
				'_bindType' => 2,
			)),
			6 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'fecha_nacimiento',
				'_schemaName' => NULL,
				'_type' => 1,
				'_isNumeric' => false,
				'_size' => 0,
				'_scale' => 0,
				'_default' => '1970-01-01',
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'email',
				'_bindType' => 2,
			)),
			7 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'ciudad_id',
				'_schemaName' => NULL,
				'_type' => 0,
				'_isNumeric' => true,
				'_size' => 10,
				'_scale' => 0,
				'_default' => '0',
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'fecha_nacimiento',
				'_bindType' => 1,
			)),
			8 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'creado_at',
				'_schemaName' => NULL,
				'_type' => 1,
				'_isNumeric' => false,
				'_size' => 0,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => false,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'ciudad_id',
				'_bindType' => 2,
			)),
			9 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'cupo',
				'_schemaName' => NULL,
				'_type' => 3,
				'_isNumeric' => true,
				'_size' => 16,
				'_scale' => 2,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'creado_at',
				'_bindType' => 32,
			)),
			10 => Phalcon\Db\Column::__set_state(array(
				'_columnName' => 'estado',
				'_schemaName' => NULL,
				'_type' => 5,
				'_isNumeric' => false,
				'_size' => 1,
				'_scale' => 0,
				'_default' => NULL,
				'_unsigned' => false,
				'_notNull' => true,
				'_autoIncrement' => false,
				'_first' => false,
				'_after' => 'cupo',
				'_bindType' => 2,
			)),
		);
	}

	public function testDbMysql()
	{

		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$connection = new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);

		//List tables
		$expectedTables = array (
			'albums',
			'artists',
			'customers',
			'issue_1534',
			'issue_2019',
			'm2m_parts',
			'm2m_robots',
			'm2m_robots_parts',
			'parts',
			'personas',
			'personnes',
			'prueba',
			'robots',
			'robots_parts',
			'songs',
			'subscriptores',
			'tipo_documento',
		);

		$tables = $connection->listTables();
		$this->assertEquals($tables, $expectedTables);

		$tables = $connection->listTables('phalcon_test');
		$this->assertEquals($tables, $expectedTables);

		//Table exist
		$this->assertEquals($connection->tableExists('personas'), 1);
		$this->assertEquals($connection->tableExists('noexist'), 0);
		$this->assertEquals($connection->tableExists('personas', 'phalcon_test'), 1);
		$this->assertEquals($connection->tableExists('personas', 'test'), 0);

		$expectedDescribe = $this->getExpectedColumnsMysql();
		$describe = $connection->describeColumns('personas');

		$this->assertEquals($describe, $expectedDescribe);

		$describe = $connection->describeColumns('personas', 'phalcon_test');
		$this->assertEquals($describe, $expectedDescribe);

		//Table Options
		$expectedOptions = array(
			'table_type' => 'BASE TABLE',
			'auto_increment' => NULL,
			'engine' => 'InnoDB',
			'table_collation' => 'utf8_unicode_ci',
		);

		$options = $connection->tableOptions('personas', 'phalcon_test');
		$this->assertEquals($options, $expectedOptions);

		//Indexes
		$expectedIndexes = array(
			'PRIMARY' => Phalcon\Db\Index::__set_state(array(
				'_name' => 'PRIMARY',
				'_columns' => array('id')
			)),
			'robots_id' => Phalcon\Db\Index::__set_state(array(
				'_name' => 'robots_id',
				'_columns' => array('robots_id')
			)),
			'parts_id' => Phalcon\Db\Index::__set_state(array(
				'_name' => 'parts_id',
				'_columns' => array('parts_id')
			))
		);

		$describeIndexes = $connection->describeIndexes('robots_parts');
		$this->assertEquals($describeIndexes, $expectedIndexes);

		$describeIndexes = $connection->describeIndexes('robots_parts', 'phalcon_test');
		$this->assertEquals($describeIndexes, $expectedIndexes);

		//References
		$expectedReferences = array(
			'robots_parts_ibfk_1' => Phalcon\Db\Reference::__set_state(array(
			'_referenceName' => 'robots_parts_ibfk_1',
			'_referencedTable' => 'robots',
			'_columns' => array('robots_id'),
				'_referencedColumns' => array('id'),
				'_referencedSchema' => 'phalcon_test'
			)),
			'robots_parts_ibfk_2' => Phalcon\Db\Reference::__set_state(array(
				'_referenceName' => 'robots_parts_ibfk_2',
				'_referencedTable' => 'parts',
				'_columns' => array('parts_id'),
				'_referencedColumns' => array('id'),
				'_referencedSchema' => 'phalcon_test',
			)),
		);

		$describeReferences = $connection->describeReferences('robots_parts');
		$this->assertEquals($describeReferences, $expectedReferences);

		$describeReferences = $connection->describeReferences('robots_parts', 'phalcon_test');
		$this->assertEquals($describeReferences, $expectedReferences);

	}

	public function testDbPostgresql()
	{

		require 'unit-tests/config.db.php';
		if (empty($configPostgresql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);

		//List tables
		$expectedTables = array (
			0 => 'customers',
			1 => 'parts',
			2 => 'personas',
			3 => 'personnes',
			4 => 'prueba',
			5 => 'robots',
			6 => 'robots_parts',
			7 => 'subscriptores',
			8 => 'tipo_documento',
		);

		$tables = $connection->listTables();
		$this->assertEquals($tables, $expectedTables);

		$tables = $connection->listTables('public');
		$this->assertEquals($tables, $expectedTables);

		//Table exist
		$this->assertEquals($connection->tableExists('personas'), 1);
		$this->assertEquals($connection->tableExists('noexist'), 0);
		$this->assertEquals($connection->tableExists('personas', 'public'), 1);
		$this->assertEquals($connection->tableExists('personas', 'test'), 0);

		//Columns
		$expectedDescribe = $this->getExpectedColumnsPostgresql();

		$describe = $connection->describeColumns('personas');
		$this->assertEquals($describe, $expectedDescribe);

		$describe = $connection->describeColumns('personas', 'public');
		$this->assertEquals($describe, $expectedDescribe);

		//Indexes
		$expectedIndexes = array(
			'robots_parts_parts_id' => Phalcon\Db\Index::__set_state(array(
				'_name' => 'robots_parts_parts_id',
				'_columns' => array('parts_id')
			)),
			'robots_parts_pkey' => Phalcon\Db\Index::__set_state(array(
				'_name' => 'robots_parts_pkey',
				'_columns' => array('id')
			)),
			'robots_parts_robots_id' => Phalcon\Db\Index::__set_state(array(
				'_name' => 'robots_parts_robots_id',
				'_columns' => array('robots_id')
			))
		);

		$describeIndexes = $connection->describeIndexes('robots_parts');
		$this->assertEquals($describeIndexes, $expectedIndexes);

		$describeIndexes = $connection->describeIndexes('robots_parts', 'public');
		$this->assertEquals($describeIndexes, $expectedIndexes);

		//References
		$expectedReferences = array(
			'robots_parts_ibfk_1' => Phalcon\Db\Reference::__set_state(array(
			'_referenceName' => 'robots_parts_ibfk_1',
			'_referencedTable' => 'robots',
			'_columns' => array('robots_id'),
				'_referencedColumns' => array('id'),
				'_referencedSchema' => 'phalcon_test'
			)),
			'robots_parts_ibfk_2' => Phalcon\Db\Reference::__set_state(array(
				'_referenceName' => 'robots_parts_ibfk_2',
				'_referencedTable' => 'parts',
				'_columns' => array('parts_id'),
				'_referencedColumns' => array('id'),
				'_referencedSchema' => 'phalcon_test',
			)),
		);

		$describeReferences = $connection->describeReferences('robots_parts');
		$this->assertEquals($describeReferences, $expectedReferences);

		$describeReferences = $connection->describeReferences('robots_parts', 'public');
		$this->assertEquals($describeReferences, $expectedReferences);

	}

	public function testDbSqlite()
	{

		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$connection = new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);

		//List tables
		$expectedTables = array (
			0 => 'customers',
			1 => 'm2m_parts',
			2 => 'm2m_robots',
			3 => 'm2m_robots_parts',
			4 => 'parts',
			5 => 'personas',
			6 => 'personnes',
			7 => 'prueba',
			8 => 'robots',
			9 => 'robots_parts',
			10 => 'sqlite_sequence',
			11 => 'subscriptores',
			12 => 'tipo_documento',
		);

		$tables = $connection->listTables();
		$this->assertEquals($tables, $expectedTables);

		$tables = $connection->listTables('public');
		$this->assertEquals($tables, $expectedTables);

		//Table exist
		$this->assertEquals($connection->tableExists('personas'), 1);
		$this->assertEquals($connection->tableExists('noexist'), 0);
		$this->assertEquals($connection->tableExists('personas', 'public'), 1);
		$this->assertEquals($connection->tableExists('personas', 'test'), 1);

		//Columns
		$expectedDescribe = $this->getExpectedColumnsSqlite();
		$describe = $connection->describeColumns('personas');
		$this->assertEquals($describe, $expectedDescribe);

		$describe = $connection->describeColumns('personas', 'main');
		$this->assertEquals($describe, $expectedDescribe);

		//Indexes ps. sqlite's integer primary key autoincrement is not listed in indexes
		$expectedIndexes = array(
			'robots_parts_parts_id' => Phalcon\Db\Index::__set_state(array(
				'_name' => 'robots_parts_parts_id',
				'_columns' => array('parts_id')
			)),
			'robots_parts_robots_id' => Phalcon\Db\Index::__set_state(array(
				'_name' => 'robots_parts_robots_id',
				'_columns' => array('robots_id')
			))
		);

		$describeIndexes = $connection->describeIndexes('robots_parts');
		$this->assertEquals($describeIndexes, $expectedIndexes);

		$describeIndexes = $connection->describeIndexes('robots_parts', 'main');
		$this->assertEquals($describeIndexes, $expectedIndexes);

		//References
		$expectedReferences = array(
		   'foreign_key_0' => Phalcon\Db\Reference::__set_state(array(
				'_referenceName' => 'foreign_key_0',
				'_referencedTable' => 'parts',
				'_columns' => array('parts_id'),
				'_referencedColumns' => array('id'),
				'_referencedSchema' => null,
			)),
			'foreign_key_1' => Phalcon\Db\Reference::__set_state(array(
				'_referenceName' => 'foreign_key_1',
				'_referencedTable' => 'robots',
				'_columns' => array('robots_id'),
				'_referencedColumns' => array('id'),
				'_referencedSchema' => null
			)),
		);

		$describeReferences = $connection->describeReferences('robots_parts');
		$this->assertEquals($describeReferences, $expectedReferences);
	}

}
