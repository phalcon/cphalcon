<?php

namespace Phalcon\Test\Unit\Queue;

use Phalcon\Test\Unit\Queue\Helper\BeanstalkBase;

use Phalcon\Queue\Beanstalk\Job;
use Phalcon\Queue\Beanstalk;
use Phalcon\Queue\Beanstalk\Exception;

/**
 * \Phalcon\Test\Unit\Queue\BeanstalkTest
 * Tests the \Phalcon\Queue\Beanstalk component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Queue
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class BeanstalkTest extends BeanstalkBase
{
    const TUBE_NAME_1 = 'beanstalk-test-1';
    const TUBE_NAME_2 = 'beanstalk-test-2';
    const TUBE_NAME_DEFAULT = 'default';
    const JOB_CLASS = 'Phalcon\Queue\Beanstalk\Job';

    /**
     * Tests Beanstalk connection
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-04-11
     */
    public function testShouldConnectAndDisconnect()
    {
        $this->specify(
            "The Beanstalk connection does not work as expected",
            function () {
                $this->client->disconnect();

                expect($this->client->disconnect())->false();
                expect(is_resource($this->client->connect()))->true();
                expect($this->client->disconnect())->true();
            }
        );
    }

    /**
     * Tests Beanstalk::getBody
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testShouldGetBody()
    {
        $this->specify(
            "The getBody method does not return expected message",
            function () {
                $expected = ['processVideo' => 4871];

                $this->client->put($expected);
                while (($job = $this->client->peekReady()) !== false) {
                    $actual = $job->getBody();
                    $job->delete();

                    expect($actual)->equals($expected);
                }
            }
        );
    }

    /**
     * Tests changing the active tube.
     * use command
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-17
     */
    public function testShouldChooseTube()
    {
        $this->specify(
            "Unable to change the active tube",
            function () {
                expect($this->client->choose(self::TUBE_NAME_1))->equals(self::TUBE_NAME_1);
                expect($this->client->choose(self::TUBE_NAME_DEFAULT))->equals(self::TUBE_NAME_DEFAULT);
            }
        );
    }

    /**
     * Tests getting status
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2015-05-11
     */
    public function testShouldGetStats()
    {
        $this->specify(
            "Unable get status",
            function () {
                expect(is_array($this->client->stats()))->true();

                $this->client->choose(self::TUBE_NAME_1);
                $tubeStats = $this->client->statsTube(self::TUBE_NAME_1);

                expect(is_array($tubeStats))->true();
                $this->assertArrayHasKey('name', $tubeStats);
                $this->assertTrue($tubeStats['name'] === self::TUBE_NAME_1);

                $this->client->choose(self::TUBE_NAME_DEFAULT);

                expect($this->client->statsTube('beanstalk-test-does-not-exist'))->false();
            }
        );
    }

    public function testShouldReleaseKickAndBury()
    {
        $this->specify(
            "Incorrect work with job queue",
            function () {
                $this->client->choose(self::TUBE_NAME_1);

                $task = 'doSomething';
                verify($this->client->put($task) !== false);
                verify($this->client->watch(self::TUBE_NAME_1) !== false);

                $job = $this->client->reserve(0);

                $this->assertInstanceOf(self::JOB_CLASS, $job);
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
        );
    }

    /**
     * Test exceeded the maximum number of characters in the tube name
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     * @expectedException \Phalcon\Queue\Beanstalk\Exception
     * @expectedExceptionMessage BAD_FORMAT
     */
    public function testShouldChooseException()
    {
        $this->client->choose(str_pad(self::TUBE_NAME_1, 201, 'over'));
    }

    /**
     * watch command
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
     * @depends testShouldChooseTube
     * @depends testShouldWatch
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
     * @depends testShouldChooseTube
     * @depends testShouldWatch
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
     * @depends testShouldChooseTube
     * @depends testShouldWatch
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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

        $this->client->put('testPutInTube', ['delay' => 2]);
        $job = $this->client->peekDelayed();
        $this->assertTrue($job->delete());
    }

    /**
     * @depends testShouldPutAndReserveAndDelete
     * @depends testShouldPutDelay
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutDelayAndPutBuriedAfterKick()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $this->client->put('testPutInTube', ['delay' => 3]);
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
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutAndTouch()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $this->client->put('testPutInTube', ['ttr' => 10]);

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
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldListTubes()
    {
        $this->client->choose(self::TUBE_NAME_1);
        $tubes = $this->client->listTubes();
        $this->assertTrue(in_array(self::TUBE_NAME_1, $tubes));
    }

    /**
     * @depends testShouldPutAndReserveAndDelete
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
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
}
