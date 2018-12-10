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
 * Class ChooseCest
 *
 * @package Phalcon\Test\Unit\Queue\Beanstalk
 */
class ChooseCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk :: choose()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function queueBeanstalkChoose(UnitTester $I)
    {
        $I->wantToTest("Queue\Beanstalk - choose()");
        $I->skipTest("Need implementation");
    }
}
