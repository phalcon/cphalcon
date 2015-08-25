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

class ModelsSerializeTest extends PHPUnit_Framework_TestCase
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
		$className = str_replace('\\', '/', $className);
		if (file_exists('unit-tests/models/'.$className.'.php')) {
			require 'unit-tests/models/'.$className.'.php';
		}
	}

	protected function _getDI()
	{
		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function() {
			return new Phalcon\Mvc\Model\Manager();
		}, true);

		$di->set('modelsMetadata', function() {
			return new Phalcon\Mvc\Model\Metadata\Memory();
		}, true);

		$di->set('db', function() {
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

        return $di;

	}

	public function testSerialize()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$this->_getDI();

		$robot = Robots::findFirst();

		$serialized = serialize($robot);
		$robot = unserialize($serialized);

		$this->assertTrue($robot->save());

	}

    public function testJsonSerialize()
    {
        require 'unit-tests/config.db.php';
        if (empty($configMysql)) {
            $this->markTestSkipped('Test skipped');
            return;
        }

        $di = $this->_getDI();

        // Single model object json serialization
        $robot = Robots::findFirst();
        $json = json_encode($robot);
        $this->assertTrue(is_string($json));
        $this->assertTrue(strlen($json) > 10); // make sure result is not "{ }"
        $array = json_decode($json, true);
        $this->assertEquals($robot->toArray(), $array);

        // Result-set serialization
        $robots = Robots::find();
        $json = json_encode($robots);
        $this->assertTrue(is_string($json));
        $this->assertTrue(strlen($json) > 50); // make sure result is not "{ }"
        $array = json_decode($json, true);
        $this->assertEquals($robots->toArray(), $array);

        // Single row serialization
        $result = $di->get('modelsManager')->executeQuery('SELECT id FROM Robots LIMIT 1');
        $this->assertEquals(get_class($result), 'Phalcon\Mvc\Model\Resultset\Simple');
        foreach ($result as $row) {
            $this->assertEquals(get_class($row), 'Phalcon\Mvc\Model\Row');
            $this->assertEquals($row->id, $robot->id);
            $json = json_encode($row);
            $this->assertTrue(is_string($json));
            $this->assertTrue(strlen($json) > 5); // make sure result is not "{ }"
            $array = json_decode($json, true);
            $this->assertEquals($row->toArray(), $array);
        }

    }

}