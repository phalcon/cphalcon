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

class GetSetValueCest
{
    /**
     * Tests Phalcon\Http\Cookie :: getValue() / setValue()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2010-01-5
     */
    public function httpCookieGetSetValue(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - getValue() / setValue()');

        $cookie = new Cookie(
            'test-cookie',
            'test',
            time() + 3600,
            '/',
            null,
            'phalcon.ltd'
        );

        $I->assertEquals('test', $cookie->getValue());

        $cookie->setValue('new-value');
        $I->assertEquals('new-value', $cookie->getValue());
    }
}
