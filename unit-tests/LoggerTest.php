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
  |          Ivan Zubok <chi_no@ukr.net>                                   |
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

	/**
	 * @runInSeparateProcess
     * @preserveGlobalState disabled
	 */
	public function testFirephp()
	{
		$this->markTestSkipped('need install xdebug');
		$logger = new \Phalcon\Logger\Adapter\Firephp();
		$logger->getFormatter()->setShowBacktrace(false);
		$logger->info('info');

		$headers = xdebug_get_headers();

		$this->assertContains('X-Wf-Protocol-1: http://meta.wildfirehq.org/Protocol/JsonStream/0.2', $headers);
		$this->assertContains('X-Wf-1-Plugin-1: http://meta.firephp.org/Wildfire/Plugin/FirePHP/Library-FirePHPCore/0.3', $headers);
		$this->assertContains('X-Wf-Structure-1: http://meta.firephp.org/Wildfire/Structure/FirePHP/FirebugConsole/0.1', $headers);
		$this->assertContains('X-Wf-1-1-1-1: 35|[{"Type":"INFO","Label":"info"},""]|', $headers);
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
