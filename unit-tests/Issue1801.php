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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

/**
 * This test has to be in a separate file and cannot be combined with ModelsTest
 */
class Issue1801 extends PHPUnit_Framework_TestCase
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
		if (file_exists('unit-tests/models/'.$className.'.php')) {
			require 'unit-tests/models/'.$className.'.php';
		}
	}

	public function tearDown()
	{
		Phalcon\Mvc\Model::setup(array('columnRenaming' => true));
		parent::tearDown();
	}

	protected function _getDI($dbService)
	{
		Phalcon\DI::reset();

		$di = new Phalcon\DI\FactoryDefault();

		$di->set('db', $dbService, true);
		return $di;
	}

	public function test1801Mysql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI(function(){
			require 'unit-tests/config.db.php';
			$db = new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
			return $db;
		});

		$this->issue1801($di);
	}

	public function test1801Postgresql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configPostgresql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI(function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		});

		$this->issue1801($di);
	}

	public function test1801Sqlite()
	{
		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI(function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
		});

		$this->issue1801($di);
	}

	protected function issue1801($di)
	{
		Phalcon\Mvc\Model::setup(array('columnRenaming' => false));

		$robot = Robots::findFirst(1);
		$di->get('modelsMetadata')->reset();
		$robot = Robots::findFirst(1);
		$this->assertTrue(true);
	}
}
