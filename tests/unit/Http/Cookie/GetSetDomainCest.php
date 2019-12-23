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

class GetSetDomainCest
{
    /**
     * Tests Phalcon\Http\Cookie :: getDomain()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpCookieGetDomain(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - getDomain()');

        $cookie = new Cookie(
            'test-cookie',
            'test',
            time() + 3600,
            '/',
            null,
            'phalcon.ltd'
        );

        $I->assertEquals('phalcon.ltd', $cookie->getDomain());

        $cookie->setDomain('phalcon.io');

        $I->assertEquals('phalcon.io', $cookie->getDomain());
    }
}
