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

class PauseTubeCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk :: pauseTube()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function queueBeanstalkPauseTube(UnitTester $I)
    {
        $I->wantToTest("Queue\Beanstalk - pauseTube()");
        $I->skipTest("Need implementation");
    }
}
