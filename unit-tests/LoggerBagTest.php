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

class LoggerBagTest extends PHPUnit_Framework_TestCase
{
	public function testObjectArgument()
	{
		date_default_timezone_set('UTC');

		$logfile1 = 'unit-tests/logs/file-1.log';
		$logfile2 = 'unit-tests/logs/file-2.log';

		@unlink($logfile1);
		@unlink($logfile2);

		$logger = new \Phalcon\Logger\Bag(array(
			'file1' => new \Phalcon\Logger\Adapter\File($logfile1),
			'file2' => new \Phalcon\Logger\Adapter\File($logfile2),
		));

		$logger->log('This is a message');
		$logger->file1->log('This is an error', \Phalcon\Logger::ERROR);
		$logger->file2->error('This is another error');

		$loggerMessage1 = array('[DEBUG] This is a message', '[ERROR] This is an error');
		$loggerMessage2 = array('[ERROR] This is another error');

		$lines = file($logfile1);
		$this->assertEquals(count($lines), 2);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage1[$key]);
		}

		unset($lines);
		$lines = file($logfile2);
		$this->assertEquals(count($lines), 1);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage2[$key]);
		}
	}

	public function testArrayArgument()
	{
		date_default_timezone_set('UTC');

		$logfile1 = 'unit-tests/logs/file-1.log';
		$logfile2 = 'unit-tests/logs/file-2.log';

		@unlink($logfile1);
		@unlink($logfile2);

		$logger = new \Phalcon\Logger\Bag(array(
			'file1' => array(
				'adapter' => 'file',
				'name' => $logfile1,
			),
			'file2' => array(
				'adapter' => 'file',
				'name' => $logfile2,
			),
		));

		$logger->log('This is a message');
		$logger->file1->log('This is an error', \Phalcon\Logger::ERROR);
		$logger->file2->error('This is another error');

		$loggerMessage1 = array('[DEBUG] This is a message', '[ERROR] This is an error');
		$loggerMessage2 = array('[ERROR] This is another error');

		$lines = file($logfile1);
		$this->assertEquals(count($lines), 2);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage1[$key]);
		}

		unset($lines);
		$lines = file($logfile2);
		$this->assertEquals(count($lines), 1);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage2[$key]);
		}
	}

	public function testPush()
	{
		date_default_timezone_set('UTC');

		$logfile1 = 'unit-tests/logs/file-1.log';
		$logfile2 = 'unit-tests/logs/file-2.log';

		@unlink($logfile1);
		@unlink($logfile2);

		$logger = new \Phalcon\Logger\Bag();
		$logger->push('file1', new \Phalcon\Logger\Adapter\File($logfile1));
		$logger->push('file2', new \Phalcon\Logger\Adapter\File($logfile2));

		$logger->log('This is a message');
		$logger->file1->log('This is an error', \Phalcon\Logger::ERROR);
		$logger->file2->error('This is another error');

		$loggerMessage1 = array('[DEBUG] This is a message', '[ERROR] This is an error');
		$loggerMessage2 = array('[ERROR] This is another error');

		$lines = file($logfile1);
		$this->assertEquals(count($lines), 2);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage1[$key]);
		}

		unset($lines);
		$lines = file($logfile2);
		$this->assertEquals(count($lines), 1);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage2[$key]);
		}
	}

	public function testDefault()
	{
		date_default_timezone_set('UTC');

		$logfile1 = 'unit-tests/logs/file-1.log';
		$logfile2 = 'unit-tests/logs/file-2.log';

		@unlink($logfile1);
		@unlink($logfile2);

		$logger = new \Phalcon\Logger\Bag(array(
			'file1' => new \Phalcon\Logger\Adapter\File($logfile1),
			'file2' => new \Phalcon\Logger\Adapter\File($logfile2),
		));

		$logger->setDefault('file2');

		$logger->log('This is a message');
		$logger->file1->log('This is an error', \Phalcon\Logger::ERROR);
		$logger->file2->error('This is another error');

		$loggerMessage1 = array('[ERROR] This is an error');
		$loggerMessage2 = array('[DEBUG] This is a message', '[ERROR] This is another error');

		$lines = file($logfile1);
		$this->assertEquals(count($lines), 1);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage1[$key]);
		}

		unset($lines);
		$lines = file($logfile2);
		$this->assertEquals(count($lines), 2);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage2[$key]);
		}
	}

	public function testFormatter()
	{
		date_default_timezone_set('UTC');

		$logfile1 = 'unit-tests/logs/file-1.log';
		$logfile2 = 'unit-tests/logs/file-2.log';

		@unlink($logfile1);
		@unlink($logfile2);

		$logger = new \Phalcon\Logger\Bag(array(
			'file1' => array(
				'adapter' => 'file',
				'name' => $logfile1,
			),
			'file2' => array(
				'adapter' => 'file',
				'name' => $logfile2,
				'formatter' => new \Phalcon\Logger\Formatter\Json(),
			),
		));

		$logger->log('This is a message');
		$logger->file1->log('This is an error', \Phalcon\Logger::ERROR);
		$logger->file2->error('This is another error');
		$logger->file2->log('This is a message');

		$loggerMessage1 = array('[DEBUG] This is a message', '[ERROR] This is an error');
		$loggerType2 = array('ERROR', 'DEBUG');
		$loggerMessage2 = array('This is another error', 'This is a message');

		$lines = file($logfile1);
		$this->assertEquals(count($lines), 2);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage1[$key]);
		}

		unset($lines);
		$lines = file($logfile2);
		$this->assertEquals(count($lines), 2);
		foreach($lines as $key => $line) {
			$line = json_decode($line, true);
			$this->assertEquals($line['type'], $loggerType2[$key]);
			$this->assertEquals($line['message'], $loggerMessage2[$key]);
		}
	}

	public function testLevel()
	{
		date_default_timezone_set('UTC');

		$logfile1 = 'unit-tests/logs/file-1.log';
		$logfile2 = 'unit-tests/logs/file-2.log';

		@unlink($logfile1);
		@unlink($logfile2);

		$logger = new \Phalcon\Logger\Bag(array(
			'file1' => array(
				'adapter' => 'file',
				'name' => $logfile1,
			),
			'file2' => array(
				'adapter' => 'file',
				'name' => $logfile2,
				'level' => \Phalcon\Logger::ERROR,
			),
		));

		$logger->file1->debug('This is a message');
		$logger->file1->warning('This is an error');
		$logger->file1->error('This is another error');

		$logger->file2->debug('This is a message');
		$logger->file2->warning('This is an error');
		$logger->file2->error('This is another error');

		$loggerMessage1 = array('[DEBUG] This is a message', '[WARNING] This is an error', '[ERROR] This is another error');
		$loggerMessage2 = array('[ERROR] This is another error');

		$lines = file($logfile1);
		$this->assertEquals(count($lines), 3);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage1[$key]);
		}

		unset($lines);
		$lines = file($logfile2);
		$this->assertEquals(count($lines), 1);
		foreach($lines as $key => $line) {
			$line = trim(preg_replace('/^\[[^\]]+\]/', '', $line));
			$this->assertEquals($line, $loggerMessage2[$key]);
		}
	}

	public function testHas()
	{
		$logfile1 = 'unit-tests/logs/file-1.log';
		$logfile2 = 'unit-tests/logs/file-2.log';

		@unlink($logfile1);
		@unlink($logfile2);

		$logger = new \Phalcon\Logger\Bag(array(
			'file1' => array(
				'adapter' => 'file',
				'name' => $logfile1,
			),
			'file2' => array(
				'adapter' => 'file',
				'name' => $logfile2,
				'formatter' => new \Phalcon\Logger\Formatter\Json(),
			),
		));

		$this->assertTrue($logger->has('file1'));
		$this->assertTrue($logger->has('file2'));
		$this->assertFalse($logger->has('file3'));
	}
}
