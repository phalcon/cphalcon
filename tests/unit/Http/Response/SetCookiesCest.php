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

namespace Phalcon\Test\Unit\Http\Response;

use UnitTester;

class SetCookiesCest
{
    /**
     * Tests Phalcon\Http\Response :: setCookies()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpResponseSetCookies(UnitTester $I)
    {
        $I->wantToTest('Http\Response - setCookies()');

        $I->skipTest('Need implementation');
    }
}
