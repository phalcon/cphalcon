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

class SessionTest extends PHPUnit_Framework_TestCase
{

	public function testSessionFiles()
	{
		$session = new Phalcon\Session\Adapter\Files();

		$this->assertFalse($session->start());
		$this->assertFalse($session->isStarted());

		@session_start();

		$session->set('some', 'value');

		$this->assertEquals($session->get('some'), 'value');
		$this->assertTrue($session->has('some'));
		$this->assertEquals($session->get('undefined', 'my-default'), 'my-default');
		
		// Automatically deleted after reading
		$this->assertEquals($session->get('some', NULL, TRUE), 'value');
		$this->assertFalse($session->has('some'));

		@session_destroy();
	}

	public function testSessionMemcache()
	{
		$session = new Phalcon\Session\Adapter\Memcache(array(
			'host' => '127.0.0.1',
			'port' => '11211',
			'prefix' => 'memcache'
		));

		$this->assertFalse($session->start());
		$this->assertFalse($session->isStarted());

		@session_start();

		$session->set('some', 'value');

		$this->assertEquals($session->get('some'), 'value');
		$this->assertTrue($session->has('some'));
		$this->assertEquals($session->get('undefined', 'my-default'), 'my-default');
		
		// Automatically deleted after reading
		$this->assertEquals($session->get('some', NULL, TRUE), 'value');
		$this->assertFalse($session->has('some'));

		@session_destroy();
	}

	public function testSessionLibmemcached()
	{
		$session = new Phalcon\Session\Adapter\Libmemcached(array(
			'servers' => array(
				array(
					'host' => '127.0.0.1',
					'port' => '11211'
				)
			),
			'prefix' => 'libmemcached'
		));

		$this->assertFalse($session->start());
		$this->assertFalse($session->isStarted());

		@session_start();

		$session->set('some', 'value');

		$this->assertEquals($session->get('some'), 'value');
		$this->assertTrue($session->has('some'));
		$this->assertEquals($session->get('undefined', 'my-default'), 'my-default');
		
		// Automatically deleted after reading
		$this->assertEquals($session->get('some', NULL, TRUE), 'value');
		$this->assertFalse($session->has('some'));

		@session_destroy();
	}

}
