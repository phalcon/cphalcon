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

class SessionTest extends PHPUnit_Framework_TestCase
{

	protected $stack = array();

	protected function setUp()
	{

		$this->stack = array(
			'save_handler' => ini_get('session.save_handler'),
			'save_path' => ini_get('session.save_path'),
			'serialize_handler' => ini_get('session.serialize_handler'),
		);

	}

	protected function tearDown()
	{
		@session_write_close();

		foreach ($this->stack as $key => $val) {
			@ini_set($key, $val);
		}

	}

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

		// Issue 10238
		$session->set('some', 0);
		$this->assertEquals($session->get('some'), 0);
	}

	public function testSessionFilesWrite()
	{

		$session_path =  __DIR__ . '/cache';
		ini_set('session.save_handler', 'files');
		ini_set('session.save_path', $session_path);
		ini_set('session.serialize_handler', 'php');

		// Write
		$session = new Phalcon\Session\Adapter\Files();
		$session->start();
		@session_start();

		$session->set('some', 'write-value');

		$this->assertEquals($session->get('some'), 'write-value');
		$this->assertTrue($session->has('some'));

		$session_id = $session->getId();
		$this->assertNotEmpty($session_id);

		session_write_close();
		unset($session);

		// Check session file
		$session_file = $session_path . '/sess_' . $session_id;
		$this->assertTrue(is_file($session_file));
		$this->assertNotEmpty(@file_get_contents($session_file));

		// Read
		$session = new Phalcon\Session\Adapter\Files();
		$session->start();
		@session_start();

		$session->setId($session_id);

		$this->assertTrue($session->has('some'));
		$this->assertEquals($session->get('some'), 'write-value');

		$session->remove('some');
		$this->assertFalse($session->has('some'));

		@session_write_close();
		unset($session);

		// Check session file
		$this->assertTrue(is_file($session_file));
		$this->assertEmpty(@file_get_contents($session_file));
		@unlink($session_file);

	}

	public function testSessionFilesWriteMagicMethods()
	{

		$session_path =  __DIR__ . '/cache';
		ini_set('session.save_handler', 'files');
		ini_set('session.save_path', $session_path);
		ini_set('session.serialize_handler', 'php');

		// Write
		$session = new Phalcon\Session\Adapter\Files();
		$session->start();
		@session_start();

		$session->some = 'write-magic-value';

		$this->assertEquals($session->some, 'write-magic-value');
		$this->assertTrue(isset($session->some));

		$session_id = $session->getId();

		@session_write_close();
		unset($session);

		// Check session file
		$session_file = $session_path . '/sess_' . $session_id;
		$this->assertTrue(is_file($session_file));
		$this->assertNotEmpty(@file_get_contents($session_file));

		// Read
		$session = new Phalcon\Session\Adapter\Files();
		$session->start();
		@session_start();

		$session->setId($session_id);

		$this->assertTrue(isset($session->some));
		$this->assertEquals($session->some, 'write-magic-value');

		unset($session->some);
		$this->assertFalse(isset($session->some));

		@session_write_close();
		unset($session);

		// Check session file
		$this->assertTrue(is_file($session_file));
		$this->assertEmpty(@file_get_contents($session_file));
		@unlink($session_file);

	}

}
