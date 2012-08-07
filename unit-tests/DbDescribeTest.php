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
  +------------------------------------------------------------------------+
*/

class DbDescribeTest extends PHPUnit_Framework_TestCase {

	public function testDbMysql(){

		require 'unit-tests/config.db.php';

		$connection = Phalcon\Db::factory('mysql', $configMysql);
		$this->assertTrue(is_object($connection));

		//List tables
		$expectedTables = array(
			'parts',
			'personas',
			'personnes',
			'prueba',
			'robots',
			'robots_parts',
			'subscriptores',
			'tipo_documento'
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

		//Fields describe
		$expectedDescribe = array(
			0 => array(
				'field' => 'cedula',
				'type' => 'char(15)',
				'null' => 'NO',
				'key' => 'PRI',
				'default' => NULL,
				'extra' => '',
			),
			1 => array(
				'field' => 'tipo_documento_id',
				'type' => 'int(3) unsigned',
				'null' => 'NO',
				'key' => '',
				'default' => NULL,
				'extra' => '',
			),
			2 => array(
				'field' => 'nombres',
				'type' => 'varchar(100)',
				'null' => 'NO',
				'key' => '',
				'default' => '',
				'extra' => '',
			),
			3 => array(
				'field' => 'telefono',
				'type' => 'varchar(20)',
				'null' => 'YES',
				'key' => '',
				'default' => NULL,
				'extra' => '',
			),
  			4 => array(
				'field' => 'direccion',
				'type' => 'varchar(100)',
				'null' => 'YES',
				'key' => '',
				'default' => NULL,
				'extra' => '',
			),
			5 => array(
				'field' => 'email',
				'type' => 'varchar(50)',
				'null' => 'YES',
				'key' => '',
				'default' => NULL,
				'extra' => '',
			),
			6 => array(
				'field' => 'fecha_nacimiento',
				'type' => 'date',
				'null' => 'YES',
				'key' => '',
				'default' => '1970-01-01',
				'extra' => '',
			),
			7 => array(
				'field' => 'ciudad_id',
				'type' => 'int(10) unsigned',
				'null' => 'YES',
				'key' => 'MUL',
				'default' => '0',
				'extra' => '',
			),
			8 => array(
				'field' => 'creado_at',
				'type' => 'date',
				'null' => 'YES',
				'key' => '',
				'default' => NULL,
				'extra' => '',
			),
			9 => array(
				'field' => 'cupo',
				'type' => 'decimal(16,2)',
				'null' => 'NO',
				'key' => '',
				'default' => NULL,
				'extra' => '',
			),
			10 => array(
				'field' => 'estado',
				'type' => 'enum(\'A\',\'I\',\'X\')',
				'null' => 'NO',
				'key' => 'MUL',
				'default' => NULL,
				'extra' => '',
			)
		);

		$describe = $connection->describeTable('personas');
		$this->assertEquals($describe, $expectedDescribe);

		$describe = $connection->describeTable('personas', 'phalcon_test');
		$this->assertEquals($describe, $expectedDescribe);

		//Table Options
		$expectedOptions = array (
  			'table_type' => 'BASE TABLE',
  			'auto_increment' => NULL,
			'engine' => 'InnoDB',
			'table_collation' => 'utf8_unicode_ci',
		);

		$options = $connection->tableOptions('personas');
		$this->assertEquals($options, $expectedOptions);

		//Indexes
		$expectedIndexes = array(
			'PRIMARY' => Phalcon\Db\Index::__set_state(array(
				'_indexName' => 'PRIMARY',
				'_columns' => array('id')
  			)),
			'robots_id' => Phalcon\Db\Index::__set_state(array(
				'_indexName' => 'robots_id',
				'_columns' => array('robots_id')
			)),
			'parts_id' => Phalcon\Db\Index::__set_state(array(
				'_indexName' => 'parts_id',
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

	/*public function testDbPostgresql(){

		require 'unit-tests/config.db.php';

		$connection = Phalcon\Db::factory('Postgresql', $configPostgresql);
		$this->assertTrue(is_object($connection));

		//List tables
		$expectedTables = array(
			'parts',
			'personas',
			'personnes',
			'prueba',
			'robots',
			'robots_parts',
			'subscriptores',
			'tipo_documento'
		);

		$tables = $connection->listTables();
		$this->assertEquals($tables, $expectedTables);

		$tables = $connection->listTables('phalcon_test');
		$this->assertEquals($tables, $expectedTables);

		//Table exist
		$this->assertEquals($connection->tableExists('personas'), 1);
		$this->assertEquals($connection->tableExists('noexist'), 0);
		$this->assertEquals($connection->tableExists('personas', 'public'), 1);
		$this->assertEquals($connection->tableExists('personas', 'test'), 0);

		//Fields describe
		$expectedDescribe = array(
			0 => array(
				'Field' => 'cedula',
				'Type' => 'character(15)',
				'Null' => 'NO',
				'Key' => 'PRI',
				'Extra' => '',
			),
			1 => array(
				'Field' => 'tipo_documento_id',
				'Type' => 'integer',
				'Null' => 'NO',
				'Key' => '',
				'Extra' => '',
			),
			2 => array(
				'Field' => 'nombres',
				'Type' => 'character varying(100)',
				'Null' => 'NO',
				'Key' => '',
				'Extra' => '',
			),
			3 => array(
				'Field' => 'telefono',
				'Type' => 'character varying(20)',
				'Null' => 'YES',
				'Key' => '',
				'Extra' => '',
			),
			4 => array(
				'Field' => 'direccion',
				'Type' => 'character varying(100)',
				'Null' => 'YES',
				'Key' => '',
				'Extra' => '',
			),
			5 => array(
				'Field' => 'email',
				'Type' => 'character varying(50)',
				'Null' => 'YES',
				'Key' => '',
				'Extra' => '',
			),
			6 => array(
				'Field' => 'fecha_nacimiento',
				'Type' => 'date',
				'Null' => 'YES',
				'Key' => '',
				'Extra' => '',
			),
			7 => array(
				'Field' => 'ciudad_id',
				'Type' => 'integer',
				'Null' => 'YES',
				'Key' => '',
				'Extra' => '',
			),
			8 => array(
				'Field' => 'creado_at',
				'Type' => 'date',
				'Null' => 'YES',
				'Key' => '',
				'Extra' => '',
			),
			9 => array(
				'Field' => 'cupo',
				'Type' => 'numeric(16,2)',
				'Null' => 'NO',
				'Key' => '',
				'Extra' => '',
			),
			10 => array(
				'Field' => 'estado',
				'Type' => 'character(1)',
				'Null' => 'NO',
				'Key' => '',
				'Extra' => '',
			),
		);

		$describe = $connection->describeTable('personas');
		$this->assertEquals($describe, $expectedDescribe);

		$describe = $connection->describeTable('personas', 'public');
		$this->assertEquals($describe, $expectedDescribe);

		//Indexes
		$expectedIndexes = array(
			'PRIMARY' => Phalcon_Db_Index::__set_state(array(
				'_indexName' => 'PRIMARY',
				'_columns' => array('id')
			)),
			'robots_id' => Phalcon_Db_Index::__set_state(array(
				'_indexName' => 'robots_id',
				'_columns' => array('robots_id')
			)),
			'parts_id' => Phalcon_Db_Index::__set_state(array(
				'_indexName' => 'parts_id',
				'_columns' => array('parts_id')
			))
		);

		$describeIndexes = $connection->describeIndexes('robots_parts');
		$this->assertEquals($describeIndexes, $expectedIndexes);

		$describeIndexes = $connection->describeIndexes('robots_parts', 'phalcon_test');
		$this->assertEquals($describeIndexes, $expectedIndexes);

		//References
		$expectedReferences = array(
			'robots_parts_ibfk_1' => Phalcon_Db_Reference::__set_state(array(
			'_referenceName' => 'robots_parts_ibfk_1',
			'_referencedTable' => 'robots',
			'_columns' => array('robots_id'),
				'_referencedColumns' => array('id'),
				'_referencedSchema' => 'phalcon_test'
			)),
			'robots_parts_ibfk_2' => Phalcon_Db_Reference::__set_state(array(
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

	}*/

}
