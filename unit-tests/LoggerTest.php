<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

  public function testIssues2798()
  {
    $logfile1 = "unit-tests/logs/file.log";
    $logfile2 = "unit-tests/logs/multiple.log";

    @unlink($logfile1);
    @unlink($logfile2);

    $logger = new \Phalcon\Logger\Multiple();
    $logger->push(new \Phalcon\Logger\Adapter\File($logfile1));
    $logger->push(new \Phalcon\Logger\Adapter\File($logfile2));
    $logger->setFormatter(new \Phalcon\Logger\Formatter\Json());
		$logger->log('This is a message');
		$logger->log("This is an error", \Phalcon\Logger::ERROR);
		$logger->error("This is another error");

    $loggerType = array('DEBUG', 'ERROR', 'ERROR');
    $loggerMessage = array('This is a message', 'This is an error', 'This is another error');

    $lines = file($logfile1);
    $this->assertEquals(count($lines), 3);
    foreach($lines as $key => $line) {
      $line = json_decode($line, true);
      $this->assertEquals($line['type'], $loggerType[$key]);
      $this->assertEquals($line['message'], $loggerMessage[$key]);
    }

    unset($lines);
    $lines = file($logfile2);
    $this->assertEquals(count($lines), 3);
    foreach($lines as $key => $line) {
      $line = json_decode($line, true);
      $this->assertEquals($line['type'], $loggerType[$key]);
      $this->assertEquals($line['message'], $loggerMessage[$key]);
    }
  }
}
