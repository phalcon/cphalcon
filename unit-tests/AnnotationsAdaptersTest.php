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

require 'annotations/TestClass.php';
require 'annotations/TestClassNs.php';

class AnnotationsAdaptersTest extends PHPUnit_Framework_TestCase
{

	public function testMemoryAdapter()
	{
		$adapter = new Phalcon\Annotations\Adapter\Memory();

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertTrue(get_class($classAnnotations), 'Phalcon\Annotations\Refactor');
		$this->assertTrue(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertTrue(get_class($classAnnotations), 'Phalcon\Annotations\Refactor');
		$this->assertTrue(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertTrue(get_class($classAnnotations), 'Phalcon\Annotations\Refactor');
		$this->assertTrue(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertTrue(get_class($classAnnotations), 'Phalcon\Annotations\Refactor');
		$this->assertTrue(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');
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
		$this->assertTrue(get_class($classAnnotations), 'Phalcon\Annotations\Refactor');
		$this->assertTrue(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('TestClass');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertTrue(get_class($classAnnotations), 'Phalcon\Annotations\Refactor');
		$this->assertTrue(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertTrue(get_class($classAnnotations), 'Phalcon\Annotations\Refactor');
		$this->assertTrue(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

		$classAnnotations = $adapter->get('User\TestClassNs');
		$this->assertTrue(is_object($classAnnotations));
		$this->assertTrue(get_class($classAnnotations), 'Phalcon\Annotations\Refactor');
		$this->assertTrue(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');
	}

}