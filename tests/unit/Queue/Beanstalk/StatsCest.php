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
 * Class StatsCest
 *
 * @package Phalcon\Test\Unit\Queue\Beanstalk
 */
class StatsCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk :: stats()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function queueBeanstalkStats(UnitTester $I)
    {
        $I->wantToTest("Queue\Beanstalk - stats()");
        $I->skipTest("Need implementation");
    }
}
