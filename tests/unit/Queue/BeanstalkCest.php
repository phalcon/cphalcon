<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Queue;

use Phalcon\Test\Fixtures\Traits\BeanstalkTrait;
use Phalcon\Queue\Beanstalk\Job;
use Phalcon\Queue\Beanstalk;
use Phalcon\Queue\Beanstalk\Exception;
use UnitTester;

class BeanstalkCest
{
    use BeanstalkTrait;

    const TUBE_NAME_1 = 'beanstalk-test-1';
    const TUBE_NAME_2 = 'beanstalk-test-2';
    const TUBE_NAME_DEFAULT = 'default';
    const JOB_CLASS = 'Phalcon\Queue\Beanstalk\Job';

    /**
     * Tests Beanstalk connection
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-04-11
     */
    public function testShouldConnectAndDisconnect(UnitTester $I)
    {
        $this->client->disconnect();

        $I->assertFalse($this->client->disconnect());
        $I->assertTrue(is_resource($this->client->connect()));
        $I->assertTrue($this->client->disconnect());
    }

    /**
     * Tests Beanstalk::getBody
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testShouldGetBody(UnitTester $I)
    {
        $expected = ['processVideo' => 4871];

        $this->client->put($expected);
        while (($job = $this->client->peekReady()) !== false) {
            $actual = $job->getBody();
            $job->delete();
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests changing the active tube.
     * use command
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-17
     */
    public function testShouldChooseTube(UnitTester $I)
    {
        $expected = self::TUBE_NAME_1;
        $actual   = $this->client->choose(self::TUBE_NAME_1);
        $I->assertEquals($expected, $actual);

        $expected = self::TUBE_NAME_DEFAULT;
        $actual   = $this->client->choose(self::TUBE_NAME_DEFAULT);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests getting status
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2015-05-11
     */
    public function testShouldGetStats(UnitTester $I)
    {
        $I->assertTrue(is_array($this->client->stats()));

        $this->client->choose(self::TUBE_NAME_1);
        $tubeStats = $this->client->statsTube(self::TUBE_NAME_1);

        $I->assertTrue(is_array($tubeStats));
        $I->assertArrayHasKey('name', $tubeStats);
        $I->assertSame(self::TUBE_NAME_1, $tubeStats['name']);

        $this->client->choose(self::TUBE_NAME_DEFAULT);

        $I->assertFalse($this->client->statsTube('beanstalk-test-does-not-exist'));
    }

    public function testShouldReleaseKickAndBury(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);

        $task = 'doSomething';
        $I->assertNotFalse($this->client->put($task));
        $I->assertNotFalse($this->client->watch(self::TUBE_NAME_1));

        $job = $this->client->reserve(0);

        $I->assertInstanceOf(self::JOB_CLASS, $job);
        $I->assertEquals($task, $job->getBody());
        $I->assertTrue($job->touch());

        // Release the job; it moves to the ready queue
        $I->assertTrue($job->release());
        $job = $this->client->reserve(0);

        $I->assertTrue($job !== false);
        $I->assertEquals($task, $job->getBody());

        // Bury the job
        $I->assertTrue($job->bury());
        $job = $this->client->peekBuried();

        $I->assertTrue($job !== false);
        $I->assertEquals($task, $job->getBody());

        // Kick the job, it should move to the ready queue again
        // kick-job is supported since 1.8
        if (false !== $job->kick()) {
            $job = $this->client->peekReady();

            $I->assertTrue($job !== false);
            $I->assertEquals($task, $job->getBody());
            $I->assertTrue($job->delete());
        }
        $I->assertTrue($job->delete());
    }

