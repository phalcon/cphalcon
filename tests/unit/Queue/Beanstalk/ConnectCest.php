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

use UnitTester;

class ConnectCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk :: connect()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function queueBeanstalkConnect(UnitTester $I)
    {
        $I->wantToTest("Queue\Beanstalk - connect()");
        $I->skipTest("Need implementation");
    }
}
