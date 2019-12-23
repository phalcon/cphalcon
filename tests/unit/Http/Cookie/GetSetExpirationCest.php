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

use Phalcon\Http\Cookie;
use UnitTester;

class GetSetExpirationCest
{
    /**
     * Tests Phalcon\Http\Cookie :: getExpiration()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-23
     */
    public function httpCookieGetExpiration(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - getExpiration()');

        $exptime = time() + 3600;

        $cookie = new Cookie(
            'test-cookie',
            'test',
            $exptime
        );

        $I->assertEquals($exptime, $cookie->getExpiration());

        $exptime1 = time() + 7200;

        $cookie->setExpiration($exptime1);

        $I->assertEquals($exptime1, $cookie->getExpiration());
    }
}
