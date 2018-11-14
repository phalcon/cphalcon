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

class BuryCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk\Job :: bury()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testBury(UnitTester $I, $scenario)
    {
        $scenario->incomplete("Need implementation");
    }
}
