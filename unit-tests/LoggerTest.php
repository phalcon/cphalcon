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
	public function testFileAdapter()
	{
		date_default_timezone_set('UTC');

		$logfile = "unit-tests/logs/file.log";

		@unlink($logfile);

		$logger = new \Phalcon\Logger\Adapter\File($logfile);
		$logger->log('This is a message');
		$logger->log("This is an error", \Phalcon\Logger::ERROR);
		$logger->error("This is another error");

		$lines = file($logfile);
		$this->assertEquals(count($lines), 3);
	}

	public function testIssues2262()
	{
		$logfile = "unit-tests/logs/file.log";

		@unlink($logfile);

		$logger = new \Phalcon\Logger\Adapter\File($logfile);
		$logger->setFormatter(new \Phalcon\Logger\Formatter\Json());
		$logger->log('This is a message');
		$logger->log("This is an error", \Phalcon\Logger::ERROR);
		$logger->error("This is another error");

		$lines = file($logfile);
		$this->assertEquals(count($lines), 3);
	}
}
