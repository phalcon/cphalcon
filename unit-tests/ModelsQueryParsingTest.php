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
		});

		return $di;
	}

	public function testSelectParsing()
	{

		$di = $this->_getDI();

		$manager = $di->getShared('modelsManager');

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				)
			),
			'tables' => array('robots'),

		);
		$query = new Query("SELECT * FROM Robots");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Some\Products',
					'column' => 'le_products'
				)
			),
			'tables' => array('le_products'),

		);
		$query = new Query('SELECT * FROM Some\Products');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Some\Products',
					'column' => 'le_products'
				)
			),
			'tables' => array('le_products'),

		);
		$query = new Query('SELECT Some\Products.* FROM Some\Products');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Some\Products',
					'column' => 'p'
				)
			),
			'tables' => array('le_products p'),

		);
		$query = new Query('SELECT p.* FROM Some\Products p');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				)
			),
			'tables' => array('robots'),

		);
		$query = new Query("SELECT Robots.* FROM Robots");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				)
			),
			'tables' => array('robots r'),

		);
		$query = new Query("SELECT r.* FROM Robots r");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				)
			),
			'tables' => array('robots r'),

		);
		$query = new Query("SELECT r.* FROM Robots AS r");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'id' => array(
					'type' => 'scalar',
					'column' => 'r.id',
					'balias' => 'id'
				),
				'name' => array(
					'type' => 'scalar',
					'column' => 'r.name',
					'balias' => 'name'
				)
			),
			'tables' => array('robots r'),

		);
		$query = new Query("SELECT r.id, r.name FROM Robots AS r");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'le_id' => array(
					'type' => 'scalar',
					'column' => 'r.id',
					'balias' => 'le_id'
				),
				'le_name' => array(
					'type' => 'scalar',
					'column' => 'r.name',
					'balias' => 'le_name'
				)
			),
			'tables' => array('robots r'),

		);
		$query = new Query("SELECT r.id AS le_id, r.name AS le_name FROM Robots AS r");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'le_id' => array(
					'type' => 'scalar',
					'column' => 'robots.id',
					'balias' => 'le_id'
				),
				'le_name' => array(
					'type' => 'scalar',
					'column' => 'robots.name',
					'balias' => 'le_name'
				)
			),
			'tables' => array('robots'),

		);
		$query = new Query("SELECT Robots.id AS le_id, Robots.name AS le_name FROM Robots");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'empty_str' => array(
					'type' => 'scalar',
					'column' => "''",
					'balias' => 'empty_str'
				),
				'double_number' => array(
					'type' => 'scalar',
					'column' => '10.5',
					'balias' => 'double_number'
				),
				'long_number' => array(
					'type' => 'scalar',
					'column' => '1000',
					'balias' => 'long_number'
				)
			),
			'tables' => array('robots'),

		);
		$query = new Query("SELECT '' empty_str, 10.5 double_number, 1000 AS long_number FROM Robots");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('People'),
			'columns' => array(
				'cedula' => array(
					'type' => 'scalar',
					'column' => 'personas.cedula',
					'balias' => 'cedula'
				),
			),
			'tables' => array('personas'),

		);
		$query = new Query("SELECT People.cedula FROM People");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('people'),
			'columns' => array(
				'cedula' => array(
					'type' => 'scalar',
					'column' => 'personas.cedula',
					'balias' => 'cedula'
				),
			),
			'tables' => array('personas'),

		);
		$query = new Query("select people.cedula from people");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('People'),
			'columns' => array(
				'cedula' => array(
					'type' => 'scalar',
					'column' => 'p.cedula',
					'balias' => 'cedula'
				),
			),
			'tables' => array('personas p'),

		);
		$query = new Query("SELECT p.cedula AS cedula FROM People p");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('People'),
			'columns' => array(
				'nombre' => array(
					'type' => 'scalar',
					'column' => 'CONCAT(personas.cedula,\'-\',personas.nombre)',
					'balias' => 'nombre'
				),
			),
			'tables' => array('personas'),

		);
		$query = new Query("SELECT CONCAT(People.cedula,'-',People.nombre) AS nombre FROM People");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots',
				)
			),
			'tables' => array('robots'),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => 'robots_parts',
					'conditions' => array('robots.id=robots_parts.robots_id'),
				),
			),
		);
		$query = new Query("SELECT * FROM Robots JOIN RobotsParts");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				)
			),
			'tables' => array('robots'),
			'joins' => array(
				array(
					'type' => 'CROSS',
					'source' => 'robots_parts',
					'conditions' => array('robots.id=robots_parts.robots_id'),
				),
			),
		);
		$query = new Query("SELECT * FROM Robots CROSS JOIN RobotsParts");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts', 'Parts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				)
			),
			'tables' => array('robots'),
			'joins' => array(
				array(
					'type' => 'LEFT',
					'source' => 'robots_parts',
					'conditions' => array('robots.id=robots_parts.robots_id'),
				),
				array(
					'type' => 'RIGHT',
					'source' => 'parts',
					'conditions' => array(),
				),
			),
		);
		$query = new Query("SELECT * FROM Robots LEFT JOIN RobotsParts RIGHT JOIN Parts");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('RobotsParts', 'Robots', 'Parts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts'
				)
			),
			'tables' => array('robots_parts'),
			'joins' => array(
				array(
					'type' => 'LEFT',
					'source' => 'robots',
					'conditions' => array('robots_parts.robots_id=robots.id'),
				),
				array(
					'type' => 'RIGHT',
					'source' => 'parts',
					'conditions' => array('robots_parts.parts_id=parts.id'),
				),
			),
		);
		$query = new Query("SELECT * FROM RobotsParts LEFT OUTER JOIN Robots RIGHT OUTER JOIN Parts");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				)
			),
			'tables' => array('robots'),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => 'robots_parts',
					'conditions' => array('robots.id=robots_parts.robots_id'),
				),
			),
		);
		$query = new Query("SELECT * FROM Robots JOIN RobotsParts ON Robots.id = RobotsParts.robots_id");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				)
			),
			'tables' => array('robots'),
			'joins' => array(
				array(
					'type' => 'LEFT',
					'source' => 'robots_parts',
					'conditions' => array('robots.id=robots_parts.robots_id AND robots_parts.robots_id=robots.id'),
				),
			),
			'where' => 'robots.id IS NULL'
		);
		$query = new Query("SELECT * FROM Robots LEFT OUTER JOIN RobotsParts ON Robots.id = RobotsParts.robots_id AND RobotsParts.robots_id = Robots.id WHERE Robots.id IS NULL");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				)
			),
			'tables' => array('robots'),
			'joins' => array(
				array(
					'type' => 'RIGHT',
					'source' => 'robots_parts',
					'conditions' => array('robots.id=robots_parts.robots_id AND robots_parts.robots_id=robots.id'),
				),
			),
			'where' => 'robots_parts.robots_id IS NOT NULL'
		);
		$query = new Query("SELECT * FROM Robots RIGHT OUTER JOIN RobotsParts ON Robots.id = RobotsParts.robots_id AND RobotsParts.robots_id = Robots.id WHERE RobotsParts.robots_id IS NOT NULL");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				)
			),
			'tables' => array('robots'),
			'joins' => array(
				array(
					'type' => 'FULL OUTER',
					'source' => 'robots_parts',
					'conditions' => array('robots.id=robots_parts.robots_id'),
				),
			),
		);
		$query = new Query("SELECT * FROM Robots FULL OUTER JOIN RobotsParts");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('RobotsParts', 'Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts'
				)
			),
			'tables' => array('robots_parts'),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => 'robots',
					'conditions' => array('robots_parts.robots_id=robots.id'),
				),
			),
		);
		$query = new Query("SELECT * FROM RobotsParts JOIN Robots");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
				1 => array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'p'
				)
			),
			'tables' => array('robots r'),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => 'robots_parts p',
					'conditions' => array('r.id=p.robots_id'),
				),
			),
		);
		$query = new Query("SELECT r.*, p.* FROM Robots AS r JOIN RobotsParts AS p");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => 'robots_parts p',
					'conditions' => array('r.id=p.robots_id'),
				),
			),
		);
		$query = new Query("SELECT * FROM Robots AS r JOIN RobotsParts AS p");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => 'robots_parts',
					'conditions' => array('r.id=robots_parts.robots_id'),
				),
			),
		);
		$query = new Query("SELECT r.* FROM Robots r INNER JOIN RobotsParts");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('People', 'Products'),
			'columns' => array(
				'_0' => array(
					'type' => 'scalar',
					'column' => '(personas.cupo+100)/(products.price*0.15)'
				),
			),
			'tables' => array('personas'),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => 'products',
					'conditions' => array(),
				),
			),
		);
		$query = new Query("SELECT ( People.cupo + 100) / (Products.price * 0.15) FROM People JOIN Products");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('People', 'Some\Products'),
			'columns' => array(
				'price' => array(
					'type' => 'scalar',
					'column' => '(personas.cupo+100)/(le_products.price*0.15)',
					'balias' => 'price'
				),
			),
			'tables' => array('personas'),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => 'le_products',
					'conditions' => array(),
				),
			),
		);
		$query = new Query('SELECT ( People.cupo + 100) / (Some\Products.price * 0.15) AS price FROM People JOIN Some\Products');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('People', 'Some\Products'),
			'columns' => array(
				'price' => array(
					'type' => 'scalar',
					'column' => '(p.cupo+100)/(s.price*0.15)',
					'balias' => 'price'
				),
			),
			'tables' => array('personas p'),
			'joins' => array(
				array(
					'type' => 'INNER',
					'source' => 'le_products s',
					'conditions' => array(),
				),
			),
		);
		$query = new Query('SELECT (p.cupo + 100) / (s.price * 0.15) AS price FROM People AS p JOIN Some\Products AS s');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
				1 => array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts'
				),
			),
			'tables' => array('robots', 'robots_parts'),

		);
		$query = new Query("SELECT * FROM Robots, RobotsParts");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
				1 => array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'p'
				),
			),
			'tables' => array('robots r', 'robots_parts p'),

		);
		$query = new Query("SELECT * FROM Robots r, RobotsParts p");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
				1 => array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'p'
				),
			),
			'tables' => array('robots r', 'robots_parts p'),

		);
		$query = new Query("SELECT * FROM Robots AS r, RobotsParts AS p");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
				1 => array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'p'
				),
			),
			'tables' => array('robots r', 'robots_parts p'),
			'where' => 'r.id=p.robots_id'
		);
		$query = new Query("SELECT * FROM Robots AS r, RobotsParts AS p WHERE r.id = p.robots_id");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots', 'RobotsParts'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
				1 => array(
					'type' => 'object',
					'model' => 'RobotsParts',
					'column' => 'robots_parts'
				),
			),
			'tables' => array('robots', 'robots_parts'),
			'where' => 'robots.id=robots_parts.robots_id'
		);
		$query = new Query("SELECT * FROM Robots, RobotsParts WHERE Robots.id = RobotsParts.robots_id");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id=100'
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.id = 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id<>100'
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.id != 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id>100'
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.id > 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id<100'
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.id < 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id>=100'
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.id >= 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id<=100'
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.id <= 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.name LIKE \'as%\''
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.name LIKE 'as%'");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.name NOT LIKE \'as%\''
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.name NOT LIKE 'as%'");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Some\Products',
					'column' => 'le_products'
				),
			),
			'tables' => array('le_products'),
			'where' => 'DATE(le_products.created_at)=\'2010-10-02\''
		);
		$query = new Query('SELECT * FROM Some\Products WHERE DATE(Some\Products.created_at) = "2010-10-02"');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Some\Products',
					'column' => 'le_products'
				),
			),
			'tables' => array('le_products'),
			'where' => 'le_products.created_at<now()'
		);
		$query = new Query('SELECT * FROM Some\Products WHERE Some\Products.created_at < now()');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id IN (1,2,3,4)'
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.id IN (1, 2, 3, 4)");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'where' => 'r.id IN (r.id+1,r.id+2)'
		);
		$query = new Query("SELECT * FROM Robots r WHERE r.id IN (r.id+1, r.id+2)");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.name=:name'
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.name = :name:");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.name=:0'
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.name = ?0");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => "robots.name='R2D2' OR robots.name<>'C3PO'"
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.name = 'R2D2' OR Robots.name <> 'C3PO'");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => "robots.name='R2D2' AND robots.name<>'C3PO'"
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.name = 'R2D2' AND Robots.name <> 'C3PO'");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => "robots.name=:first_name AND robots.name<>:second_name"
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.name = :first_name: AND Robots.name <> :second_name:");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => "robots.name='R2D2' AND robots.name<>'C3PO' AND robots.id>100"
		);
		$query = new Query("SELECT * FROM Robots WHERE Robots.name = 'R2D2' AND Robots.name <> 'C3PO' AND Robots.id > 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => "(robots.name='R2D2' AND robots.name<>'C3PO') OR robots.id>100"
		);
		$query = new Query("SELECT * FROM Robots WHERE (Robots.name = 'R2D2' AND Robots.name <> 'C3PO') OR Robots.id > 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => "(robots.name='R2D2' AND robots.name<>'C3PO') OR (robots.id>100 AND robots.id<=150)"
		);
		$query = new Query("SELECT * FROM Robots WHERE (Robots.name = 'R2D2' AND Robots.name <> 'C3PO') OR (Robots.id > 100 AND Robots.id <= 150)");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'where' => 'r.id NOT IN (r.id+1,r.id+2)'
		);
		$query = new Query("SELECT * FROM Robots r WHERE r.id NOT IN (r.id+1, r.id+2)");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'limit' => array('number' => 100)
		);
		$query = new Query("SELECT * FROM Robots r LIMIT 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'limit' => array('number' => 100, 'offset' => 10)
		);
		$query = new Query("SELECT * FROM Robots r LIMIT 10,100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'limit' => array('number' => 100, 'offset' => 10)
		);
		$query = new Query("SELECT * FROM Robots r LIMIT 100 OFFSET 10");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Some\Products',
					'column' => 'p'
				),
			),
			'tables' => array('le_products p'),
			'where' => 'p.name=\'Artichoke\'',
			'limit' => array('number' => 100)
		);
		$query = new Query('SELECT * FROM Some\Products p WHERE p.name = "Artichoke" LIMIT 100');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Some\Products',
					'column' => 'p'
				),
			),
			'tables' => array('le_products p'),
			'order' => 'p.name'
		);
		$query = new Query('SELECT * FROM Some\Products p ORDER BY p.name');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Some\Products',
					'column' => 'le_products'
				),
			),
			'tables' => array('le_products'),
			'order' => 'le_products.name'
		);
		$query = new Query('SELECT * FROM Some\Products ORDER BY Some\Products.name');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Some\Products',
					'column' => 'le_products'
				),
			),
			'tables' => array('le_products'),
			'order' => 'id,le_products.name,3'
		);
		$query = new Query('SELECT * FROM Some\Products ORDER BY id, Some\Products.name, 3');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'where' => 'NOT (r.name=\'shaggy\')',
			'order' => '1,r.name'
		);
		$query = new Query('SELECT * FROM Robots r WHERE NOT (r.name = "shaggy") ORDER BY 1, r.name');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'where' => 'NOT (r.name=\'shaggy\')',
			'order' => '1,r.name'
		);
		$query = new Query('SELECT * FROM Robots r WHERE NOT (r.name = "shaggy") ORDER BY 1, r.name');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'where' => 'NOT (r.name=\'shaggy\')',
			'order' => '1 DESC,r.name'
		);
		$query = new Query('SELECT * FROM Robots r WHERE NOT (r.name = "shaggy") ORDER BY 1 DESC, r.name');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'where' => 'NOT (r.name=\'shaggy\')',
			'order' => '1,r.name'
		);
		$query = new Query('SELECT * FROM Robots r WHERE NOT (r.name = "shaggy") ORDER BY 1, r.name');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'where' => 'r.name<>\'shaggy\'',
			'order' => '1,2',
			'limit' => array('number' => 5)
		);
		$query = new Query('SELECT * FROM Robots r WHERE r.name <> "shaggy" ORDER BY 1, 2 LIMIT 5');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'r'
				),
			),
			'tables' => array('robots r'),
			'where' => 'r.name<>\'shaggy\'',
			'order' => '1 ASC,2 DESC',
			'limit' => array('number' => 5)
		);
		$query = new Query('SELECT * FROM Robots r WHERE r.name <> "shaggy" ORDER BY 1 ASC, 2 DESC LIMIT 5');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'group' => 'robots.name'
		);
		$query = new Query('SELECT * FROM Robots GROUP BY Robots.name');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'group' => 'robots.name,robots.id'
		);
		$query = new Query('SELECT * FROM Robots GROUP BY Robots.name, Robots.id');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'column' => 'robots.name',
					'balias' => 'name'
				),
				'summatory' => array(
					'type' => 'scalar',
					'column' => 'SUM(robots.price)',
					'balias' => 'summatory'
				),
			),
			'tables' => array('robots'),
			'group' => 'robots.name'
		);
		$query = new Query('SELECT Robots.name, SUM(Robots.price) AS summatory FROM Robots GROUP BY Robots.name');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'id' => array(
					'type' => 'scalar',
					'column' => 'r.id',
					'balias' => 'id'
				),
				'name' => array(
					'type' => 'scalar',
					'column' => 'r.name',
					'balias' => 'name'
				),
				'summatory' => array(
					'type' => 'scalar',
					'column' => 'SUM(r.price)',
					'balias' => 'summatory'
				),
				'_3' => array(
					'type' => 'scalar',
					'column' => 'MIN(r.price)'
				),
			),
			'tables' => array('robots r'),
			'group' => 'r.id,r.name'
		);
		$query = new Query('SELECT r.id, r.name, SUM(r.price) AS summatory, MIN(r.price) FROM Robots r GROUP BY r.id, r.name');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id>5',
			'group' => 'robots.name'
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id > 5 GROUP BY Robots.name');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id>5',
			'group' => 'robots.name',
			'limit' => array('number' => 10)
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id > 5 GROUP BY Robots.name LIMIT 10');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id>5',
			'group' => 'robots.name',
			'order' => 'robots.id',
			'limit' => array('number' => 10)
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id > 5 GROUP BY Robots.name ORDER BY Robots.id LIMIT 10');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'group' => 'robots.name',
			'order' => 'robots.id',
		);
		$query = new Query('SELECT * FROM Robots GROUP BY Robots.name ORDER BY Robots.id');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				0 => array(
					'type' => 'object',
					'model' => 'Robots',
					'column' => 'robots'
				),
			),
			'tables' => array('robots'),
			'where' => 'robots.id<>10',
			'group' => 'robots.name',
			'order' => 'robots.id',
		);
		$query = new Query('SELECT * FROM Robots WHERE Robots.id != 10 GROUP BY Robots.name ORDER BY Robots.id');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'column' => 'robots.name',
					'balias' => 'name'
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => 'COUNT(*)'
				)
			),
			'tables' => array('robots'),
			'having' => 'COUNT(*)>100',
			'group' => 'robots.name'
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots GROUP BY Robots.name HAVING COUNT(*)>100');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'columns' => array(
				'type' => array(
					'type' => 'scalar',
					'balias' => 'type',
					'column' => 'le_products.type'
				),
				'price' => array(
					'type' => 'scalar',
					'column' => 'SUM(le_products.price)',
					'balias' => 'price'
				)
			),
			'tables' => array('le_products'),
			'having' => 'SUM(le_products.price)<100',
			'group' => 'le_products.type'
		);
		$query = new Query('SELECT Some\Products.type, SUM(Some\Products.price) AS price FROM Some\Products GROUP BY Some\Products.type HAVING SUM(Some\Products.price)<100');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'column' => 'robots.name',
					'balias' => 'name'
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => 'COUNT(*)'
				)
			),
			'tables' => array('robots'),
			'where' => 'robots.type=\'virtual\'',
			'having' => 'COUNT(*)>100',
			'group' => 'robots.name'
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots WHERE Robots.type = "virtual" GROUP BY Robots.name HAVING COUNT(*)>100');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'column' => 'robots.name',
					'balias' => 'name'
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => 'COUNT(*)'
				)
			),
			'tables' => array('robots'),
			'where' => 'robots.type=\'virtual\'',
			'having' => 'COUNT(*)>100',
			'group' => 'robots.name',
			'order' => '2'
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots WHERE Robots.type = "virtual" GROUP BY Robots.name HAVING COUNT(*)>100 ORDER BY 2');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'column' => 'robots.name',
					'balias' => 'name'
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => 'COUNT(*)'
				)
			),
			'tables' => array('robots'),
			'where' => 'robots.type=\'virtual\'',
			'having' => 'COUNT(*)>100',
			'group' => 'robots.name',
			'order' => '2',
			'limit' => array('number' => 15)
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots WHERE Robots.type = "virtual" GROUP BY Robots.name HAVING COUNT(*)>100 ORDER BY 2 LIMIT 15');
		$query->setDI($di);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'column' => 'robots.name',
					'balias' => 'name'
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => 'COUNT(*)'
				)
			),
			'tables' => array('robots'),
			'having' => 'COUNT(*)>100',
			'group' => 'robots.name',
			'order' => '2',
			'limit' => array('number' => 15)
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots GROUP BY Robots.name HAVING COUNT(*)>100 ORDER BY 2 LIMIT 15');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'column' => 'robots.name',
					'balias' => 'name'
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => 'COUNT(*)'
				)
			),
			'tables' => array('robots'),
			'where' => 'robots.type=\'virtual\'',
			'having' => 'COUNT(*)>100',
			'group' => 'robots.name',
			'limit' => array('number' => 15)
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots WHERE Robots.type = "virtual" GROUP BY Robots.name HAVING COUNT(*)>100 LIMIT 15');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'columns' => array(
				'name' => array(
					'type' => 'scalar',
					'column' => 'robots.name',
					'balias' => 'name'
				),
				'_1' => array(
					'type' => 'scalar',
					'column' => 'COUNT(*)'
				)
			),
			'tables' => array('robots'),
			'having' => 'COUNT(*)>100',
			'group' => 'robots.name',
			'limit' => array('number' => 15)
		);
		$query = new Query('SELECT Robots.name, COUNT(*) FROM Robots GROUP BY Robots.name HAVING COUNT(*)>100 LIMIT 15');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

	}

	public function testInsertParsing()
	{

		$di = $this->_getDI();

		$manager = $di->getShared('modelsManager');

		$expected = array(
			'model' => 'Robots',
			'table' => 'robots',
			'values' => array(
				array("type" => 322, "value" => 'NULL'),
				array("type" => 260, "value" => "some robot"),
				array("type" => 258, "value" => "1945")
			)
		);
		$query = new Query("INSERT INTO Robots VALUES (NULL, 'some robot', 1945)");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'model' => 'robots',
			'table' => 'robots',
			'values' => array(
				array("type" => 322, "value" => 'NULL'),
				array("type" => 260, "value" => "some robot"),
				array("type" => 258, "value" => "1945")
			)
		);
		$query = new Query("insert into robots values (null, 'some robot', 1945)");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'model' => 'Some\Products',
			'table' => 'le_products',
			'values' => array(
				array("type" => 260, "value" => "Some name"),
				array("type" => 259, "value" => "100.15"),
				array("type" => 355, "value" => "current_date"),
				array("type" => 350, "value" => "now()")
			)
		);
		$query = new Query('INSERT INTO Some\Products VALUES ("Some name", 100.15, current_date, now())');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'model' => 'Robots',
			'table' => 'robots',
			'values' => array(
				array("type" => 356, "value" => '(1+1000*:le_id)'),
				array("type" => 350, "value" => "CONCAT('some','robot')"),
				array("type" => 258, "value" => "2011")
			)
		);
		$query = new Query("INSERT INTO Robots VALUES ((1+1000*:le_id:), CONCAT('some', 'robot'), 2011)");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'model' => 'Robots',
			'table' => 'robots',
			'fields' => array(
				'name', 'type', 'year', 'status'
			),
			'values' => array(
				array("type" => 260, "value" => "a name"),
				array("type" => 260, "value" => "virtual"),
				array("type" => 258, "value" => "2011"),
				array("type" => 273, "value" => ":0")
			)
		);
		$query = new Query("INSERT INTO Robots (name, type, year, status) VALUES ('a name', 'virtual', 2011, ?0)");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

	}

	public function testUpdateParsing()
	{

		$di = $this->_getDI();

		$manager = $di->getShared('modelsManager');

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots'),
			'fields' => array('name'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
			)
		);
		$query = new Query("UPDATE Robots SET name = 'some name'");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots'),
			'fields' => array('robots.name'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
			)
		);
		$query = new Query("UPDATE Robots SET Robots.name = 'some name'");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'tables' => array('le_products'),
			'fields' => array('le_products.name'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
			)
		);
		$query = new Query('UPDATE Some\Products SET Some\Products.name = "some name"');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'tables' => array('le_products p'),
			'fields' => array('p.name'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
			)
		);
		$query = new Query('UPDATE Some\Products p SET p.name = "some name"');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots'),
			'fields' => array('robots.name', 'robots.year'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
				array("type" => 258, "value" => "1990"),
			)
		);
		$query = new Query("UPDATE Robots SET Robots.name = 'some name', Robots.year = 1990");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Some\Products'),
			'tables' => array('le_products p'),
			'fields' => array('p.name', 'p.year'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
				array("type" => 258, "value" => "1990"),
			)
		);
		$query = new Query('UPDATE Some\Products p SET p.name = "some name", p.year = 1990');
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots'),
			'fields' => array('robots.name', 'robots.year'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
				array("type" => 43, "value" => "YEAR(current_date)+robots.year"),
			)
		);
		$query = new Query("UPDATE Robots SET Robots.name = 'some name', Robots.year = YEAR(current_date) + Robots.year");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'fields' => array('r.name', 'r.year'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
				array("type" => 43, "value" => "YEAR(current_date)+r.year"),
			)
		);
		$query = new Query("UPDATE Robots AS r SET r.name = 'some name', r.year = YEAR(current_date) + r.year");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'fields' => array('r.name'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
			),
			'where' => 'r.id>100'
		);
		$query = new Query("UPDATE Robots AS r SET r.name = 'some name' WHERE r.id > 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'fields' => array('r.name', 'r.year'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
				array("type" => 42, "value" => 'r.year*2'),
			),
			'where' => 'r.id>100 AND r.id<=200'
		);
		$query = new Query("update Robots as r set r.name = 'some name', r.year = r.year*2 where r.id > 100 and r.id <= 200");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'fields' => array('r.name'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
			),
			'limit' => 10
		);
		$query = new Query("UPDATE Robots AS r SET r.name = 'some name' LIMIT 10");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'fields' => array('r.name'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
			),
			'limit' => 10
		);
		$query = new Query("UPDATE Robots r SET r.name = 'some name' LIMIT 10");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'fields' => array('r.name'),
			'values' => array(
				array("type" => 260, "value" => "some name"),
			),
			'where' => 'r.id>100',
			'limit' => 10
		);
		$query = new Query("UPDATE Robots AS r SET r.name = 'some name' WHERE r.id > 100 LIMIT 10");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

	}

	public function testDeleteParsing()
	{

		$di = $this->_getDI();

		$manager = $di->getShared('modelsManager');

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots'),
		);
		$query = new Query("DELETE FROM Robots");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'where' => 'r.id>100'
		);
		$query = new Query("DELETE FROM Robots AS r WHERE r.id > 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'where' => 'r.id>100'
		);
		$query = new Query("DELETE FROM Robots r WHERE r.id > 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'where' => 'r.id>100'
		);
		$query = new Query("delete from Robots as r where r.id > 100");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'limit' => 10
		);
		$query = new Query("DELETE FROM Robots r LIMIT 10");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

		$expected = array(
			'models' => array('Robots'),
			'tables' => array('robots r'),
			'where' => 'r.id>100',
			'limit' => 10
		);
		$query = new Query("DELETE FROM Robots r WHERE r.id > 100 LIMIT 10");
		$query->setDI($di);
		$this->assertEquals($query->parse($manager), $expected);

	}

}