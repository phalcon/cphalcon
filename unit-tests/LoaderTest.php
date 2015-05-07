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

class LoaderTest extends PHPUnit_Framework_TestCase
{

	public function testNamespaces()
	{

		$loader = new Phalcon\Loader();

		$loader->registerNamespaces(array(
			"Example\\Base" => "unit-tests/vendor/example/base/",
		));

		$loader->registerNamespaces(array(
			"Example\\Adapter" => "unit-tests/vendor/example/adapter/",
			"Example" => "unit-tests/vendor/example/"
		), true);

		$loader->register();

		$some = new \Example\Adapter\Some();
		$this->assertEquals(get_class($some), 'Example\Adapter\Some');

		$leSome = new \Example\Adapter\LeSome();
		$this->assertEquals(get_class($leSome), 'Example\Adapter\LeSome');

		$leEngine = new \Example\Engines\LeEngine();
		$this->assertEquals(get_class($leEngine), 'Example\Engines\LeEngine');

		$example = new \Example\Example\Example();
		$this->assertEquals(get_class($example), 'Example\Example\Example');

		$loader->unregister();
	}

	public function testNamespacesExtensions()
	{

		$loader = new Phalcon\Loader();

		$loader->setExtensions(array('inc', 'php'));

		$loader->registerNamespaces(array(
			"Example\\Base" => "unit-tests/vendor/example/base/",
			"Example\\Adapter" => "unit-tests/vendor/example/adapter/",
		));

		$loader->registerNamespaces(array(
			"Example" => "unit-tests/vendor/example/"
		), true);

		$loader->register();

		$leEngine = new \Example\Engines\LeOtherEngine();
		$this->assertEquals(get_class($leEngine), 'Example\Engines\LeOtherEngine');
		$this->assertTrue($leEngine->some());

		$loader->unregister();
	}

	public function testDirectories()
	{

		$loader = new Phalcon\Loader();

		$loader->registerDirs(array(
			"unit-tests/vendor/example/dialects", //missing trailing slash
		));

		$loader->registerDirs(array(
			"unit-tests/vendor/example/types",
			"unit-tests/vendor",
		), true);

		$loader->register();

		$dialect = new LeDialect();
		$this->assertEquals(get_class($dialect), 'LeDialect');

		$someType = new SomeType();
		$this->assertEquals(get_class($someType), 'SomeType');

		$some = new \example\adapter\SomeCool();
		$this->assertEquals(get_class($some), 'Example\Adapter\SomeCool');

		$leSome = new \example\adapter\LeCoolSome();
		$this->assertEquals(get_class($leSome), 'Example\Adapter\LeCoolSome');

		$loader->unregister();
	}

	public function testDirectoriesExtensions()
	{

		$loader = new Phalcon\Loader();

		$loader->setExtensions(array('inc', 'php'));

		$loader->registerDirs(array(
			"unit-tests/vendor/example/dialects/",
			"unit-tests/vendor/example/types/",
			"unit-tests/vendor/",
		));

		$loader->register();

		$leSome = new \example\adapter\LeAnotherSome();
		$this->assertEquals(get_class($leSome), 'Example\Adapter\LeAnotherSome');

		$loader->unregister();
	}

	public function testClasses()
	{

		$loader = new Phalcon\Loader();

		$loader->registerClasses(array(
			"MoiTest" => "unit-tests/vendor/example/test/MoiTest.php",
		));

		$loader->registerClasses(array(
			"LeTest" => "unit-tests/vendor/example/test/LeTest.php",
		), true);

		$loader->register();

		$test = new MoiTest();
		$this->assertEquals(get_class($test), 'MoiTest');

		$leTest = new LeTest();
		$this->assertEquals(get_class($leTest), 'LeTest');

		$loader->unregister();
	}

	public function testPrefixes()
	{

		$loader = new Phalcon\Loader();

		$loader->registerPrefixes(array(
			"Pseudo" => "unit-tests/vendor/example/Pseudo/",
		));

		$loader->registerPrefixes(array(
			"SecondPseudo" => "unit-tests/vendor/example/SecondPseudo/",
		), true);

		$loader->register();

		$pseudoClass = new Pseudo_Some_Something();
		$this->assertEquals(get_class($pseudoClass), 'Pseudo_Some_Something');

		$pseudoClass = new Pseudo_Base();
		$this->assertEquals(get_class($pseudoClass), 'Pseudo_Base');

		$pseudoClass = new SecondPseudo_Some_Something();
		$this->assertEquals(get_class($pseudoClass), 'SecondPseudo_Some_Something');

		$pseudoClass = new SecondPseudo_Base();
		$this->assertEquals(get_class($pseudoClass), 'SecondPseudo_Base');

		$loader->unregister();
	}

	public function testPrefixesUnderscore()
	{

		$loader = new Phalcon\Loader();

		$loader->registerPrefixes(array(
			"Pseudo_" => "unit-tests/vendor/example/Pseudo/",
		));

		$loader->register();

		$pseudoClass = new Pseudo_Some_Something();
		$this->assertEquals(get_class($pseudoClass), 'Pseudo_Some_Something');

		$pseudoClass = new Pseudo_Base();
		$this->assertEquals(get_class($pseudoClass), 'Pseudo_Base');

		$loader->unregister();
	}

	public function testEvents()
	{

		$loader = new Phalcon\Loader();

		$loader->registerDirs(array(
			"unit-tests/vendor/example/other/"
		));

		$loader->registerClasses(array(
			"AvecTest" => "unit-tests/vendor/example/other/Avec/"
		));

		$loader->registerNamespaces(array(
			"Avec\Test" => "unit-tests/vendor/example/other/Avec/"
		));

		$loader->registerPrefixes(array(
			"Avec_" => "unit-tests/vendor/example/other/Avec/"
		));

		$loader->register();

		$eventsManager = new Phalcon\Events\Manager();

		$trace = array();

		$eventsManager->attach('loader', function($event, $loader) use (&$trace) {
			if(!isset($trace[$event->getType()])){
				$trace[$event->getType()] = array();
			}
			$trace[$event->getType()][] = $loader->getCheckedPath();
		});

		$loader->setEventsManager($eventsManager);

		$loader->register();

		$test = new VousTest();
		$this->assertEquals(get_class($test), 'VousTest');

		$this->assertEquals($trace, array(
			'beforeCheckClass' => array(
				0 => NULL,
			),
			'beforeCheckPath' => array(
				0 => 'unit-tests/vendor/example/other/VousTest.php',
			),
			'pathFound' => array(
				0 => 'unit-tests/vendor/example/other/VousTest.php',
			),
		));

		$loader->unregister();

	}

}
