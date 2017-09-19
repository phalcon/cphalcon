<?php

namespace Phalcon\Test\Unit\Queue\Beanstalk;

use Phalcon\Test\Unit\Queue\Helper\BeanstalkBase;

/**
 * \Phalcon\Test\Unit\Queue\Beanstalk\JobTest
 * Tests the \Phalcon\Queue\Beanstalk\Job component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Queue\Beanstalk
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class JobTest extends BeanstalkBase
{
    /**
     * Tests getting status
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-17
     */
    public function testStats()
    {
        $this->specify(
            "Unable get status",
            function () {
                $this->client->choose('beanstalk-test');
                $this->client->put('doSomething');
                $this->client->watch('beanstalk-test');

                $job = $this->client->peekReady();
                $jobStats = $job->stats();

                verify(is_array($jobStats));
                $this->assertArrayHasKey('tube', $jobStats);
                verify($jobStats['tube'] === 'beanstalk-test');
            }
        );
    }
}
