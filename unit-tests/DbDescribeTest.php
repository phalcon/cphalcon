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

		$connection = Phalcon\Db::factory('Mysql', $configMysql);
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
				'Field' => 'cedula',
				'Type' => 'char(15)',
				'Null' => 'NO',
				'Key' => 'PRI',
				'Default' => NULL,
				'Extra' => '',
			),
			1 => array(
				'Field' => 'tipo_documento_id',
				'Type' => 'int(3) unsigned',
				'Null' => 'NO',
				'Key' => '',
				'Default' => NULL,
				'Extra' => '',
			),
			2 => array(
				'Field' => 'nombres',
				'Type' => 'varchar(100)',
				'Null' => 'NO',
				'Key' => '',
				'Default' => '',
				'Extra' => '',
			),
			3 => array(
				'Field' => 'telefono',
				'Type' => 'varchar(20)',
				'Null' => 'YES',
				'Key' => '',
				'Default' => NULL,
				'Extra' => '',
			),
  			4 => array(
				'Field' => 'direccion',
				'Type' => 'varchar(100)',
				'Null' => 'YES',
				'Key' => '',
				'Default' => NULL,
				'Extra' => '',
			),
			5 => array(
				'Field' => 'email',
				'Type' => 'varchar(50)',
				'Null' => 'YES',
				'Key' => '',
				'Default' => NULL,
				'Extra' => '',
			),
			6 => array(
				'Field' => 'fecha_nacimiento',
				'Type' => 'date',
				'Null' => 'YES',
				'Key' => '',
				'Default' => '1970-01-01',
				'Extra' => '',
			),
			7 => array(
				'Field' => 'ciudad_id',
				'Type' => 'int(10) unsigned',
				'Null' => 'YES',
				'Key' => 'MUL',
				'Default' => '0',
				'Extra' => '',
			),
			8 => array(
				'Field' => 'creado_at',
				'Type' => 'date',
				'Null' => 'YES',
				'Key' => '',
				'Default' => NULL,
				'Extra' => '',
			),
			9 => array(
				'Field' => 'cupo',
				'Type' => 'decimal(16,2)',
				'Null' => 'NO',
				'Key' => '',
				'Default' => NULL,
				'Extra' => '',
			),
			10 => array(
				'Field' => 'estado',
				'Type' => 'enum(\'A\',\'I\',\'X\')',
				'Null' => 'NO',
				'Key' => 'MUL',
				'Default' => NULL,
				'Extra' => '',
			)
		);

		$describe = $connection->describeTable('personas');
		$this->assertEquals($describe, $expectedDescribe);

		$describe = $connection->describeTable('personas', 'phalcon_test');
		$this->assertEquals($describe, $expectedDescribe);

		//Table Options
		$expectedOptions = array (
  			'TABLE_TYPE' => 'BASE TABLE',
  			'AUTO_INCREMENT' => NULL,
			'ENGINE' => 'InnoDB',
			'TABLE_COLLATION' => 'utf8_unicode_ci',
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

	public function testDbPostgresql(){

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

		/*//Indexes
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
		$this->assertEquals($describeReferences, $expectedReferences);*/

	}

}
