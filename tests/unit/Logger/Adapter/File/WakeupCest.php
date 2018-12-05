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

namespace Phalcon\Test\Unit\Logger\Adapter\File;

use UnitTester;

/**
 * Class WakeupCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class WakeupCest
{
    /**
     * Tests Phalcon\Logger\Adapter\File :: __wakeup()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterFileWakeup(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\File - __wakeup()");
        $I->skipTest("Need implementation");
    }
}
