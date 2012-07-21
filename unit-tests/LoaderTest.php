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

class LoaderTest extends PHPUnit_Framework_TestCase {

	public function testNamespaces(){

		$loader = new Phalcon\Loader();

		$loader->registerNamespaces(array(
			"Example\Base" => "unit-tests/vendor/example/base/",
			"Example\Adapter" => "unit-tests/vendor/example/adapter/",
			"Example" => "unit-tests/vendor/example/"
		));

		$loader->register();

		$some = new \Example\Adapter\Some();
		$this->assertEquals(get_class($some), 'Example\Adapter\Some');

		$leSome = new Example\Adapter\LeSome();
		$this->assertEquals(get_class($leSome), 'Example\Adapter\LeSome');

		$leEngine = new \Example\Engines\LeEngine();
		$this->assertEquals(get_class($leEngine), 'Example\Engines\LeEngine');
	}

	public function testDirectories(){

		$loader = new Phalcon\Loader();

		$loader->registerDirs(array(
			"unit-tests/vendor/example/dialects/",
			"unit-tests/vendor/example/types/",
		));

		$loader->register();

		$dialect = new LeDialect();
		$this->assertEquals(get_class($dialect), 'LeDialect');

		$someType = new SomeType();
		$this->assertEquals(get_class($someType), 'SomeType');

	}

	public function testClasses(){

		$loader = new Phalcon\Loader();

		$loader->registerClasses(array(
			"MoiTest" => "unit-tests/vendor/example/test/MoiTest.php",
			"LeTest" => "unit-tests/vendor/example/test/LeTest.php",
		));

		$loader->register();

		$test = new MoiTest();
		$this->assertEquals(get_class($test), 'MoiTest');

		$leTest = new LeTest();
		$this->assertEquals(get_class($leTest), 'LeTest');

	}

}