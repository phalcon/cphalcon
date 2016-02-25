<?php

namespace Phalcon\Test\Unit\Queue;

use Phalcon\Test\Unit\Queue\Helper\BeanstalkBase;

/**
 * \Phalcon\Test\Unit\Queue\BeanstalkTest
 * Tests the \Phalcon\Queue\Beanstalk component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Queue
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class BeanstalkTest extends BeanstalkBase
{
    /**
     * Tests Beanstalk::getBody
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testBeanstalk()
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
     * Tests changing the active tube
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-17
     */
    public function testChoose()
    {
        $this->specify(
            "Unable to change the active tube",
            function () {
                expect($this->client->choose('beanstalk-test'))->equals('beanstalk-test');
                expect($this->client->choose('default'))->equals('default');
            }
        );
    }

    /**
     * Tests getting status
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2015-05-11
     */
    public function testStats()
    {
        $this->specify(
            "Unable get status",
            function () {
                expect(is_array($this->client->stats()))->true();

                $this->client->choose('beanstalk-test');
                $tubeStats = $this->client->statsTube('beanstalk-test');

                expect(is_array($tubeStats))->true();
                $this->assertArrayHasKey('name', $tubeStats);
                $this->assertTrue($tubeStats['name'] === 'beanstalk-test');

                $this->client->choose('default');

                expect($this->client->statsTube('beanstalk-test-does-not-exist'))->false();
            }
        );
    }

    public function testReleaseKickBury()
    {
        $this->specify(
            "Incorrect work with job queue",
            function () {
                $this->client->choose('beanstalk-test');

                $task = 'doSomething';
                verify($this->client->put($task) !== false);
                verify($this->client->watch('beanstalk-test') !== false);

                $job = $this->client->reserve(0);

                $this->assertInstanceOf('Phalcon\Queue\Beanstalk\Job', $job);
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
}
