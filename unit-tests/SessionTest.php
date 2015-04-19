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
	|          Stanislav Kiryukhin <korsar.zn@gmail.com>                     |
	+------------------------------------------------------------------------+
*/

use Phalcon\Session\Adapter as SessionAdapter;
use Phalcon\Session\AdapterInterface as SessionAdapterInterface;

/**
 * Class SessionTest
 */
class SessionTest extends PHPUnit_Framework_TestCase
{
	protected $stack = array();

	/**
	 * @var SessionAdapterInterface
	 */
	protected $session;

	public static function setUpBeforeClass()
	{
		@session_unset();
		@session_destroy();
		@session_write_close();

		session_save_path(__DIR__ . '/cache');
	}

	public function setUp()
	{
		$this->stack = array(
			'save_handler' => ini_get('session.save_handler'),
			'save_path' => ini_get('session.save_path'),
			'serialize_handler' => ini_get('session.serialize_handler')
		);

		$this->session = $this->createAdapter();
	}

	public function tearDown()
	{
		@$this->sessionStart();
		@$this->session->clear();
		@$this->session->destroy();
		$this->session = null;

		foreach ($this->stack as $key => $val) {
			@ini_set($key, $val);
		}
	}

	/**
	 * Test method getOptions, getOption
	 * @throws Exception
	 */
	public function testSessionGetOptions()
	{
		$options = array(
			'option1' => 'test-value-1',
			'option2' => 'test-value-2'
		);

		$session = $this->createAdapter($options);

		$this->assertEquals($session->getOptions(), $options);

		$this->assertEquals($session->getOption('option1'), 'test-value-1');
		$this->assertEquals($session->getOption('option2'), 'test-value-2');

		// Test getOption default value
		$this->assertEquals($session->getOption('option3'), null);
		$this->assertEquals($session->getOption('option4', 'test-value-4'), 'test-value-4');
	}


	/**
	 * Test method setOptions
	 * @throws Exception
	 */
	public function testSessionSetOptions()
	{
		$options = array(
			'option-1' => 'test-value-1',
			'option-2' => 'test-value-2'
		);

		$session = $this->createAdapter();
		$session->setOptions($options);

		$this->assertEquals($session->getOptions(), $options);

		$this->assertEquals($session->getOption('option-1'), 'test-value-1');
		$this->assertEquals($session->getOption('option-2'), 'test-value-2');

		// Test getOption default value
		$this->assertEquals($session->getOption('option-3'), null);
		$this->assertEquals($session->getOption('option-4', 'test-value-4'), 'test-value-4');
	}

	/**
	 * Test gets\sets session id
	 * @throws Exception
	 */
	public function testSessionSetId()
	{
		$this->sessionStart();

		$session_id = $this->session->getId();
		$this->assertNotEmpty($session_id);

		$this->session->setId($session_id_new = md5($session_id));
		$this->assertEquals($this->session->getId(), $session_id_new);
	}

	/**
	 * Test gets\sets session name
	 * @throws Exception
	 */
	public function testSessionSetName()
	{
		$this->sessionStart();

		$session_name = $this->session->getName();
		$this->assertNotEmpty($session_name);

		$this->assertEquals($this->session->setName('some-name'), $session_name);
		$this->assertEquals($this->session->getName(), 'some-name');
	}

	/**
	 * Test adapter Phalcon\Session\Adapter\File, option savePath
	 * @throws Exception
	 */
	public function testSessionAdapterFilesOptionSavePath()
	{
		$session_path_old = session_save_path();

		$session_path = __DIR__ . '/cache/session';

		if (!is_dir($session_path)) {
			@mkdir($session_path, 0777, true);
		}

		$session = $this->createAdapter(array(
			'savePath' => $session_path
		));

		$this->sessionStart();
		$session->set('some', 'write-value');

		$session_id = $session->getId();

		$session->commit();
		unset($session);

		// Check session file
		$session_file = $session_path . '/sess_' . $session_id;
		$this->assertTrue(is_file($session_file));
		$this->assertNotEmpty(@file_get_contents($session_file));

		@unlink($session_file);
		@rmdir($session_path);

		session_save_path($session_path_old);
	}

	/**
	 * Test session start, start force and status
	 *
	 * @throws Exception
	 */
	public function testSessionStart()
	{
		$this->assertEquals($this->session->status(), SessionAdapter::SESSION_NONE);

		// Test not force start
		$this->assertFalse($this->session->start());
		$this->assertFalse($this->session->isStarted());
		$this->assertEquals($this->session->status(), SessionAdapter::SESSION_NONE);

		// Test force start
		$this->assertFalse($this->session->start());
		$this->assertFalse($this->session->isStarted());

		@session_start();

		$this->assertTrue($this->session->isStarted());
		$this->assertEquals($this->session->status(), SessionAdapter::SESSION_ACTIVE);
	}


