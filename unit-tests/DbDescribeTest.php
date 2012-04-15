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

	public function testDb(){

		$config = new stdClass();
		$config->host = '127.0.0.1';
		$config->username = 'root';
		$config->password = '';
		$config->name = 'phalcon_test';

		$connection = Phalcon_Db::factory('Mysql', $config, true);
		$this->assertTrue(is_object($connection));

		//List tables
		$expectedTables = array(
   			'parts',
    		'personas',
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

		//Indexes
		$expectedIndexes = array(
			'PRIMARY' => array(
    			0 => 'id',
  			),
  			'robots_id' => array(
    			0 => 'robots_id',
  			),
  			'parts_id' => array(
    			0 => 'parts_id',
  			),
		);
		$describeIndexes = $connection->describeIndexes('robots_parts');
		$this->assertEquals($describeIndexes, $expectedIndexes);

		$describeIndexes = $connection->describeIndexes('robots_parts', 'phalcon_test');
		$this->assertEquals($describeIndexes, $expectedIndexes);

		//References
		$expectedReferences = array(
  			'robots_parts_ibfk_1' => array(
    			'referencedSchema' => 'phalcon_test',
    			'referencedTable' => 'robots',
    			'columns' => array(
      				0 => 'robots_id',
    			),
    			'referencedColumns' => array(
      				0 => 'id',
    			),
  			),
  			'robots_parts_ibfk_2' => array(
    			'referencedSchema' => 'phalcon_test',
    			'referencedTable' => 'parts',
    			'columns' => array(
      				0 => 'parts_id',
    			),
    			'referencedColumns' => array(
      				0 => 'id',
    			),
  			),
		);

		$describeReferences = $connection->describeReferences('robots_parts');
		$this->assertEquals($describeReferences, $expectedReferences);

		$describeReferences = $connection->describeReferences('robots_parts', 'phalcon_test');
		$this->assertEquals($describeReferences, $expectedReferences);

	}

}
