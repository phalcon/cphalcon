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

class PeekDelayedCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk :: peekDelayed()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function queueBeanstalkPeekDelayed(UnitTester $I)
    {
        $I->wantToTest("Queue\Beanstalk - peekDelayed()");
        $I->skipTest("Need implementation");
    }
}
