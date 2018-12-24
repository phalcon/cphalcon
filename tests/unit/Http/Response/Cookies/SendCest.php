<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response\Cookies;

use UnitTester;

/**
 * Class SendCest
 */
class SendCest
{
    /**
     * Tests Phalcon\Http\Response\Cookies :: send()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpResponseCookiesSend(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - send()');
        $I->skipTest('Need implementation');
    }
}
