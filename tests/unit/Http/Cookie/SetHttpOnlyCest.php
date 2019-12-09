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

class SetHttpOnlyCest
{
    /**
     * Tests Phalcon\Http\Cookie :: setHttpOnly()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpCookieSetHttpOnly(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - setHttpOnly()');

        $I->skipTest('Need implementation');
    }
}
