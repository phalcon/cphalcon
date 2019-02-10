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

namespace Phalcon\Test\Unit\Http\Cookie\Exception;

use UnitTester;

/**
 * Class WakeupCest
 */
class WakeupCest
{
    /**
     * Tests Phalcon\Http\Cookie\Exception :: __wakeup()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpCookieExceptionWakeup(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie\Exception - __wakeup()');
        $I->skipTest('Need implementation');
    }
}
