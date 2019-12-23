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

class DeleteCest
{
    /**
     * Tests Phalcon\Http\Cookie :: delete()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-23
     */
    public function httpCookieDelete(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - delete()');

        $cookie = new Cookie(
            'test-cookie',
            'test',
            time() + 3600
        );

        $cookie->delete();

        $I->assertNull($cookie->getValue());
    }
}
