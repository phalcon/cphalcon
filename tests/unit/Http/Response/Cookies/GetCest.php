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

namespace Phalcon\Test\Unit\Http\Response\Cookies;

use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Http\Response\Cookies :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpResponseCookiesGet(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - get()');

        $I->skipTest('Need implementation');
    }
}
