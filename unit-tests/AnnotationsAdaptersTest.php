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

require_once 'annotations/TestClass.php';
require_once 'annotations/TestClassNs.php';
require_once 'helpers/xcache.php';

class AnnotationsAdaptersTest extends PHPUnit_Framework_TestCase
{

	public function testMemoryAdapter()
	{
		$adapter = new Phalcon\Annotations\Adapter\Memory();

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$property = $adapter->getProperty('TestClass', 'testProp1');
		$this->assertTrue(is_object($property));
		$this->assertEquals(get_class($property), 'Phalcon\Annotations\Collection');
		$this->assertEquals($property->count(), 4);
	}

	public function testFilesAdapter()
	{
		@unlink('unit-tests/annotations/cache/TestClass.php');
		@unlink('unit-tests/annotations/cache/User_TestClassNs.php');

		$adapter = new Phalcon\Annotations\Adapter\Files(array(
			'annotationsDir' => 'unit-tests/annotations/cache/'
		));

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');
	}

	public function testApcAdapter()
	{
		if (!function_exists('apc_fetch')) {
			$this->markTestSkipped('apc not loaded');
			return;
		}

		$adapter = new Phalcon\Annotations\Adapter\Apc();

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$property = $adapter->getProperty('TestClass', 'testProp1');
		$this->assertTrue(is_object($property));
		$this->assertEquals(get_class($property), 'Phalcon\Annotations\Collection');
		$this->assertEquals($property->count(), 4);
	}


	public function testXcacheAdapter()
	{
		if (!function_exists('xcache_get')) {
			$this->markTestSkipped('xcache not loaded');
			return;
		}

		$adapter = new Phalcon\Annotations\Adapter\Xcache();

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
		$this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$property = $adapter->getProperty('TestClass', 'testProp1');
		$this->assertTrue(is_object($property));
		$this->assertEquals(get_class($property), 'Phalcon\Annotations\Collection');
		$this->assertEquals($property->count(), 4);
	}
}
