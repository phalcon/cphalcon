<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\Cookie;

use UnitTester;

class GetExpirationCest
{
    /**
     * Tests Phalcon\Http\Cookie :: getExpiration()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpCookieGetExpiration(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - getExpiration()');

        $I->skipTest('Need implementation');
    }
}