	/**
	 * Test session, getters, setters, has, remove
	 * @throws Exception
	 */
	public function testSessionMethodsManipulate()
	{
		$this->sessionStart();

		$this->session->set('some', 'write-value');

		// Test gets and sets method
		$this->assertEquals($this->session->get('some'), 'write-value');
		$this->assertTrue($this->session->has('some'));

		// Test gets default value
		$this->assertEquals($this->session->get('undefined-key', 'default-value'), 'default-value');

		// Automatically deleted after reading
		$this->assertEquals($this->session->get('some', null, true), 'write-value');
		$this->assertFalse($this->session->has('some'));

		// Test remove key
		$this->session->set('some2', 'write-value');
		$this->session->remove('some2');
		$this->assertFalse($this->session->has('some'));

		// Issue 10238
		$this->session->set('some', 0);
		$this->assertEquals($this->session->get('some'), 0);
	}

	/**
	 * Test session magic methods
	 * @throws Exception
	 */
	public function testSessionMagicMethodsManipulate()
	{
		$this->sessionStart();

		$this->session->some = 'write-magic-value';

		$this->assertEquals($this->session->some, 'write-magic-value');
		$this->assertTrue(isset($this->session->some));

		$this->session->some2 = 'write-magic-value';
		unset($this->session->some2);
		$this->assertFalse(isset($this->session->some2));
	}


	/**
	 * Test session regenerate id
	 * @throws Exception
	 */
	public function testSessionRegenerateId()
	{
		$this->sessionStart();

		$this->session->set('some-key-1', 'some-value-1');
		$this->assertTrue($this->session->has('some-key-1'));

		$this->assertNotEmpty($session_id = $this->session->getId());

		$newId = @$this->session->regenerateId();
		$this->assertNotEquals($newId, $session_id);

		$this->assertTrue($this->session->isStarted());
		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertEquals($this->session->get('some-key-1'), 'some-value-1');
	}

	/**
	 * Test session commit
	 * @throws Exception
	 */
	public function testSessionCommit()
	{
		$this->sessionStart();

		$this->session->set('some-key-1', 'some-value-1');
		$this->session->set('some-key-2', 'some-value-2');
		$this->session->commit();

		$this->assertFalse($this->session->isStarted());

		if (method_exists($this->session, 'read')) {
			$this->assertNotEmpty($data = $this->session->read($this->session->getId()));
		}

		// The value of the session should not be updated after the start
		$this->session->set('some-key-3', 'some-value-3');

		$this->sessionStart();
		$this->assertFalse($this->session->has('some-key-3'));
	}

	/**
	 * Test session reset
	 * @throws Exception
	 */
	public function testSessionReset()
	{
		$this->sessionStart();

		/**
		 * Test, reset to empty data
		 */
		$this->session->set('some-key-1', 'some-value-1');

		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertEquals($this->session->get('some-key-1'), 'some-value-1');

		$this->session->reset();

		$this->assertTrue($this->session->isStarted());
		$this->assertFalse($this->session->has('some-key-1'));


		/**
		 * Test, reset to previous data
		 */
		$this->session->set('some-key-1', 'some-value-1');
		$this->session->set('some-key-2', 'some-value-2');
		$this->session->commit();

		$this->assertFalse($this->session->isStarted());

		$this->sessionStart();

		// test key1
		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertEquals($this->session->get('some-key-1'), 'some-value-1');

		// test key2
		$this->session->set('some-key-2', 'some-value-22');
		$this->assertTrue($this->session->has('some-key-2'));
		$this->assertEquals($this->session->get('some-key-2'), 'some-value-22');

		// test key3
		$this->session->set('some-key-3', 'some-value-3');
		$this->assertTrue($this->session->has('some-key-3'));
		$this->assertEquals($this->session->get('some-key-3'), 'some-value-3');

		// Reset
		$this->session->reset();

		$this->assertTrue($this->session->isStarted());

		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertTrue($this->session->has('some-key-2'));
		$this->assertFalse($this->session->has('some-key-3'));

		$this->assertEquals($this->session->get('some-key-1'), 'some-value-1');
		$this->assertEquals($this->session->get('some-key-2'), 'some-value-2');
	}

