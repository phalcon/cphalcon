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

class LoggerTest extends PHPUnit_Framework_TestCase
{

	public function testFileLogger1()
	{

		@unlink('unit-tests/logs/test.log');

		$logger = new Phalcon\Logger\Adapter\File('unit-tests/logs/test.log');

		$logger->log("Hello");

		$logger->close();

		$lines = file('unit-tests/logs/test.log');
		$this->assertEquals(count($lines), 1);

		$this->assertTrue(strpos($lines[0], '[DEBUG]')!==false);
		$this->assertTrue(strpos($lines[0], 'Hello')!==false);

	}

	public function testFileLogger2()
	{

		@unlink('unit-tests/logs/test.log');

		$logger = new Phalcon\Logger\Adapter\File('unit-tests/logs/test.log');

		$logger->log("Hello 1", Phalcon\Logger::NOTICE);
		$logger->log("Hello 2", Phalcon\Logger::ERROR);

		$logger->close();

		$lines = file('unit-tests/logs/test.log');
		$this->assertEquals(count($lines), 2);

		$this->assertTrue(strpos($lines[0], '[NOTICE]')!==false);
		$this->assertTrue(strpos($lines[0], 'Hello 1')!==false);

		$this->assertTrue(strpos($lines[1], '[ERROR]')!==false);
		$this->assertTrue(strpos($lines[1], 'Hello 2')!==false);

	}

	public function testFileLogger3()
	{

		@unlink('unit-tests/logs/test.log');

		$logger = new Phalcon\Logger\Adapter\File('unit-tests/logs/test.log');

		$logger->notice("Hello 1");
		$logger->error("Hello 2");

		$logger->close();

		$lines = file('unit-tests/logs/test.log');
		$this->assertEquals(count($lines), 2);

		$this->assertTrue(strpos($lines[0], '[NOTICE]')!==false);
		$this->assertTrue(strpos($lines[0], 'Hello 1')!==false);

		$this->assertTrue(strpos($lines[1], '[ERROR]')!==false);
		$this->assertTrue(strpos($lines[1], 'Hello 2')!==false);

	}

	public function testFileLogger4()
	{

		@unlink('unit-tests/logs/test.log');

		$logger = new Phalcon\Logger\Adapter\File('unit-tests/logs/test.log');

		$logger->setFormat('/%date%/%type%/ %message%');

		$logger->alert("Hello 1");

		$logger->close();

		$lines = file('unit-tests/logs/test.log');
		$this->assertEquals(count($lines), 1);

		$this->assertTrue(strpos($lines[0], '/ALERT/')!==false);
		$this->assertTrue(strpos($lines[0], 'Hello 1')!==false);

	}

	public function testFileLogger5()
	{

		@unlink('unit-tests/logs/test.log');

		$logger = new Phalcon\Logger\Adapter\File('unit-tests/logs/test.log');

		$logger->begin();

		$logger->debug("Hello 1");
		$logger->debug("Hello 2");
		$logger->debug("Hello 3");
		$logger->debug("Hello 4");
		$logger->debug("Hello 5");

		$logger->rollback();

		$logger->close();

		$lines = file('unit-tests/logs/test.log');
		$this->assertEquals(count($lines), 0);

	}

	public function testFileLogger6()
	{

		@unlink('unit-tests/logs/test.log');

		$logger = new Phalcon\Logger\Adapter\File('unit-tests/logs/test.log');

		$logger->begin();

		$logger->debug("Hello 1");
		$logger->debug("Hello 2");
		$logger->debug("Hello 3");
		$logger->debug("Hello 4");
		$logger->debug("Hello 5");

		$lines = file('unit-tests/logs/test.log');
		$this->assertEquals(count($lines), 0);

		$logger->commit();

		$logger->close();

		$lines = file('unit-tests/logs/test.log');
		$this->assertEquals(count($lines), 5);

	}

}