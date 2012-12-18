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
  | If you did not receive a copy of the licnse and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

use Phalcon\Mvc\Model\Query\Builder as Builder;

class ModelsQueryBuilderTest extends PHPUnit_Framework_TestCase
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

	public function testAction()
	{

		$di = $this->_getDI();

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from(array('Robots', 'RobotsParts'))
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].*, [RobotsParts].* FROM [Robots], [RobotsParts]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->columns('*')
						->from('Robots')
						->getPhql();
		$this->assertEquals($phql, 'SELECT * FROM [Robots]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->columns(array('id', 'name'))
						->from('Robots')
						->getPhql();
		$this->assertEquals($phql, 'SELECT id, name FROM [Robots]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->columns('id')
						->from('Robots')
						->getPhql();
		$this->assertEquals($phql, 'SELECT id FROM [Robots]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->where('Robots.name = "Voltron"')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] WHERE Robots.name = "Voltron"');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->where(100)
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] WHERE [Robots].[id] = 100');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->groupBy('Robots.name')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] GROUP BY Robots.name');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->groupBy(array('Robots.name', 'Robots.id'))
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] GROUP BY Robots.name, Robots.id');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->columns(array('Robots.name', 'SUM(Robots.price)'))
						->from('Robots')
						->groupBy('Robots.name')
						->getPhql();
		$this->assertEquals($phql, 'SELECT Robots.name, SUM(Robots.price) FROM [Robots] GROUP BY Robots.name');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->columns(array('Robots.name', 'SUM(Robots.price)'))
						->from('Robots')
						->groupBy('Robots.name')
						->having('SUM(Robots.price) > 1000')
						->getPhql();
		$this->assertEquals($phql, 'SELECT Robots.name, SUM(Robots.price) FROM [Robots] GROUP BY Robots.name HAVING SUM(Robots.price) > 1000');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->join('RobotsParts')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] JOIN [RobotsParts]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->join('RobotsParts', null, 'p')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] JOIN [RobotsParts] AS [p]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->join('RobotsParts', 'Robots.id = RobotsParts.robots_id', 'p')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] JOIN [RobotsParts] ON Robots.id = RobotsParts.robots_id AS [p]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->join('RobotsParts', 'Robots.id = RobotsParts.robots_id', 'p')
						->join('Parts', 'Parts.id = RobotsParts.parts_id', 't')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] JOIN [RobotsParts] ON Robots.id = RobotsParts.robots_id AS [p] JOIN [Parts] ON Parts.id = RobotsParts.parts_id AS [t]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->addFrom('Robots', 'r')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [r].* FROM [Robots] AS [r]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->addFrom('Parts', 'p')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].*, [p].* FROM [Robots], [Parts] AS [p]');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from(array('r' => 'Robots'))
						->addFrom('Parts', 'p')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [r].*, [p].* FROM [Robots] AS [r], [Parts] AS [p]');


		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from(array('r' => 'Robots', 'p' => 'Parts'))
						->getPhql();
		$this->assertEquals($phql, 'SELECT [r].*, [p].* FROM [Robots] AS [r], [Parts] AS [p]');


		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->orderBy('Robots.name')
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] ORDER BY Robots.name');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->orderBy(array(1, 'Robots.name'))
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] ORDER BY 1, Robots.name');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->limit(10)
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] LIMIT 10');

		$builder = new Builder();
		$phql = $builder->setDi($di)
						->from('Robots')
						->limit(10, 5)
						->getPhql();
		$this->assertEquals($phql, 'SELECT [Robots].* FROM [Robots] LIMIT 10 OFFSET 5');

	}

}
