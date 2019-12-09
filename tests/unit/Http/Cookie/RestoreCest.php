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

class RestoreCest
{
    /**
     * Tests Phalcon\Http\Cookie :: restore()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpCookieRestore(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - restore()');

        $I->skipTest('Need implementation');
    }
}
