<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Queue\Beanstalk\Job;

use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk\Job :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function queueBeanstalkJobConstruct(UnitTester $I)
    {
        $I->wantToTest("Queue\Beanstalk\Job - __construct()");
        $I->skipTest("Need implementation");
    }
}
