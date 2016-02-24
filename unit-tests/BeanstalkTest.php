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
  |          Dmitry Korolev <chameleonweb2012@gmail.com>                   |
  +------------------------------------------------------------------------+
 */

use Phalcon\Queue\Beanstalk\Job;
use Phalcon\Queue\Beanstalk;
use Phalcon\Queue\Beanstalk\Exception;

class BeanstalkTest extends PHPUnit_Framework_TestCase
{
    
    const TUBE_NAME_1 = 'test-tube-1';
    const TUBE_NAME_2 = 'test-tube-2';
    const JOB_CLASS = 'Phalcon\Queue\Beanstalk\Job';
    
    protected $fakeData = [
        "big_tube_name_over_200" => "tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_tube_name_"
    ];


    /**
     * @var \Phalcon\Queue\Beanstalk
     */
    protected $client = null;

    public function setUp()
    {
        $this->client = new Phalcon\Queue\Beanstalk();

        try {
            $connect = $this->client->connect();
        } catch (Exception $e) {
            $this->markTestSkipped($e->getMessage());
            return;
        }        
    }
    
    /**
     * use command
     * 
     */
    public function testShouldChoose()
    {
        $tube = $this->client->choose(self::TUBE_NAME_1);
        
        $this->assertNotEquals(false, $tube);
        $this->assertEquals($tube, self::TUBE_NAME_1);
    }
    
    public function testShouldChooseException()
    {
        try {
            $tube = $this->client->choose($this->fakeData['big_tube_name_over_200']);
        } catch (Exception $e) {
            $this->assertEquals(Phalcon\Queue\Beanstalk::MSG_BAD_FORMAT, $e->getMessage());
            return;
        }
        
        $this->markTestSkipped("Not exception");
    }
    
    /**
     * watch command
     *
     */
    public function testShouldWatch()
    {
        $countWatchTubes = $this->client->watch(self::TUBE_NAME_1);
        
        $this->assertNotEquals(false, $countWatchTubes);
        $this->assertEquals($countWatchTubes, 2);
    }
    
    /**
     * choose -> put -> watch -> reserve -> delete
     * 
     * @depends testShouldChoose
     * @depends testShouldWatch
     */
    public function testShouldPutAndReserveAndDelete()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');
        $this->assertNotEquals(false, $jobId);
        
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        $this->assertInstanceOf(self::JOB_CLASS, $job);
        $this->assertEquals($jobId, $job->getId());
        
