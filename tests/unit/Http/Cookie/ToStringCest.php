<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Cookie;

use UnitTester;

class ToStringCest
{
    /**
     * Tests Phalcon\Http\Cookie :: __toString()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpCookieToString(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - __toString()');

        $I->skipTest('Need implementation');
    }
}
