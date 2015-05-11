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
  +------------------------------------------------------------------------+
*/

use Phalcon\Mvc\Model\Query as Query;

class ModelsQueryParsingTest extends PHPUnit_Framework_TestCase
{

	public function __construct()
	{
		spl_autoload_register(array($this, 'modelsAutoloader'));
	}

	public function __destruct()
	{
		spl_autoload_unregister(array($this, 'modelsAutoloader'));
	}

	public function modelsAutoloader($className)
	{
		$className = str_replace("\\", DIRECTORY_SEPARATOR, $className);
		$path = 'unit-tests/models/'.$className.'.php';
		if (file_exists($path)) {
			require $path;
		}
	}

	protected function _getDI()
	{

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		return $di;
	}

	/**
	 * @medium
	 */
	public function testSelectParsing()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				'le_products',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Some\\Products',
					'column' => 'le_products',
				),
			),
		);
		$query = new Query('SELECT * FROM Some\Products');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				'le_products',
			),
			'columns' => array(
				'some\\Products' => array(
					'type' => 'object',
					'model' => 'Some\\Products',
					'column' => 'le_products',
					'balias' => 'some\\Products',
				),
			),
		);
		$query = new Query('SELECT Some\Products.* FROM Some\Products');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				array(
					'le_products',
					NULL,
					'p',
				),
			),
			'columns' => array(
				'p' => array(
					'type' => 'object',
					'model' => 'Some\\Products',
					'column' => 'p',
					'balias' => 'p',
				),
			),
		);
		$query = new Query('SELECT p.* FROM Some\Products p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'robots' => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
					'balias' => 'robots',
				),
			),
		);
		$query = new Query('SELECT Robots.* FROM Robots');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
					'balias' => 'r',
				),
			),
		);
		$query = new Query('SELECT r.* FROM Robots r');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
					'balias' => 'r',
				),
			),
		);
		$query = new Query('SELECT r.* FROM Robots AS r');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'id' => array(
					'type' => 'scalar',
					'balias' => 'id',
					'sqlAlias' => 'id',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'id',
						'balias' => 'id',
					),
				),
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
			),
		);
		$query = new Query('SELECT id, name FROM Robots');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'id' => array(
					'type' => 'scalar',
					'balias' => 'id',
					'sqlAlias' => 'id',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'id',
						'balias' => 'id',
					),
				),
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'name',
					),
				),
			),
		);
		$query = new Query('SELECT r.id, r.name FROM Robots AS r');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'le_id' => array(
					'type' => 'scalar',
					'balias' => 'le_id',
					'sqlAlias' => 'le_id',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'id',
						'balias' => 'id',
					),
				),
				'le_name' => array(
					'type' => 'scalar',
					'balias' => 'le_name',
					'sqlAlias' => 'le_name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'name',
					),
				),
			),
		);
		$query = new Query('SELECT r.id AS le_id, r.name AS le_name FROM Robots AS r');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'le_id' => array(
					'type' => 'scalar',
					'balias' => 'le_id',
					'sqlAlias' => 'le_id',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'id',
						'balias' => 'id',
					),
				),
				'le_name' => array(
					'type' => 'scalar',
					'balias' => 'le_name',
					'sqlAlias' => 'le_name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
			),
		);
		$query = new Query('SELECT Robots.id AS le_id, Robots.name AS le_name FROM Robots');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'empty_str' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'literal',
						'value' => '\'\'',
					),
					'balias' => 'empty_str',
					'sqlAlias' => 'empty_str',
				),
				'double_number' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'literal',
						'value' => '10.5',
					),
					'balias' => 'double_number',
					'sqlAlias' => 'double_number',
				),
				'long_number' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'literal',
						'value' => '1000',
					),
					'balias' => 'long_number',
					'sqlAlias' => 'long_number',
				),
			),
		);
		$query = new Query('SELECT \'\' empty_str, 10.5 double_number, 1000 AS long_number FROM Robots');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'People',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'cedula' => array(
					'type' => 'scalar',
					'balias' => 'cedula',
					'sqlAlias' => 'cedula',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'personas',
						'name' => 'cedula',
						'balias' => 'cedula',
					),
				),
			),
		);
		$query = new Query('SELECT People.cedula FROM People');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'people',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'cedula' => array(
					'type' => 'scalar',
					'balias' => 'cedula',
					'sqlAlias' => 'cedula',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'personas',
						'name' => 'cedula',
						'balias' => 'cedula',
					),
				),
			),
		);
		$query = new Query('select people.cedula from people');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'People',
			),
			'tables' => array(
				array(
					'personas',
					NULL,
					'p',
				),
			),
			'columns' => array(
				'cedula' => array(
					'type' => 'scalar',
					'balias' => 'cedula',
					'sqlAlias' => 'cedula',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'p',
						'name' => 'cedula',
						'balias' => 'cedula',
					),
				),
			),
		);
		$query = new Query('SELECT p.cedula AS cedula FROM People p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'People',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'nombre' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'CONCAT',
						'arguments' => array(
							array(
								'type' => 'qualified',
								'domain' => 'personas',
								'name' => 'cedula',
								'balias' => 'cedula',
							),
							array(
								'type' => 'literal',
								'value' => '\'-\'',
							),
							array(
								'type' => 'qualified',
								'domain' => 'personas',
								'name' => 'nombres',
								'balias' => 'nombres',
							),
						),
					),
					'balias' => 'nombre',
					'sqlAlias' => 'nombre',
				),
			),
		);
		$query = new Query('SELECT CONCAT(cedula,\'-\',nombres) AS nombre FROM People');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'People',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'nombre' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'CONCAT',
						'arguments' => array(
							array(
								'type' => 'qualified',
								'domain' => 'personas',
								'name' => 'cedula',
								'balias' => 'cedula',
							),
							array(
								'type' => 'literal',
								'value' => '\'-\'',
							),
							array(
								'type' => 'qualified',
								'domain' => 'personas',
								'name' => 'nombres',
								'balias' => 'nombres',
							),
						),
					),
					'balias' => 'nombre',
					'sqlAlias' => 'nombre',
				),
			),
		);
		$query = new Query('SELECT CONCAT(People.cedula,\'-\',People.nombres) AS nombre FROM People');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robots_id',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots JOIN RobotsParts');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'CROSS',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robots_id',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots CROSS JOIN RobotsParts');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
				array(
					'type' => 'object',
					'model' => 'Parts',
					'column' => 'parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'LEFT',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robots_id',
							),
						),
					),
				),
				array(
					'type' => 'RIGHT',
					'source' => array(
						'parts',
						NULL,
					),
					'conditions' => array(
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots LEFT JOIN RobotsParts RIGHT JOIN Parts');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'RobotsParts',
			),
			'tables' => array(
				'robots_parts',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'Parts',
					'column' => 'parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'LEFT',
					'source' => array(
						'robots',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robots_id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'id',
							),
						),
					),
				),
				array(
					'type' => 'RIGHT',
					'source' => array(
						'parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'parts_id',
								'balias' => 'parts_id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'parts',
								'name' => 'id',
								'balias' => 'id',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM RobotsParts LEFT OUTER JOIN Robots RIGHT OUTER JOIN Parts');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robots_id',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots JOIN RobotsParts ON Robots.id = RobotsParts.robots_id');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'LEFT',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'binary-op',
								'op' => '=',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'robots',
									'name' => 'id',
									'balias' => 'id',
								),
								'right' => array(
									'type' => 'binary-op',
									'op' => 'AND',
									'left' => array(
										'type' => 'qualified',
										'domain' => 'robots_parts',
										'name' => 'robots_id',
										'balias' => 'robots_id',
									),
									'right' => array(
										'type' => 'qualified',
										'domain' => 'robots_parts',
										'name' => 'robots_id',
										'balias' => 'robots_id',
									),
								),
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'id',
							),
						),
					),
				),
			),
			'where' => array(
				'type' => 'unary-op',
				'op' => ' IS NULL',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots LEFT OUTER JOIN RobotsParts ON Robots.id = RobotsParts.robots_id AND RobotsParts.robots_id = Robots.id WHERE Robots.id IS NULL');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'RIGHT',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'binary-op',
								'op' => '=',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'robots',
									'name' => 'id',
									'balias' => 'id',
								),
								'right' => array(
									'type' => 'binary-op',
									'op' => 'AND',
									'left' => array(
										'type' => 'qualified',
										'domain' => 'robots_parts',
										'name' => 'robots_id',
										'balias' => 'robots_id',
									),
									'right' => array(
										'type' => 'qualified',
										'domain' => 'robots_parts',
										'name' => 'robots_id',
										'balias' => 'robots_id',
									),
								),
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'id',
							),
						),
					),
				),
			),
			'where' => array(
				'type' => 'unary-op',
				'op' => ' IS NOT NULL',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots_parts',
					'name' => 'robots_id',
					'balias' => 'robots_id',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots RIGHT OUTER JOIN RobotsParts ON Robots.id = RobotsParts.robots_id AND RobotsParts.robots_id = Robots.id WHERE RobotsParts.robots_id IS NOT NULL');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'FULL OUTER',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robots_id',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots FULL OUTER JOIN RobotsParts');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'RobotsParts',
			),
			'tables' => array(
				'robots_parts',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robots_id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'id',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM RobotsParts JOIN Robots');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
					'balias' => 'r',
				),
				'p' => array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'p',
					'balias' => 'p',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
						'p',
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'p',
								'name' => 'robots_id',
								'balias' => 'robots_id',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT r.*, p.* FROM Robots AS r JOIN RobotsParts AS p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'p',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
						'p',
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'p',
								'name' => 'robots_id',
								'balias' => 'robots_id',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots AS r JOIN RobotsParts AS p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
					'balias' => 'r',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robots_id',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT r.* FROM Robots r INNER JOIN RobotsParts');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'People',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'_0' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'binary-op',
						'op' => '/',
						'left' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '+',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'personas',
									'name' => 'cupo',
									'balias' => 'cupo',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '100',
								),
							),
						),
						'right' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '*',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'products',
									'name' => 'price',
									'balias' => 'price',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '0.15',
								),
							),
						),
					),
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'products',
						NULL,
					),
					'conditions' => array(
					),
				),
			),
		);
		$query = new Query('SELECT ( People.cupo + 100) / (Products.price * 0.15) FROM People JOIN Products');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'People',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'price' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'binary-op',
						'op' => '/',
						'left' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '+',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'personas',
									'name' => 'cupo',
									'balias' => 'cupo',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '100',
								),
							),
						),
						'right' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '*',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'le_products',
									'name' => 'price',
									'balias' => 'price',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '0.15',
								),
							),
						),
					),
					'balias' => 'price',
					'sqlAlias' => 'price',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'le_products',
						NULL,
					),
					'conditions' => array(
					),
				),
			),
		);
		$query = new Query('SELECT ( People.cupo + 100) / (Some\Products.price * 0.15) AS price FROM People JOIN Some\Products');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'People',
			),
			'tables' => array(
				array(
					'personas',
					NULL,
					'p',
				),
			),
			'columns' => array(
				'price' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'binary-op',
						'op' => '/',
						'left' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '+',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'p',
									'name' => 'cupo',
									'balias' => 'cupo',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '100',
								),
							),
						),
						'right' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '*',
								'left' => array(
									'type' => 'qualified',
									'domain' => 's',
									'name' => 'price',
									'balias' => 'price',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '0.15',
								),
							),
						),
					),
					'balias' => 'price',
					'sqlAlias' => 'price',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'le_products',
						NULL,
						's',
					),
					'conditions' => array(
					),
				),
			),
		);
		$query = new Query('SELECT (p.cupo + 100) / (s.price * 0.15) AS price FROM People AS p JOIN Some\Products AS s');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
				'RobotsParts',
			),
			'tables' => array(
				'robots',
				'robots_parts',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots, RobotsParts');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
				'RobotsParts',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
				array(
					'robots_parts',
					NULL,
					'p',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'p',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r, RobotsParts p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
				'RobotsParts',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
				array(
					'robots_parts',
					NULL,
					'p',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'p',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots AS r, RobotsParts AS p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
				'RobotsParts',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
				array(
					'robots_parts',
					NULL,
					'p',
				),
			),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'parts_id' => array(
					'type' => 'scalar',
					'balias' => 'parts_id',
					'sqlAlias' => 'parts_id',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'p',
						'name' => 'parts_id',
						'balias' => 'parts_id',
					),
				),
			),
		);
		$query = new Query('SELECT name, parts_id FROM Robots AS r, RobotsParts AS p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
				'RobotsParts',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
				array(
					'robots_parts',
					NULL,
					'p',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'p',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'qualified',
					'domain' => 'p',
					'name' => 'robots_id',
					'balias' => 'robots_id',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots AS r, RobotsParts AS p WHERE r.id = p.robots_id');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
				'RobotsParts',
			),
			'tables' => array(
				'robots',
				'robots_parts',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'qualified',
					'domain' => 'robots_parts',
					'name' => 'robots_id',
					'balias' => 'robots_id',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots, RobotsParts WHERE Robots.id = RobotsParts.robots_id');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id = 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id != 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id > 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id < 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id >= 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id <= 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => 'LIKE',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'as%\'',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.name LIKE \'as%\'');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => 'NOT LIKE',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'as%\'',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.name NOT LIKE \'as%\'');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => 'BETWEEN',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
				'right' => array(
					'type' => 'binary-op',
					'op' => 'AND',
					'left' => array(
						'type' => 'literal',
						'value' => '\'john\'',
					),
					'right' => array(
						'type' => 'literal',
						'value' => '\'mike\'',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.name BETWEEN \'john\' AND \'mike\'');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				'le_products',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Some\\Products',
					'column' => 'le_products',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'DATE',
					'arguments' => array(
						array(
							'type' => 'qualified',
							'domain' => 'le_products',
							'name' => 'created_at',
							'balias' => 'created_at',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'2010-10-02\'',
				),
			),
		);
		$query = new Query('SELECT * FROM Some\Products WHERE DATE(Some\Products.created_at) = "2010-10-02"');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				'le_products',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Some\\Products',
					'column' => 'le_products',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'le_products',
					'name' => 'created_at',
					'balias' => 'created_at',
				),
				'right' => array(
					'type' => 'functionCall',
					'name' => 'now',
				),
			),
		);
		$query = new Query('SELECT * FROM Some\Products WHERE Some\Products.created_at < now()');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => 'IN',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'list',
					array(
						array(
							'type' => 'literal',
							'value' => '1',
						)
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id IN (1)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => 'IN',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'list',
					array(
						array(
							'type' => 'literal',
							'value' => '1',
						),
						array(
							'type' => 'literal',
							'value' => '2',
						),
						array(
							'type' => 'literal',
							'value' => '3',
						),
						array(
							'type' => 'literal',
							'value' => '4',
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id IN (1, 2, 3, 4)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => 'IN',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'list',
					array(
						array(
							'type' => 'binary-op',
							'op' => '+',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'literal',
								'value' => '1',
							),
						),
						array(
							'type' => 'binary-op',
							'op' => '+',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'literal',
								'value' => '2',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r WHERE r.id IN (r.id+1, r.id+2)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
				'right' => array(
					'type' => 'placeholder',
					'value' => ':name',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.name = :name:');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
				'right' => array(
					'type' => 'placeholder',
					'value' => ':0',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.name = ?0');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<>',
				'left' => array(
					'type' => 'binary-op',
					'op' => '=',
					'left' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
					'right' => array(
						'type' => 'binary-op',
						'op' => 'OR',
						'left' => array(
							'type' => 'literal',
							'value' => '\'R2D2\'',
						),
						'right' => array(
							'type' => 'qualified',
							'domain' => 'robots',
							'name' => 'name',
							'balias' => 'name',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'C3PO\'',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.name = \'R2D2\' OR Robots.name <> \'C3PO\'');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<>',
				'left' => array(
					'type' => 'binary-op',
					'op' => '=',
					'left' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
					'right' => array(
						'type' => 'binary-op',
						'op' => 'AND',
						'left' => array(
							'type' => 'literal',
							'value' => '\'R2D2\'',
						),
						'right' => array(
							'type' => 'qualified',
							'domain' => 'robots',
							'name' => 'name',
							'balias' => 'name',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'C3PO\'',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.name = \'R2D2\' AND Robots.name <> \'C3PO\'');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<>',
				'left' => array(
					'type' => 'binary-op',
					'op' => '=',
					'left' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
					'right' => array(
						'type' => 'binary-op',
						'op' => 'AND',
						'left' => array(
							'type' => 'placeholder',
							'value' => ':first_name',
						),
						'right' => array(
							'type' => 'qualified',
							'domain' => 'robots',
							'name' => 'name',
							'balias' => 'name',
						),
					),
				),
				'right' => array(
					'type' => 'placeholder',
					'value' => ':second_name',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.name = :first_name: AND Robots.name <> :second_name:');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'binary-op',
					'op' => '<>',
					'left' => array(
						'type' => 'binary-op',
						'op' => '=',
						'left' => array(
							'type' => 'qualified',
							'domain' => 'robots',
							'name' => 'name',
							'balias' => 'name',
						),
						'right' => array(
							'type' => 'binary-op',
							'op' => 'AND',
							'left' => array(
								'type' => 'literal',
								'value' => '\'R2D2\'',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'name',
								'balias' => 'name',
							),
						),
					),
					'right' => array(
						'type' => 'binary-op',
						'op' => 'AND',
						'left' => array(
							'type' => 'literal',
							'value' => '\'C3PO\'',
						),
						'right' => array(
							'type' => 'qualified',
							'domain' => 'robots',
							'name' => 'id',
							'balias' => 'id',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.name = \'R2D2\' AND Robots.name <> \'C3PO\' AND Robots.id > 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'binary-op',
					'op' => 'OR',
					'left' => array(
						'type' => 'parentheses',
						'left' => array(
							'type' => 'binary-op',
							'op' => '<>',
							'left' => array(
								'type' => 'binary-op',
								'op' => '=',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'robots',
									'name' => 'name',
									'balias' => 'name',
								),
								'right' => array(
									'type' => 'binary-op',
									'op' => 'AND',
									'left' => array(
										'type' => 'literal',
										'value' => '\'R2D2\'',
									),
									'right' => array(
										'type' => 'qualified',
										'domain' => 'robots',
										'name' => 'name',
										'balias' => 'name',
									),
								),
							),
							'right' => array(
								'type' => 'literal',
								'value' => '\'C3PO\'',
							),
						),
					),
					'right' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'id',
						'balias' => 'id',
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE (Robots.name = \'R2D2\' AND Robots.name <> \'C3PO\') OR Robots.id > 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => 'OR',
				'left' => array(
					'type' => 'parentheses',
					'left' => array(
						'type' => 'binary-op',
						'op' => '<>',
						'left' => array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'name',
								'balias' => 'name',
							),
							'right' => array(
								'type' => 'binary-op',
								'op' => 'AND',
								'left' => array(
									'type' => 'literal',
									'value' => '\'R2D2\'',
								),
								'right' => array(
									'type' => 'qualified',
									'domain' => 'robots',
									'name' => 'name',
									'balias' => 'name',
								),
							),
						),
						'right' => array(
							'type' => 'literal',
							'value' => '\'C3PO\'',
						),
					),
				),
				'right' => array(
					'type' => 'parentheses',
					'left' => array(
						'type' => 'binary-op',
						'op' => '<=',
						'left' => array(
							'type' => 'binary-op',
							'op' => '>',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'binary-op',
								'op' => 'AND',
								'left' => array(
									'type' => 'literal',
									'value' => '100',
								),
								'right' => array(
									'type' => 'qualified',
									'domain' => 'robots',
									'name' => 'id',
									'balias' => 'id',
								),
							),
						),
						'right' => array(
							'type' => 'literal',
							'value' => '150',
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE (Robots.name = \'R2D2\' AND Robots.name <> \'C3PO\') OR (Robots.id > 100 AND Robots.id <= 150)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => 'NOT IN',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'list',
					array(
						array(
							'type' => 'binary-op',
							'op' => '+',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'literal',
								'value' => '1',
							),
						),
						array(
							'type' => 'binary-op',
							'op' => '+',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'id',
							),
							'right' => array(
								'type' => 'literal',
								'value' => '2',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r WHERE r.id NOT IN (r.id+1, r.id+2)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r LIMIT 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '100',
				),
				'offset' => array(
					'type' => 'literal',
					'value' => '10',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r LIMIT 10,100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '100',
				),
				'offset' => array(
					'type' => 'literal',
					'value' => '10',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r LIMIT 100 OFFSET 10');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				array(
					'le_products',
					NULL,
					'p',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Some\\Products',
					'column' => 'p',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'p',
					'name' => 'name',
					'balias' => 'name',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'Artichoke\'',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT * FROM Some\Products p WHERE p.name = "Artichoke" LIMIT 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				array(
					'le_products',
					NULL,
					'p',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Some\\Products',
					'column' => 'p',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'qualified',
						'domain' => 'p',
						'name' => 'name',
						'balias' => 'name',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Some\Products p ORDER BY p.name');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				'le_products',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Some\\Products',
					'column' => 'le_products',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'qualified',
						'domain' => 'le_products',
						'name' => 'name',
						'balias' => 'name',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Some\Products ORDER BY Some\Products.name');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				'le_products',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Some\\Products',
					'column' => 'le_products',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'qualified',
						'domain' => 'le_products',
						'name' => 'id',
						'balias' => 'id',
					),
				),
				array(
					array(
						'type' => 'qualified',
						'domain' => 'le_products',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				array(
					array(
						'type' => 'literal',
						'value' => '3',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Some\Products ORDER BY id, Some\Products.name, 3');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'unary-op',
				'op' => 'NOT ',
				'right' => array(
					'type' => 'parentheses',
					'left' => array(
						'type' => 'binary-op',
						'op' => '=',
						'left' => array(
							'type' => 'qualified',
							'domain' => 'r',
							'name' => 'name',
							'balias' => 'name',
						),
						'right' => array(
							'type' => 'literal',
							'value' => '\'shaggy\'',
						),
					),
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '1',
					),
				),
				array(
					array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'name',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r WHERE NOT (r.name = "shaggy") ORDER BY 1, r.name');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'unary-op',
				'op' => 'NOT ',
				'right' => array(
					'type' => 'parentheses',
					'left' => array(
						'type' => 'binary-op',
						'op' => '=',
						'left' => array(
							'type' => 'qualified',
							'domain' => 'r',
							'name' => 'name',
							'balias' => 'name',
						),
						'right' => array(
							'type' => 'literal',
							'value' => '\'shaggy\'',
						),
					),
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '1',
					),
					'DESC',
				),
				array(
					array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'name',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r WHERE NOT (r.name = "shaggy") ORDER BY 1 DESC, r.name');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'unary-op',
				'op' => 'NOT ',
				'right' => array(
					'type' => 'parentheses',
					'left' => array(
						'type' => 'binary-op',
						'op' => '=',
						'left' => array(
							'type' => 'qualified',
							'domain' => 'r',
							'name' => 'name',
							'balias' => 'name',
						),
						'right' => array(
							'type' => 'literal',
							'value' => '\'shaggy\'',
						),
					),
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '1',
					),
				),
				array(
					array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'name',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r WHERE NOT (r.name = "shaggy") ORDER BY 1, r.name');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'name',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'shaggy\'',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '1',
					),
				),
				array(
					array(
						'type' => 'literal',
						'value' => '2',
					),
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '5',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r WHERE r.name <> "shaggy" ORDER BY 1, 2 LIMIT 5');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'name',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'shaggy\'',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '1',
					),
					'ASC',
				),
				array(
					array(
						'type' => 'literal',
						'value' => '2',
					),
					'DESC',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '5',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r WHERE r.name <> "shaggy" ORDER BY 1 ASC, 2 DESC LIMIT 5');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots GROUP BY Robots.name');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots GROUP BY Robots.name, Robots.id');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'summatory' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'SUM',
						'arguments' => array(
							array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'price',
								'balias' => 'price',
							),
						),
					),
					'balias' => 'summatory',
					'sqlAlias' => 'summatory',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
		);
		$query = new Query('SELECT Robots.name, SUM(Robots.price) AS summatory FROM Robots GROUP BY Robots.name');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'id' => array(
					'type' => 'scalar',
					'balias' => 'id',
					'sqlAlias' => 'id',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'id',
						'balias' => 'id',
					),
				),
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'summatory' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'SUM',
						'arguments' => array(
							array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'price',
								'balias' => 'price',
							),
						),
					),
					'balias' => 'summatory',
					'sqlAlias' => 'summatory',
				),
				'_3' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'MIN',
						'arguments' => array(
							array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'price',
								'balias' => 'price',
							),
						),
					),
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'name',
				),
			),
		);
		$query = new Query('SELECT r.id, r.name, SUM(r.price) AS summatory, MIN(r.price) FROM Robots r GROUP BY r.id, r.name');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '5',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id > 5 GROUP BY Robots.name');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '5',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '10',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id > 5 GROUP BY Robots.name LIMIT 10');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '5',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'id',
						'balias' => 'id',
					),
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '10',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id > 5 GROUP BY Robots.name ORDER BY Robots.id LIMIT 10');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'id',
						'balias' => 'id',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots GROUP BY Robots.name ORDER BY Robots.id');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '10',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'id',
						'balias' => 'id',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id != 10 GROUP BY Robots.name ORDER BY Robots.id');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'COUNT',
						'arguments' => array(
							array(
								'type' => 'all',
							),
						),
					),
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'having' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'COUNT',
					'arguments' => array(
						array(
							'type' => 'all',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots GROUP BY Robots.name HAVING COUNT(*)>100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				'le_products',
			),
			'columns' => array(
				'type' => array(
					'type' => 'scalar',
					'balias' => 'type',
					'sqlAlias' => 'type',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'le_products',
						'name' => 'type',
						'balias' => 'type',
					),
				),
				'price' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'SUM',
						'arguments' => array(
							array(
								'type' => 'qualified',
								'domain' => 'le_products',
								'name' => 'price',
								'balias' => 'price',
							),
						),
					),
					'balias' => 'price',
					'sqlAlias' => 'price',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'le_products',
					'name' => 'type',
					'balias' => 'type',
				),
			),
			'having' => array(
				'type' => 'binary-op',
				'op' => '<',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'SUM',
					'arguments' => array(
						array(
							'type' => 'qualified',
							'name' => 'price',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT Some\Products.type, SUM(Some\Products.price) AS price FROM Some\Products GROUP BY Some\Products.type HAVING SUM(Some\Products.price)<100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				'le_products',
			),
			'columns' => array(
				'type' => array(
					'type' => 'scalar',
					'balias' => 'type',
					'sqlAlias' => 'type',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'le_products',
						'name' => 'type',
						'balias' => 'type',
					),
				),
				'price' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'SUM',
						'arguments' => array(
							array(
								'type' => 'qualified',
								'domain' => 'le_products',
								'name' => 'price',
								'balias' => 'price',
							),
						),
					),
					'balias' => 'price',
					'sqlAlias' => 'price',
				),
			),
			'group' => array(
				array(
					'type' => 'literal',
					'value' => '1',
				),
			),
			'having' => array(
				'type' => 'binary-op',
				'op' => '<',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'SUM',
					'arguments' => array(
						array(
							'type' => 'qualified',
							'name' => 'price',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT type, SUM(price) AS price FROM Some\Products GROUP BY 1 HAVING SUM(price)<100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				'le_products',
			),
			'columns' => array(
				'price' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'COUNT',
						'arguments' => array(
							array(
								'type' => 'qualified',
								'domain' => 'le_products',
								'name' => 'type',
								'balias' => 'type',
							),
						),
						'distinct' => 1,
					),
					'balias' => 'price',
					'sqlAlias' => 'price',
				),
			),
		);
		$query = new Query('SELECT COUNT(DISTINCT Some\Products.type) AS price FROM Some\Products');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Products',
			),
			'tables' => array(
				'le_products',
			),
			'columns' => array(
				'price' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'COUNT',
						'arguments' => array(
							array(
								'type' => 'qualified',
								'domain' => 'le_products',
								'name' => 'type',
								'balias' => 'type',
							),
						),
						'distinct' => 1,
					),
					'balias' => 'price',
					'sqlAlias' => 'price',
				),
			),
		);
		$query = new Query('SELECT COUNT(DISTINCT Some\Products.type) price FROM Some\Products');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'COUNT',
						'arguments' => array(
							array(
								'type' => 'all',
							),
						),
					),
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'type',
					'balias' => 'type',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'virtual\'',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'having' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'COUNT',
					'arguments' => array(
						array(
							'type' => 'all',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots WHERE Robots.type = "virtual" GROUP BY Robots.name HAVING COUNT(*)>100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'COUNT',
						'arguments' => array(
							array(
								'type' => 'all',
							),
						),
					),
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'type',
					'balias' => 'type',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'virtual\'',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'having' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'COUNT',
					'arguments' => array(
						array(
							'type' => 'all',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '2',
					),
				),
			),
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots WHERE Robots.type = "virtual" GROUP BY Robots.name HAVING COUNT(*)>100 ORDER BY 2');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'COUNT',
						'arguments' => array(
							array(
								'type' => 'all',
							),
						),
					),
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'type',
					'balias' => 'type',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'virtual\'',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'having' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'COUNT',
					'arguments' => array(
						array(
							'type' => 'all',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '2',
					),
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '15',
				),
			),
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots WHERE Robots.type = "virtual" GROUP BY Robots.name HAVING COUNT(*)>100 ORDER BY 2 LIMIT 15');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'COUNT',
						'arguments' => array(
							array(
								'type' => 'all',
							),
						),
					),
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'having' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'COUNT',
					'arguments' => array(
						array(
							'type' => 'all',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '2',
					),
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '15',
				),
			),
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots GROUP BY Robots.name HAVING COUNT(*)>100 ORDER BY 2 LIMIT 15');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'COUNT',
						'arguments' => array(
							array(
								'type' => 'all',
							),
						),
					),
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'type',
					'balias' => 'type',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'virtual\'',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'having' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'COUNT',
					'arguments' => array(
						array(
							'type' => 'all',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '15',
				),
			),
		);
		$query = new Query('SELECT name, COUNT(*) FROM Robots WHERE type = "virtual" GROUP BY name HAVING COUNT(*)>100 LIMIT 15');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'COUNT',
						'arguments' => array(
							array(
								'type' => 'all',
							),
						),
					),
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'type',
					'balias' => 'type',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'virtual\'',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'having' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'COUNT',
					'arguments' => array(
						array(
							'type' => 'all',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '15',
				),
			),
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots WHERE Robots.type = "virtual" GROUP BY Robots.name HAVING COUNT(*)>100 LIMIT 15');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'COUNT',
						'arguments' => array(
							array(
								'type' => 'all',
							),
						),
					),
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'having' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'functionCall',
					'name' => 'COUNT',
					'arguments' => array(
						array(
							'type' => 'all',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '15',
				),
			),
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots GROUP BY Robots.name HAVING COUNT(*)>100 LIMIT 15');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Some\\Robotters',
					'column' => 'robots',
				),
			),
		);
		$query = new Query('SELECT * FROM Some\Robotters');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'some\\Robotters' => array(
					'type' => 'object',
					'model' => 'Some\\Robotters',
					'column' => 'robots',
					'balias' => 'some\\Robotters',
				),
			),
		);
		$query = new Query('SELECT Some\Robotters.* FROM Some\Robotters');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Some\\Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Some\\Robotters',
					'column' => 'r',
					'balias' => 'r',
				),
			),
		);
		$query = new Query('SELECT r.* FROM Some\Robotters r');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'robotters' => array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
					'balias' => 'robotters',
				),
			),
		);
		$query = new Query('SELECT Robotters.* FROM Robotters');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
					'balias' => 'r',
				),
			),
		);
		$query = new Query('SELECT r.* FROM Robotters r');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
					'balias' => 'r',
				),
			),
		);
		$query = new Query('SELECT r.* FROM Robotters AS r');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'code' => array(
					'type' => 'scalar',
					'balias' => 'code',
					'sqlAlias' => 'code',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'id',
						'balias' => 'code',
					),
				),
				'theName' => array(
					'type' => 'scalar',
					'balias' => 'theName',
					'sqlAlias' => 'theName',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'theName',
					),
				),
			),
		);
		$query = new Query('SELECT code, theName FROM Robotters');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'code' => array(
					'type' => 'scalar',
					'balias' => 'code',
					'sqlAlias' => 'code',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'id',
						'balias' => 'code',
					),
				),
				'theName' => array(
					'type' => 'scalar',
					'balias' => 'theName',
					'sqlAlias' => 'theName',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'theName',
					),
				),
			),
		);
		$query = new Query('SELECT r.code, r.theName FROM Robotters AS r');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'le_id' => array(
					'type' => 'scalar',
					'balias' => 'le_id',
					'sqlAlias' => 'le_id',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'id',
						'balias' => 'code',
					),
				),
				'le_name' => array(
					'type' => 'scalar',
					'balias' => 'le_name',
					'sqlAlias' => 'le_name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'theName',
					),
				),
			),
		);
		$query = new Query('SELECT r.code AS le_id, r.theName AS le_name FROM Robotters AS r');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'le_id' => array(
					'type' => 'scalar',
					'balias' => 'le_id',
					'sqlAlias' => 'le_id',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'id',
						'balias' => 'code',
					),
				),
				'le_name' => array(
					'type' => 'scalar',
					'balias' => 'le_name',
					'sqlAlias' => 'le_name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'theName',
					),
				),
			),
		);
		$query = new Query('SELECT Robotters.code AS le_id, Robotters.theName AS le_name FROM Robotters');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'empty_str' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'literal',
						'value' => '\'\'',
					),
					'balias' => 'empty_str',
					'sqlAlias' => 'empty_str',
				),
				'double_number' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'literal',
						'value' => '10.5',
					),
					'balias' => 'double_number',
					'sqlAlias' => 'double_number',
				),
				'long_number' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'literal',
						'value' => '1000',
					),
					'balias' => 'long_number',
					'sqlAlias' => 'long_number',
				),
			),
		);
		$query = new Query('SELECT \'\' empty_str, 10.5 double_number, 1000 AS long_number FROM Robotters');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Personers',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'borgerId' => array(
					'type' => 'scalar',
					'balias' => 'borgerId',
					'sqlAlias' => 'borgerId',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'personas',
						'name' => 'cedula',
						'balias' => 'borgerId',
					),
				),
			),
		);
		$query = new Query('SELECT Personers.borgerId FROM Personers');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'personers',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'borgerId' => array(
					'type' => 'scalar',
					'balias' => 'borgerId',
					'sqlAlias' => 'borgerId',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'personas',
						'name' => 'cedula',
						'balias' => 'borgerId',
					),
				),
			),
		);
		$query = new Query('select personers.borgerId from personers');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Personers',
			),
			'tables' => array(
				array(
					'personas',
					NULL,
					'p',
				),
			),
			'columns' => array(
				'cedula' => array(
					'type' => 'scalar',
					'balias' => 'cedula',
					'sqlAlias' => 'cedula',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'p',
						'name' => 'cedula',
						'balias' => 'borgerId',
					),
				),
			),
		);
		$query = new Query('SELECT p.borgerId AS cedula FROM Personers p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Personers',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'navne' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'functionCall',
						'name' => 'CONCAT',
						'arguments' => array(
							array(
								'type' => 'qualified',
								'domain' => 'personas',
								'name' => 'cedula',
								'balias' => 'borgerId',
							),
							array(
								'type' => 'literal',
								'value' => '\'-\'',
							),
							array(
								'type' => 'qualified',
								'domain' => 'personas',
								'name' => 'nombres',
								'balias' => 'navnes',
							),
						),
					),
					'balias' => 'navne',
					'sqlAlias' => 'navne',
				),
			),
		);
		$query = new Query('SELECT CONCAT(Personers.borgerId,\'-\',Personers.navnes) AS navne FROM Personers');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters JOIN RobottersDeles');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'CROSS',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters CROSS JOIN RobottersDeles');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
				array(
					'type' => 'object',
					'model' => 'Deles',
					'column' => 'parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'LEFT',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
				array(
					'type' => 'RIGHT',
					'source' => array(
						'parts',
						NULL,
					),
					'conditions' => array(
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters LEFT JOIN RobottersDeles RIGHT JOIN Deles');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'RobottersDeles',
			),
			'tables' => array(
				'robots_parts',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'Deles',
					'column' => 'parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'LEFT',
					'source' => array(
						'robots',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'code',
							),
						),
					),
				),
				array(
					'type' => 'RIGHT',
					'source' => array(
						'parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'parts_id',
								'balias' => 'delesCode',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'parts',
								'name' => 'id',
								'balias' => 'code',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM RobottersDeles LEFT OUTER JOIN Robotters RIGHT OUTER JOIN Deles');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters JOIN RobottersDeles ON Robotters.code = RobottersDeles.robottersCode');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'LEFT',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'binary-op',
								'op' => '=',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'robots',
									'name' => 'id',
									'balias' => 'code',
								),
								'right' => array(
									'type' => 'binary-op',
									'op' => 'AND',
									'left' => array(
										'type' => 'qualified',
										'domain' => 'robots_parts',
										'name' => 'robots_id',
										'balias' => 'robottersCode',
									),
									'right' => array(
										'type' => 'qualified',
										'domain' => 'robots_parts',
										'name' => 'robots_id',
										'balias' => 'robottersCode',
									),
								),
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'code',
							),
						),
					),
				),
			),
			'where' => array(
				'type' => 'unary-op',
				'op' => ' IS NULL',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'code',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters LEFT OUTER JOIN RobottersDeles ON Robotters.code = RobottersDeles.robottersCode AND RobottersDeles.robottersCode = Robotters.code WHERE Robotters.code IS NULL');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'RIGHT',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'binary-op',
								'op' => '=',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'robots',
									'name' => 'id',
									'balias' => 'code',
								),
								'right' => array(
									'type' => 'binary-op',
									'op' => 'AND',
									'left' => array(
										'type' => 'qualified',
										'domain' => 'robots_parts',
										'name' => 'robots_id',
										'balias' => 'robottersCode',
									),
									'right' => array(
										'type' => 'qualified',
										'domain' => 'robots_parts',
										'name' => 'robots_id',
										'balias' => 'robottersCode',
									),
								),
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'code',
							),
						),
					),
				),
			),
			'where' => array(
				'type' => 'unary-op',
				'op' => ' IS NOT NULL',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots_parts',
					'name' => 'robots_id',
					'balias' => 'robottersCode',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters RIGHT OUTER JOIN RobottersDeles ON Robotters.code = RobottersDeles.robottersCode AND RobottersDeles.robottersCode = Robotters.code WHERE RobottersDeles.robottersCode IS NOT NULL');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
			),
			'joins' => array(
				array(
					'type' => 'FULL OUTER',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters FULL OUTER JOIN RobottersDeles');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'RobottersDeles',
			),
			'tables' => array(
				'robots_parts',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'code',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM RobottersDeles JOIN Robotters');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
					'balias' => 'r',
				),
				'p' => array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'p',
					'balias' => 'p',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
						'p',
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'p',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT r.*, p.* FROM Robotters AS r JOIN RobottersDeles AS p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'p',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
						'p',
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'p',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters AS r JOIN RobottersDeles AS p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
					'balias' => 'r',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT r.* FROM Robotters r INNER JOIN RobottersDeles');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'RobottersDeles',
			),
			'tables' => array(
				'robots_parts',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots',
								'name' => 'id',
								'balias' => 'code',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM RobottersDeles JOIN Robotters');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
					'balias' => 'r',
				),
				'p' => array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'p',
					'balias' => 'p',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
						'p',
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'p',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT r.*, p.* FROM Robotters AS r JOIN RobottersDeles AS p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'p',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
						'p',
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'p',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters AS r JOIN RobottersDeles AS p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				'r' => array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
					'balias' => 'r',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'robots_parts',
						NULL,
					),
					'conditions' => array(
						array(
							'type' => 'binary-op',
							'op' => '=',
							'left' => array(
								'type' => 'qualified',
								'domain' => 'r',
								'name' => 'id',
								'balias' => 'code',
							),
							'right' => array(
								'type' => 'qualified',
								'domain' => 'robots_parts',
								'name' => 'robots_id',
								'balias' => 'robottersCode',
							),
						),
					),
				),
			),
		);
		$query = new Query('SELECT r.* FROM Robotters r INNER JOIN RobottersDeles');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Personers',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'_0' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'binary-op',
						'op' => '/',
						'left' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '+',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'personas',
									'name' => 'cupo',
									'balias' => 'kredit',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '100',
								),
							),
						),
						'right' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '*',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'products',
									'name' => 'price',
									'balias' => 'price',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '0.15',
								),
							),
						),
					),
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'products',
						NULL,
					),
					'conditions' => array(
					),
				),
			),
		);
		$query = new Query('SELECT ( Personers.kredit + 100) / (Products.price * 0.15) FROM Personers JOIN Products');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Personers',
			),
			'tables' => array(
				'personas',
			),
			'columns' => array(
				'price' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'binary-op',
						'op' => '/',
						'left' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '+',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'personas',
									'name' => 'cupo',
									'balias' => 'kredit',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '100',
								),
							),
						),
						'right' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '*',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'le_products',
									'name' => 'price',
									'balias' => 'price',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '0.15',
								),
							),
						),
					),
					'balias' => 'price',
					'sqlAlias' => 'price',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'le_products',
						NULL,
					),
					'conditions' => array(
					),
				),
			),
		);
		$query = new Query('SELECT ( Personers.kredit + 100) / (Some\Products.price * 0.15) AS price FROM Personers JOIN Some\Products');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Personers',
			),
			'tables' => array(
				array(
					'personas',
					NULL,
					'p',
				),
			),
			'columns' => array(
				'price' => array(
					'type' => 'scalar',
					'column' => array(
						'type' => 'binary-op',
						'op' => '/',
						'left' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '+',
								'left' => array(
									'type' => 'qualified',
									'domain' => 'p',
									'name' => 'cupo',
									'balias' => 'kredit',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '100',
								),
							),
						),
						'right' => array(
							'type' => 'parentheses',
							'left' => array(
								'type' => 'binary-op',
								'op' => '*',
								'left' => array(
									'type' => 'qualified',
									'domain' => 's',
									'name' => 'price',
									'balias' => 'price',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '0.15',
								),
							),
						),
					),
					'balias' => 'price',
					'sqlAlias' => 'price',
				),
			),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => array(
						'le_products',
						NULL,
						's',
					),
					'conditions' => array(
					),
				),
			),
		);
		$query = new Query('SELECT (p.kredit + 100) / (s.price * 0.15) AS price FROM Personers AS p JOIN Some\Products AS s');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
				'RobottersDeles',
			),
			'tables' => array(
				'robots',
				'robots_parts',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters, RobottersDeles');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
				'RobottersDeles',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
				array(
					'robots_parts',
					NULL,
					'p',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'p',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters r, RobottersDeles p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
				'RobottersDeles',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
				array(
					'robots_parts',
					NULL,
					'p',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'p',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters AS r, RobottersDeles AS p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
				'RobottersDeles',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
				array(
					'robots_parts',
					NULL,
					'p',
				),
			),
			'columns' => array(
				'theName' => array(
					'type' => 'scalar',
					'balias' => 'theName',
					'sqlAlias' => 'theName',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'theName',
					),
				),
				'delesCode' => array(
					'type' => 'scalar',
					'balias' => 'delesCode',
					'sqlAlias' => 'delesCode',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'p',
						'name' => 'parts_id',
						'balias' => 'delesCode',
					),
				),
			),
		);
		$query = new Query('SELECT theName, delesCode FROM Robotters AS r, RobottersDeles AS p');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
				'RobottersDeles',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
				array(
					'robots_parts',
					NULL,
					'p',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'p',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'code',
				),
				'right' => array(
					'type' => 'qualified',
					'domain' => 'p',
					'name' => 'robots_id',
					'balias' => 'robottersCode',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters AS r, RobottersDeles AS p WHERE r.code = p.robottersCode');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
				'RobottersDeles',
			),
			'tables' => array(
				'robots',
				'robots_parts',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
				array(
					'type' => 'object',
					'model' => 'RobottersDeles',
					'column' => 'robots_parts',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '=',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'code',
				),
				'right' => array(
					'type' => 'qualified',
					'domain' => 'robots_parts',
					'name' => 'robots_id',
					'balias' => 'robottersCode',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters, RobottersDeles WHERE Robotters.code = RobottersDeles.robottersCode');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'unary-op',
				'op' => 'NOT ',
				'right' => array(
					'type' => 'parentheses',
					'left' => array(
						'type' => 'binary-op',
						'op' => '=',
						'left' => array(
							'type' => 'qualified',
							'domain' => 'r',
							'name' => 'name',
							'balias' => 'theName',
						),
						'right' => array(
							'type' => 'literal',
							'value' => '\'shaggy\'',
						),
					),
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '1',
					),
				),
				array(
					array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'theName',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters r WHERE NOT (r.theName = "shaggy") ORDER BY 1, r.theName');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'unary-op',
				'op' => 'NOT ',
				'right' => array(
					'type' => 'parentheses',
					'left' => array(
						'type' => 'binary-op',
						'op' => '=',
						'left' => array(
							'type' => 'qualified',
							'domain' => 'r',
							'name' => 'name',
							'balias' => 'theName',
						),
						'right' => array(
							'type' => 'literal',
							'value' => '\'shaggy\'',
						),
					),
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '1',
					),
					'DESC',
				),
				array(
					array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'theName',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters r WHERE NOT (r.theName = "shaggy") ORDER BY 1 DESC, r.theName');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'unary-op',
				'op' => 'NOT ',
				'right' => array(
					'type' => 'parentheses',
					'left' => array(
						'type' => 'binary-op',
						'op' => '=',
						'left' => array(
							'type' => 'qualified',
							'domain' => 'r',
							'name' => 'name',
							'balias' => 'theName',
						),
						'right' => array(
							'type' => 'literal',
							'value' => '\'shaggy\'',
						),
					),
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '1',
					),
				),
				array(
					array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'name',
						'balias' => 'theName',
					),
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters r WHERE NOT (r.theName = "shaggy") ORDER BY 1, r.theName');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'theName',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'shaggy\'',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '1',
					),
				),
				array(
					array(
						'type' => 'literal',
						'value' => '2',
					),
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '5',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters r WHERE r.theName <> "shaggy" ORDER BY 1, 2 LIMIT 5');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'r',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'theName',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '\'shaggy\'',
				),
			),
			'order' => array(
				array(
					array(
						'type' => 'literal',
						'value' => '1',
					),
					'ASC',
				),
				array(
					array(
						'type' => 'literal',
						'value' => '2',
					),
					'DESC',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '5',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters r WHERE r.theName <> "shaggy" ORDER BY 1 ASC, 2 DESC LIMIT 5');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'theName',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters GROUP BY Robotters.theName');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robotters',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robotters',
					'column' => 'robots',
				),
			),
			'group' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'theName',
				),
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'code',
				),
			),
		);
		$query = new Query('SELECT * FROM Robotters GROUP BY Robotters.theName, Robotters.code');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		// Issue 1011
		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'placeholder',
					'value' => ':limit',
				),
				'offset' => array(
					'type' => 'placeholder',
					'value' => ':1',
				),
			),
		);
		$query = new Query('SELECT * FROM Robots r LIMIT ?1,:limit:');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		// SELECT DISTINCT and SELECT ALL
		$expected = array(
			'distinct' => 1,
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				'id' => array(
					'type' => 'scalar',
					'balias' => 'id',
					'sqlAlias' => 'id',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'id',
						'balias' => 'id',
					),
				),
				'name' => array(
					'type' => 'scalar',
					'balias' => 'name',
					'sqlAlias' => 'name',
					'column' => array(
						'type' => 'qualified',
						'domain' => 'robots',
						'name' => 'name',
						'balias' => 'name',
					),
				),
			),
		);

		$query = new Query('SELECT DISTINCT id, name FROM Robots');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$query = new Query('SELECT ALL id, name FROM Robots');
		$query->setDI($di);
		$expected['distinct'] = 0;
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'models' => array(
				'Robots',
			),
			'tables' => array(
				'robots',
			),
			'columns' => array(
				array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => 'IN',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'select',
					'value' => array(
						'models' => array(
							'RobotsParts',
						),
						'tables' => array(
							'robots_parts',
						),
						'columns' => array(
							'robots_id' => array(
								'type' => 'scalar',
								'balias' => 'robots_id',
								'sqlAlias' => 'robots_id',
								'sqlAlias' => 'robots_id',
								'column' => array(
									'type' => 'qualified',
									'domain' => 'robots_parts',
									'name' => 'robots_id',
									'balias' => 'robots_id',
								),
							),
						),
					),
				),
			),
		);

		$query = new Query('SELECT * FROM Robots WHERE id IN (SELECT robots_id FROM RobotsParts)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);
	}

	public function testInsertParsing()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$expected = array(
			'model' => 'Robots',
			'table' => 'robots',
			'values' => array(
				array(
					'type' => 322,
					'value' => array(
						'type' => 'literal',
						'value' => 'NULL',
					),
				),
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some robot',
					),
				),
				array(
					'type' => 258,
					'value' => array(
						'type' => 'literal',
						'value' => '1945',
					),
				),
			),
		);
		$query = new Query('INSERT INTO Robots VALUES (NULL, \'some robot\', 1945)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'model' => 'robots',
			'table' => 'robots',
			'values' => array(
				array(
					'type' => 322,
					'value' => array(
						'type' => 'literal',
						'value' => 'NULL',
					),
				),
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some robot',
					),
				),
				array(
					'type' => 258,
					'value' => array(
						'type' => 'literal',
						'value' => '1945',
					),
				),
			),
		);
		$query = new Query('insert into robots values (null, \'some robot\', 1945)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'model' => 'Some\\Products',
			'table' => 'le_products',
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'Some name',
					),
				),
				array(
					'type' => 259,
					'value' => array(
						'type' => 'literal',
						'value' => '100.15',
					),
				),
				array(
					'type' => 350,
					'value' => array(
						'type' => 'functionCall',
						'name' => 'current_date',
					),
				),
				array(
					'type' => 350,
					'value' => array(
						'type' => 'functionCall',
						'name' => 'now',
					),
				),
			),
		);
		$query = new Query('INSERT INTO Some\\Products VALUES ("Some name", 100.15, current_date(), now())');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'model' => 'Robots',
			'table' => 'robots',
			'values' => array(
				array(
					'type' => 356,
					'value' => array(
						'type' => 'parentheses',
						'left' => array(
							'type' => 'binary-op',
							'op' => '*',
							'left' => array(
								'type' => 'binary-op',
								'op' => '+',
								'left' => array(
									'type' => 'literal',
									'value' => '1',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '1000',
								),
							),
							'right' => array(
								'type' => 'placeholder',
								'value' => ':le_id',
							),
						),
					),
				),
				array(
					'type' => 350,
					'value' => array(
						'type' => 'functionCall',
						'name' => 'CONCAT',
						'arguments' => array(
							array(
								'type' => 'literal',
								'value' => '\'some\'',
							),
							array(
								'type' => 'literal',
								'value' => '\'robot\'',
							),
						),
					),
				),
				array(
					'type' => 258,
					'value' => array(
						'type' => 'literal',
						'value' => '2011',
					),
				),
			),
		);
		$query = new Query('INSERT INTO Robots VALUES ((1+1000*:le_id:), CONCAT(\'some\', \'robot\'), 2011)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'model' => 'Robots',
			'table' => 'robots',
			'fields' => array(
				'name',
				'type',
				'year',
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'a name',
					),
				),
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'virtual',
					),
				),
				array(
					'type' => 273,
					'value' => array(
						'type' => 'placeholder',
						'value' => ':0',
					),
				),
			),
		);
		$query = new Query('INSERT INTO Robots (name, type, year) VALUES (\'a name\', \'virtual\', ?0)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'model' => 'Robotters',
			'table' => 'robots',
			'values' => array(
				array(
					'type' => 322,
					'value' => array(
						'type' => 'literal',
						'value' => 'NULL',
					),
				),
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some robot',
					),
				),
				array(
					'type' => 258,
					'value' => array(
						'type' => 'literal',
						'value' => '1945',
					),
				),
			),
		);
		$query = new Query('INSERT INTO Robotters VALUES (NULL, \'some robot\', 1945)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'model' => 'robotters',
			'table' => 'robots',
			'values' => array(
				array(
					'type' => 322,
					'value' => array(
						'type' => 'literal',
						'value' => 'NULL',
					),
				),
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some robot',
					),
				),
				array(
					'type' => 258,
					'value' => array(
						'type' => 'literal',
						'value' => '1945',
					),
				),
			),
		);
		$query = new Query('insert into robotters values (null, \'some robot\', 1945)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'model' => 'Robotters',
			'table' => 'robots',
			'values' => array(
				array(
					'type' => 356,
					'value' => array(
						'type' => 'parentheses',
						'left' => array(
							'type' => 'binary-op',
							'op' => '*',
							'left' => array(
								'type' => 'binary-op',
								'op' => '+',
								'left' => array(
									'type' => 'literal',
									'value' => '1',
								),
								'right' => array(
									'type' => 'literal',
									'value' => '1000',
								),
							),
							'right' => array(
								'type' => 'placeholder',
								'value' => ':le_id',
							),
						),
					),
				),
				array(
					'type' => 350,
					'value' => array(
						'type' => 'functionCall',
						'name' => 'CONCAT',
						'arguments' => array(
							array(
								'type' => 'literal',
								'value' => '\'some\'',
							),
							array(
								'type' => 'literal',
								'value' => '\'robot\'',
							),
						),
					),
				),
				array(
					'type' => 258,
					'value' => array(
						'type' => 'literal',
						'value' => '2011',
					),
				),
			),
		);
		$query = new Query('INSERT INTO Robotters VALUES ((1+1000*:le_id:), CONCAT(\'some\', \'robot\'), 2011)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'model' => 'Robotters',
			'table' => 'robots',
			'fields' => array(
				'theName',
				'theType',
				'theYear',
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'a name',
					),
				),
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'virtual',
					),
				),
				array(
					'type' => 273,
					'value' => array(
						'type' => 'placeholder',
						'value' => ':0',
					),
				),
			),
		);
		$query = new Query('INSERT INTO Robotters (theName, theType, theYear) VALUES (\'a name\', \'virtual\', ?0)');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);
	}

	public function testUpdateParsing()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$expected = array(
			'tables' => array(
				'robots',
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
			),
		);
		$query = new Query('UPDATE Robots SET name = \'some name\'');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				'robots',
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
			),
		);
		$query = new Query('UPDATE Robots SET Robots.name = \'some name\'');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				'le_products',
			),
			'models' => array(
				'Some\\Products',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'le_products',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
			),
		);
		$query = new Query('UPDATE Some\\Products SET Some\\Products.name = "some name"');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'le_products',
					NULL,
					'p',
				),
			),
			'models' => array(
				'Some\\Products',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'p',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
			),
		);
		$query = new Query('UPDATE Some\\Products p SET p.name = "some name"');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				'robots',
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'year',
					'balias' => 'year',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
				array(
					'type' => 258,
					'value' => array(
						'type' => 'literal',
						'value' => '1990',
					),
				),
			),
		);
		$query = new Query('UPDATE Robots SET Robots.name = \'some name\', Robots.year = 1990');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'le_products',
					NULL,
					'p',
				),
			),
			'models' => array(
				'Some\\Products',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'p',
					'name' => 'name',
					'balias' => 'name',
				),
				array(
					'type' => 'qualified',
					'domain' => 'p',
					'name' => 'year',
					'balias' => 'year',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
				array(
					'type' => 258,
					'value' => array(
						'type' => 'literal',
						'value' => '1990',
					),
				),
			),
		);
		$query = new Query('UPDATE Some\\Products p SET p.name = "some name", p.year = 1990');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				'robots',
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'name',
					'balias' => 'name',
				),
				array(
					'type' => 'qualified',
					'domain' => 'robots',
					'name' => 'year',
					'balias' => 'year',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
				array(
					'type' => 43,
					'value' => array(
						'type' => 'binary-op',
						'op' => '+',
						'left' => array(
							'type' => 'functionCall',
							'name' => 'YEAR',
							'arguments' => array(
								array(
									'type' => 'functionCall',
									'name' => 'current_date',
								),
							),
						),
						'right' => array(
							'type' => 'qualified',
							'domain' => 'robots',
							'name' => 'year',
							'balias' => 'year',
						),
					),
				),
			),
		);
		$query = new Query('UPDATE Robots SET Robots.name = \'some name\', Robots.year = YEAR(current_date()) + Robots.year');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'name',
				),
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'year',
					'balias' => 'year',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
				array(
					'type' => 43,
					'value' => array(
						'type' => 'binary-op',
						'op' => '+',
						'left' => array(
							'type' => 'functionCall',
							'name' => 'YEAR',
							'arguments' => array(
								array(
									'type' => 'functionCall',
									'name' => 'current_date',
								),
							),
						),
						'right' => array(
							'type' => 'qualified',
							'domain' => 'r',
							'name' => 'year',
							'balias' => 'year',
						),
					),
				),
			),
		);
		$query = new Query('UPDATE Robots AS r SET r.name = \'some name\', r.year = YEAR(current_date()) + r.year');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('UPDATE Robots AS r SET r.name = \'some name\' WHERE r.id > 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'name',
				),
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'year',
					'balias' => 'year',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
				array(
					'type' => 42,
					'value' => array(
						'type' => 'binary-op',
						'op' => '*',
						'left' => array(
							'type' => 'qualified',
							'domain' => 'r',
							'name' => 'year',
							'balias' => 'year',
						),
						'right' => array(
							'type' => 'literal',
							'value' => '2',
						),
					),
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '<=',
				'left' => array(
					'type' => 'binary-op',
					'op' => '>',
					'left' => array(
						'type' => 'qualified',
						'domain' => 'r',
						'name' => 'id',
						'balias' => 'id',
					),
					'right' => array(
						'type' => 'binary-op',
						'op' => 'AND',
						'left' => array(
							'type' => 'literal',
							'value' => '100',
						),
						'right' => array(
							'type' => 'qualified',
							'domain' => 'r',
							'name' => 'id',
							'balias' => 'id',
						),
					),
				),
				'right' => array(
					'type' => 'literal',
					'value' => '200',
				),
			),
		);
		$query = new Query('update Robots as r set r.name = \'some name\', r.year = r.year*2 where r.id > 100 and r.id <= 200');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '10',
				),
			),
		);
		$query = new Query('UPDATE Robots AS r SET r.name = \'some name\' LIMIT 10');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '10',
				),
			),
		);
		$query = new Query('UPDATE Robots r SET r.name = \'some name\' LIMIT 10');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '10',
				),
			),
		);
		$query = new Query('UPDATE Robots AS r SET r.name = \'some name\' WHERE r.id > 100 LIMIT 10');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		// Issue 1011
		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'fields' => array(
				array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'name',
					'balias' => 'name',
				),
			),
			'values' => array(
				array(
					'type' => 260,
					'value' => array(
						'type' => 'literal',
						'value' => 'some name',
					),
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'placeholder',
					'value' => ':1',
				),
			),
		);
		$query = new Query('UPDATE Robots r SET r.name = \'some name\' LIMIT ?1');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);
	}

	public function testDeleteParsing()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$expected = array(
			'tables' => array(
				'robots',
			),
			'models' => array(
				'Robots',
			),
		);
		$query = new Query('DELETE FROM Robots');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('DELETE FROM Robots AS r WHERE r.id > 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('DELETE FROM Robots r WHERE r.id > 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
		);
		$query = new Query('delete from Robots as r where r.id > 100');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '10',
				),
			),
		);
		$query = new Query('DELETE FROM Robots r LIMIT 10');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'literal',
					'value' => '10',
				),
			),
		);
		$query = new Query('DELETE FROM Robots r WHERE r.id > 100 LIMIT 10');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);

		// Issue 1011
		$expected = array(
			'tables' => array(
				array(
					'robots',
					NULL,
					'r',
				),
			),
			'models' => array(
				'Robots',
			),
			'where' => array(
				'type' => 'binary-op',
				'op' => '>',
				'left' => array(
					'type' => 'qualified',
					'domain' => 'r',
					'name' => 'id',
					'balias' => 'id',
				),
				'right' => array(
					'type' => 'literal',
					'value' => '100',
				),
			),
			'limit' => array(
				'number' => array(
					'type' => 'placeholder',
					'value' => ':limit',
				),
			),
		);
		$query = new Query('DELETE FROM Robots r WHERE r.id > 100 LIMIT :limit:');
		$query->setDI($di);
		$this->assertEquals($query->parse(), $expected);
	}

}