	public function testSessionAbort()
	{
		$this->sessionStart();

		$this->session->set('some-key-1', 'some-value-1');
		$this->session->set('some-key-2', 'some-value-2');

		// test key1
		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertEquals($this->session->get('some-key-1'), 'some-value-1');

		// test key2
		$this->assertTrue($this->session->has('some-key-2'));
		$this->assertEquals($this->session->get('some-key-2'), 'some-value-2');

		$this->session->commit();
		$this->assertFalse($this->session->isStarted());

		// Session start
		$this->sessionStart();

		// Change session data
		$this->session->set('some-key-2', 'some-value-22');
		$this->assertTrue($this->session->has('some-key-2'));
		$this->assertEquals($this->session->get('some-key-2'), 'some-value-22');

		$this->session->set('some-key-3', 'some-value-3');
		$this->assertTrue($this->session->has('some-key-3'));
		$this->assertEquals($this->session->get('some-key-3'), 'some-value-3');

		/**
		 * Test abort session
		 */
		$this->session->abort();
		$this->assertFalse($this->session->isStarted());

		$this->sessionStart();

		// test key1
		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertEquals($this->session->get('some-key-1'), 'some-value-1');

		// test key2
		$this->assertTrue($this->session->has('some-key-2'));
		$this->assertEquals($this->session->get('some-key-2'), 'some-value-2');

		$this->assertFalse($this->session->has('some-key-3'));
	}


	/**
	 * Test session clear
	 * @throws Exception
	 */
	public function testSessionClear()
	{
		$this->sessionStart();

		$session_id = $this->session->getId();

		$this->session->set('some-key-1', 'some-value-1');
		$this->session->set('some-key-2', 'some-value-2');

		// test key1
		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertEquals($this->session->get('some-key-1'), 'some-value-1');

		// test key2
		$this->assertTrue($this->session->has('some-key-2'));
		$this->assertEquals($this->session->get('some-key-2'), 'some-value-2');

		/**
		 * Test session clear
		 */
		$this->session->clear();

		$this->assertTrue($this->session->isStarted());
		$this->assertEquals($this->session->getId(), $session_id);

		$this->assertFalse($this->session->has('some-key-1'));
		$this->assertFalse($this->session->has('some-key-2'));
	}

	/**
	 * Test session clear
	 * @throws Exception
	 */
	public function testSessionDestroy()
	{
		$this->sessionStart();

		$this->session->set('some-key-1', 'some-value-1');
		$this->session->set('some-key-2', 'some-value-2');

		// test key1
		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertEquals($this->session->get('some-key-1'), 'some-value-1');

		// test key2
		$this->assertTrue($this->session->has('some-key-2'));
		$this->assertEquals($this->session->get('some-key-2'), 'some-value-2');

		/**
		 * Test session clear
		 */
		$this->assertTrue($this->session->destroy());

		$this->assertFalse($this->session->isStarted());
		$this->assertEquals($this->session->getId(), '');


		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertTrue($this->session->has('some-key-2'));

		$this->sessionStart();

		$this->assertFalse($this->session->has('some-key-1'));
		$this->assertFalse($this->session->has('some-key-2'));
	}

	/**
	 * Test session clear
	 * @throws Exception
	 */
	public function testSessionEncodeDecode()
	{
		$this->sessionStart();

		$this->session->set('some-key-1', 'some-value-1');
		$this->session->set('some-key-2', 'some-value-2');

		// test key1
		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertEquals($this->session->get('some-key-1'), 'some-value-1');

		// test key2
		$this->assertTrue($this->session->has('some-key-2'));
		$this->assertEquals($this->session->get('some-key-2'), 'some-value-2');

		/**
		 * Test session encode
		 */
		$this->assertNotEmpty($session_data = $this->session->encode());

		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertTrue($this->session->has('some-key-2'));

		// test key3
		$this->session->set('some-key-3', 'some-value-3');
		$this->assertTrue($this->session->has('some-key-3'));
		$this->assertEquals($this->session->get('some-key-3'), 'some-value-3');

		// clear current session
		$this->session->clear();

		$this->assertFalse($this->session->has('some-key-1'));
		$this->assertFalse($this->session->has('some-key-2'));
		$this->assertFalse($this->session->has('some-key-3'));

		/**
		 * Test session decode
		 */
		$this->assertTrue($this->session->decode($session_data));

		// test key1
		$this->assertTrue($this->session->has('some-key-1'));
		$this->assertEquals($this->session->get('some-key-1'), 'some-value-1');

		// test key2
		$this->assertTrue($this->session->has('some-key-2'));
		$this->assertEquals($this->session->get('some-key-2'), 'some-value-2');

		// test key3
		$this->assertFalse($this->session->has('some-key-3'));
	}

	protected function sessionStart()
	{
		if (!$this->session->start()) {
			@session_start();
		}

		$this->assertTrue($this->session->isStarted());
	}

	/**
	 * @param array $options
	 * @return SessionAdapter\Files
	 */
	protected function createAdapter(Array $options = null)
	{
		return new Phalcon\Session\Adapter\Files($options);
	}
}