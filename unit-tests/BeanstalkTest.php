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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

class BeanstalkTest extends PHPUnit_Framework_TestCase
{
	public function testBasic()
	{
		$queue = new Phalcon\Queue\Beanstalk();
		try {
			@$queue->connect();
		}
		catch (Exception $e) {
			$this->markTestSkipped($e->getMessage());
			return;
		}

		$expected = array('processVideo' => 4871);

		$queue->put($expected);
		while (($job = $queue->peekReady()) !== false) {
			$actual = $job->getBody();
			$job->delete();
			$this->assertEquals($expected, $actual);
		}
	}

	public function testReleaseKickBury()
	{
		$queue = new Phalcon\Queue\Beanstalk();
		try {
			@$queue->connect();
		}
		catch (Exception $e) {
			$this->markTestSkipped($e->getMessage());
			return;
		}

		$this->assertTrue($queue->choose('beanstalk-test') !== false);

		$task = 'doSomething';

		$this->assertTrue($queue->put($task) !== false);

		$this->assertTrue($queue->watch('beanstalk-test') !== false);

		$job = $queue->reserve(0);

		$this->assertTrue($job !== false);
		$this->assertEquals($task, $job->getBody());

		$this->assertTrue($job->touch());

		// Release the job; it moves to the ready queue
		$this->assertTrue($job->release());
		$job = $queue->reserve(0);

		$this->assertTrue($job !== false);
		$this->assertEquals($task, $job->getBody());

		// Bury the job
		$this->assertTrue($job->bury());
		$job = $queue->peekBuried();

		$this->assertTrue($job !== false);
		$this->assertEquals($task, $job->getBody());

		// Kick the job, it should move to the ready queue again
		// kick-job is supported since 1.8
		if (false !== $job->kick()) {
			$job = $queue->peekReady();

			$this->assertTrue($job !== false);
			$this->assertEquals($task, $job->getBody());
		}

		$this->assertTrue($job->delete());
	}

	public function testStats()
	{
		$queue = new Phalcon\Queue\Beanstalk();
		try {
			@$queue->connect();
		}
		catch (Exception $e) {
			$this->markTestSkipped($e->getMessage());
			return;
		}

		$this->assertTrue($queue->choose('beanstalk-test') !== false);

		$queueStats = $queue->stats();
		$this->assertTrue(is_array($queueStats));

		$tubeStats = $queue->statsTube('beanstalk-test');
		$this->assertTrue(is_array($tubeStats));
		$this->assertTrue($jobStats['name'] === 'beanstalk-test');

		$this->assertTrue($queue->statsTube('beanstalk-test-does-not-exist') === false);

		$this->assertTrue($queue->choose('beanstalk-test') !== false);

		$queue->put('doSomething');

		$queue->watch('beanstalk-test');

		$job = $queue->peekReady();
		$jobStats = $job->stats();

		$this->assertTrue(is_array($jobStats));
		$this->assertTrue($jobStats['tube'] === 'beanstalk-test');
	}
}
