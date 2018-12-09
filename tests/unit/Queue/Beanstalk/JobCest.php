<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Queue\Beanstalk;

use Phalcon\Test\Fixtures\Traits\BeanstalkTrait;
use UnitTester;

class JobCest
{
    use BeanstalkTrait;

    /**
     * Tests getting status
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-17
     */
    public function testStats(UnitTester $I)
    {
        $this->client->choose('beanstalk-test');
        $this->client->put('doSomething');
        $this->client->watch('beanstalk-test');

        $job      = $this->client->peekReady();
        $jobStats = $job->stats();

        $I->assertTrue(is_array($jobStats));
        $I->assertTrue(isset($jobStats['tube']));
        $I->assertTrue($jobStats['tube'] === 'beanstalk-test');
    }
}