        $this->assertTrue($job->delete());
    }
    
    /**
     * @depends testShouldPutAndReserveAndDelete
     */
    public function testShouldPutAndPeekReady()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');
        
        $job = $this->client->peekReady();
        $this->assertInstanceOf(self::JOB_CLASS, $job);
        $this->assertEquals($jobId, $job->getId());
        
        $this->assertTrue($job->delete());
    }
    
    /**
     * choose -> put -> watch -> reserve-with-timeout -> delete
     * 
     * @todo bad test, but have so far
     * 
     * @depends testShouldChoose
     * @depends testShouldWatch
     */
    public function testShouldPutAndReserveTimeoutAndDelete()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');
        
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve(2);
        $this->assertInstanceOf(self::JOB_CLASS, $job);
        $this->assertEquals($jobId, $job->getId());
        
        $this->assertTrue($job->delete());
    }
    
    /**
     * many tubes watch
     * choose -> put -> choose -> put -> watch,watch -> reserve -> delete
     * 
     * @depends testShouldChoose
     * @depends testShouldWatch
     */
    public function testShouldPutAndReserveManyTubesAndDelete()
    {
        $tubes = [self::TUBE_NAME_1,self::TUBE_NAME_2];
        
        $jobsId = [];
        foreach ($tubes as $tube) {
            $this->client->choose($tube);
            $jobId = $this->client->put('testPutInTube');
            $this->assertNotEquals(false, $jobId);
            $jobsId[] = $jobId;
        }
        
        $jobs = [];
        foreach ($tubes as $tubeWatch) {
            $this->client->watch($tubeWatch);
        }
        
        while ($job = $this->client->reserve(1)) {
            $jobs[] = $job;
        }
        
        $this->assertEquals(count($tubes), count($jobs));
        
        foreach ($jobs as $k => $job) {
            $this->assertInstanceOf(self::JOB_CLASS, $jobs[$k]);
            $this->assertEquals($jobsId[$k], $jobs[$k]->getId());
            $this->assertTrue($jobs[$k]->delete());
        }
    }
    
    /**
     * @depends testShouldPutAndReserveAndDelete
     */
    public function testShouldPutAndReserveJobAndBackReady()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');
        
        $this->assertEquals('ready', (new Job($this->client, $jobId, ''))->stats()['state']);
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        $this->assertInstanceOf(self::JOB_CLASS, $job);
        $this->assertEquals($jobId, $job->getId());
        
        $this->assertEquals('reserved', $job->stats()['state']);
        $this->assertEquals(1, $job->stats()['reserves']);
        
        $this->assertTrue($job->release());
        $this->assertEquals('ready', $job->stats()['state']);
        $this->assertEquals(1, $job->stats()['releases']);
        
        $this->assertTrue($job->delete());
    }
    
    
    /**
     * @depends testShouldPutAndReserveAndDelete
     */
    public function testShouldPutAndReserveJobAndBackReadyDelay()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');
        
        $this->assertEquals('ready', (new Job($this->client, $jobId, ''))->stats()['state']);
        
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        $this->assertEquals('reserved', $job->stats()['state']);
        $this->assertEquals(1, $job->stats()['reserves']);
        
        $this->assertTrue($job->release(Beanstalk::DEFAULT_PRIORITY, 3));
        $this->assertEquals('delayed', $job->stats()['state']);
        $this->assertEquals(1, $job->stats()['releases']);
        $this->assertEquals(3, $job->stats()['delay']);
        sleep(4);
        $this->assertEquals(4, $job->stats()['age']);
        $this->assertEquals('ready', $job->stats()['state']);
        $this->assertTrue($job->delete());
    }
    
    /**
     * @depends testShouldPutAndReserveAndDelete
     */
    public function testShouldPutBuriedAfterPeekBuriedAndKick()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');
        
        $this->assertEquals('ready', (new Job($this->client, $jobId, ''))->stats()['state']);
        
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        
        $this->assertTrue($job->bury(Beanstalk::DEFAULT_PRIORITY));
        $this->assertEquals('buried', $job->stats()['state']);
        $this->assertEquals(1, $job->stats()['buries']);
        
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->peekBuried();
        
        $this->assertInstanceOf(self::JOB_CLASS, $job);
        $this->assertEquals($jobId, $job->getId());
        
        $this->assertTrue($job->kick());
        $this->assertEquals('ready', $job->stats()['state']);
        $this->assertEquals(1, $job->stats()['kicks']);
        
        $this->assertTrue($job->delete());
    }
    
    /**
     * @depends testShouldPutAndReserveAndDelete
     */
    public function testShouldPutDelay()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube', ['delay' => 2]);
        $job = new Job($this->client, $jobId, '');
        $this->assertEquals('delayed', $job->stats()['state']);
        sleep(3);
        $this->assertEquals('ready', $job->stats()['state']);
        
        $this->client->watch(self::TUBE_NAME_1);
        
        $job = $this->client->reserve();
        $this->assertTrue($job->delete());
        
        $jobId = $this->client->put('testPutInTube', ['delay' => 2]);
        $job = $this->client->peekDelayed();
        $this->assertTrue($job->delete());
    }
    
    /**
     * @depends testShouldPutAndReserveAndDelete
     * @depends testShouldPutDelay
     */
    public function testShouldPutDelayAfterKick()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube', ['delay' => 3]);
        $job = new Job($this->client, $jobId, '');
        
        $this->assertTrue($job->kick());
        $this->assertEquals('ready', $job->stats()['state']);
        
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        $this->assertTrue($job->delete());
    }
    
    /**
     * @depends testShouldPutBuriedAfterPeekBuriedAndKick
     * @depends testShouldPutDelay
     */
    public function testShouldPutDelayAndPutBuriedAfterKick()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube', ['delay' => 3]);
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        $this->assertTrue($job->bury(Beanstalk::DEFAULT_PRIORITY));
        $this->assertTrue($job->kick());
        $this->assertEquals('ready', $job->stats()['state']);
        $this->assertTrue($job->delete());
    }
    
    /**
     * @depends testShouldPutDelayAfterKick
     * @depends testShouldPutDelayAndPutBuriedAfterKick
     */
    public function testShouldPutDelayKickAndBuryKick()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube', ['delay' => 3]);
        $job = new Job($this->client, $jobId, '');
        
        $this->assertEquals(1, $this->client->kick(1));
        $this->assertEquals('ready', $job->stats()['state']);
        
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        
        $this->assertTrue($job->bury(Beanstalk::DEFAULT_PRIORITY));
        $this->assertEquals(1, $this->client->kick(1));
        $this->assertEquals('ready', $job->stats()['state']);
        $this->assertTrue($job->delete());
    }
    
    /**
     * @depends testShouldPutAndReserveAndDelete
     */
    public function testShouldPutAndTouch()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube', ['ttr' => 10]);
        
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        sleep(2);
        $this->assertEquals(7, $job->stats()['time-left']);
        $this->assertTrue($job->touch());
        $this->assertEquals(9, $job->stats()['time-left']);
        $this->assertTrue($job->delete());
    }
    
    /**
     * list-tubes command
     * 
     * @depends testShouldPutAndReserveAndDelete
     */
    public function testShouldListTubes()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $tubes = $this->client->listTubes();
        $this->assertTrue(in_array(self::TUBE_NAME_1, $tubes));
    }
    
    /**
     * @depends testShouldPutAndReserveAndDelete
     */
    public function testShouldPutAndPeek()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');
        
        $this->assertNotEquals(false, $jobId);
        $job = $this->client->jobPeek($jobId);
        $this->assertInstanceOf(self::JOB_CLASS, $job);
        $this->assertEquals($jobId, $job->getId());
        $this->assertTrue($job->delete());
    }

    public function testBasic()
    {
        $expected = array('processVideo' => 4871);

        $this->client->put($expected);
        while (($job = $this->client->peekReady()) !== false) {
            $actual = $job->getBody();
            $job->delete();
            $this->assertEquals($expected, $actual);
        }
    }

    public function testReleaseKickBury()
    {
        $this->assertTrue($this->client->choose('beanstalk-test') !== false);

        $task = 'doSomething';

        $this->assertTrue($this->client->put($task) !== false);

        $this->assertTrue($this->client->watch('beanstalk-test') !== false);

        $job = $this->client->reserve(0);

        $this->assertTrue($job !== false);
        $this->assertEquals($task, $job->getBody());

        $this->assertTrue($job->touch());

        // Release the job; it moves to the ready queue
        $this->assertTrue($job->release());
        $job = $this->client->reserve(0);

        $this->assertTrue($job !== false);
        $this->assertEquals($task, $job->getBody());

        // Bury the job
        $this->assertTrue($job->bury());
        $job = $this->client->peekBuried();

        $this->assertTrue($job !== false);
        $this->assertEquals($task, $job->getBody());

        // Kick the job, it should move to the ready queue again
        // kick-job is supported since 1.8
        if (false !== $job->kick()) {
            $job = $this->client->peekReady();

            $this->assertTrue($job !== false);
            $this->assertEquals($task, $job->getBody());
        }

        $this->assertTrue($job->delete());
    }

    public function testStats()
    {
        $this->assertTrue($this->client->choose('beanstalk-test') !== false);

        $queueStats = $this->client->stats();
        $this->assertTrue(is_array($queueStats));

        $tubeStats = $this->client->statsTube('beanstalk-test');
        $this->assertTrue(is_array($tubeStats));
        $this->assertTrue($tubeStats['name'] === 'beanstalk-test');

        $this->assertTrue($this->client->statsTube('beanstalk-test-does-not-exist') === false);
        $this->assertTrue($this->client->choose('beanstalk-test') !== false);

        $this->client->put('doSomething');

        $this->client->watch('beanstalk-test');
        $job = $this->client->peekReady();
        $jobStats = $job->stats();

        $this->assertTrue(is_array($jobStats));
        $this->assertTrue($jobStats['tube'] === 'beanstalk-test');
    }

}
