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

class HasCest
{
    /**
     * Tests Phalcon\Http\Response\Cookies :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpResponseCookiesHas(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - has()');

        $I->skipTest('Need implementation');
    }
}
