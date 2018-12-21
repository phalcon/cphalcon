<?php
declare(strict_types=1);

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

/**
 * Class ReadStatusCest
 *
 * @package Phalcon\Test\Unit\Queue\Beanstalk
 */
class ReadStatusCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk :: readStatus()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function queueBeanstalkReadStatus(UnitTester $I)
    {
        $I->wantToTest("Queue\Beanstalk - readStatus()");
        $I->skipTest("Need implementation");
    }
}