    /**
     * Test exceeded the maximum number of characters in the tube name
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     * @expectedException \Phalcon\Queue\Beanstalk\Exception
     * @expectedExceptionMessage BAD_FORMAT
     */
    public function testShouldChooseException(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception('BAD_FORMAT'),
            function () {
                $this->client->choose(str_pad(self::TUBE_NAME_1, 201, 'over'));
            }
        );
    }

    /**
     * watch command
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldWatch(UnitTester $I)
    {
        $countWatchTubes = $this->client->watch(self::TUBE_NAME_1);

        $I->assertNotEquals(false, $countWatchTubes);
        $I->assertEquals($countWatchTubes, 2);
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
    public function testShouldPutAndReserveAndDelete(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');
        $I->assertNotEquals(false, $jobId);

        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        $I->assertInstanceOf(self::JOB_CLASS, $job);
        $I->assertEquals($jobId, $job->getId());

        $I->assertTrue($job->delete());
    }

    /**
     * @depends testShouldPutAndReserveAndDelete
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutAndPeekReady(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');

        $job = $this->client->peekReady();
        $I->assertInstanceOf(self::JOB_CLASS, $job);
        $I->assertEquals($jobId, $job->getId());

        $I->assertTrue($job->delete());
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
    public function testShouldPutAndReserveTimeoutAndDelete(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');

        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve(2);
        $I->assertInstanceOf(self::JOB_CLASS, $job);
        $I->assertEquals($jobId, $job->getId());

        $I->assertTrue($job->delete());
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
    public function testShouldPutAndReserveManyTubesAndDelete(UnitTester $I)
    {
        $tubes = [self::TUBE_NAME_1,self::TUBE_NAME_2];

        $jobsId = [];
        foreach ($tubes as $tube) {
            $this->client->choose($tube);
            $jobId = $this->client->put('testPutInTube');
            $I->assertNotEquals(false, $jobId);
            $jobsId[] = $jobId;
        }

        $jobs = [];
        foreach ($tubes as $tubeWatch) {
            $this->client->watch($tubeWatch);
        }

        while ($job = $this->client->reserve(1)) {
            $jobs[] = $job;
        }

        $I->assertCount(count($tubes), $jobs);

        foreach ($jobs as $k => $job) {
            $I->assertInstanceOf(self::JOB_CLASS, $jobs[$k]);
            $I->assertEquals($jobsId[$k], $jobs[$k]->getId());
            $I->assertTrue($jobs[$k]->delete());
        }
    }

    /**
     * @depends testShouldPutAndReserveAndDelete
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutAndReserveJobAndBackReady(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');

        $I->assertEquals('ready', (new Job($this->client, $jobId, ''))->stats()['state']);
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        $I->assertInstanceOf(self::JOB_CLASS, $job);
        $I->assertEquals($jobId, $job->getId());

        $I->assertEquals('reserved', $job->stats()['state']);
        $I->assertEquals(1, $job->stats()['reserves']);

        $I->assertTrue($job->release());
        $I->assertEquals('ready', $job->stats()['state']);
        $I->assertEquals(1, $job->stats()['releases']);

        $I->assertTrue($job->delete());
    }


    /**
     * @depends testShouldPutAndReserveAndDelete
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutAndReserveJobAndBackReadyDelay(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');

        $I->assertEquals('ready', (new Job($this->client, $jobId, ''))->stats()['state']);

        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        $I->assertEquals('reserved', $job->stats()['state']);
        $I->assertEquals(1, $job->stats()['reserves']);

        $I->assertTrue($job->release(Beanstalk::DEFAULT_PRIORITY, 3));
        $I->assertEquals('delayed', $job->stats()['state']);
        $I->assertEquals(1, $job->stats()['releases']);
        $I->assertEquals(3, $job->stats()['delay']);
        sleep(4);
        $I->assertEquals(4, $job->stats()['age']);
        $I->assertEquals('ready', $job->stats()['state']);
        $I->assertTrue($job->delete());
    }

    /**
     * @depends testShouldPutAndReserveAndDelete
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutBuriedAfterPeekBuriedAndKick(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');

        $I->assertEquals('ready', (new Job($this->client, $jobId, ''))->stats()['state']);

        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();

        $I->assertTrue($job->bury(Beanstalk::DEFAULT_PRIORITY));
        $I->assertEquals('buried', $job->stats()['state']);
        $I->assertEquals(1, $job->stats()['buries']);

        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->peekBuried();

        $I->assertInstanceOf(self::JOB_CLASS, $job);
        $I->assertEquals($jobId, $job->getId());

        $I->assertTrue($job->kick());
        $I->assertEquals('ready', $job->stats()['state']);
        $I->assertEquals(1, $job->stats()['kicks']);

        $I->assertTrue($job->delete());
    }

    /**
     * @depends testShouldPutAndReserveAndDelete
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutDelay(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube', ['delay' => 2]);
        $job = new Job($this->client, $jobId, '');
        $I->assertEquals('delayed', $job->stats()['state']);
        sleep(3);
        $I->assertEquals('ready', $job->stats()['state']);

        $this->client->watch(self::TUBE_NAME_1);

        $job = $this->client->reserve();
        $I->assertTrue($job->delete());

        $this->client->put('testPutInTube', ['delay' => 2]);
        $job = $this->client->peekDelayed();
        $I->assertTrue($job->delete());
    }

    /**
     * @depends testShouldPutAndReserveAndDelete
     * @depends testShouldPutDelay
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutDelayAfterKick(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube', ['delay' => 3]);
        $job = new Job($this->client, $jobId, '');

        $I->assertTrue($job->kick());
        $I->assertEquals('ready', $job->stats()['state']);

        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        $I->assertTrue($job->delete());
    }

    /**
     * @depends testShouldPutBuriedAfterPeekBuriedAndKick
     * @depends testShouldPutDelay
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutDelayAndPutBuriedAfterKick(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $this->client->put('testPutInTube', ['delay' => 3]);
        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        $I->assertTrue($job->bury(Beanstalk::DEFAULT_PRIORITY));
        $I->assertTrue($job->kick());
        $I->assertEquals('ready', $job->stats()['state']);
        $I->assertTrue($job->delete());
    }

    /**
     * @depends testShouldPutDelayAfterKick
     * @depends testShouldPutDelayAndPutBuriedAfterKick
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutDelayKickAndBuryKick(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube', ['delay' => 3]);
        $job = new Job($this->client, $jobId, '');

        $I->assertEquals(1, $this->client->kick(1));
        $I->assertEquals('ready', $job->stats()['state']);

        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();

        $I->assertTrue($job->bury(Beanstalk::DEFAULT_PRIORITY));
        $I->assertEquals(1, $this->client->kick(1));
        $I->assertEquals('ready', $job->stats()['state']);
        $I->assertTrue($job->delete());
    }

    /**
     * @depends testShouldPutAndReserveAndDelete
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutAndTouch(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $this->client->put('testPutInTube', ['ttr' => 10]);

        $this->client->watch(self::TUBE_NAME_1);
        $job = $this->client->reserve();
        sleep(2);
        $I->assertEquals(7, $job->stats()['time-left']);
        $I->assertTrue($job->touch());
        $I->assertEquals(9, $job->stats()['time-left']);
        $I->assertTrue($job->delete());
    }

    /**
     * list-tubes command
     *
     * @depends testShouldPutAndReserveAndDelete
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldListTubes(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $tubes = $this->client->listTubes();
        $I->assertContains(self::TUBE_NAME_1, $tubes);
    }

    /**
     * @depends testShouldPutAndReserveAndDelete
     *
     * @author Dmitry Korolev <chameleonweb2012@gmail.com>
     * @since  2016-02-23
     */
    public function testShouldPutAndPeek(UnitTester $I)
    {
        $this->client->choose(self::TUBE_NAME_1);
        $jobId = $this->client->put('testPutInTube');

        $I->assertNotEquals(false, $jobId);
        $job = $this->client->jobPeek($jobId);
        $I->assertInstanceOf(self::JOB_CLASS, $job);
        $I->assertEquals($jobId, $job->getId());
        $I->assertTrue($job->delete());
    }
}
