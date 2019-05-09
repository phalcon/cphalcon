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

namespace Phalcon\Test\Unit\Http\Cookie\Exception;

use UnitTester;

class GetCodeCest
{
    /**
     * Tests Phalcon\Http\Cookie\Exception :: getCode()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpCookieExceptionGetCode(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie\Exception - getCode()');

        $I->skipTest('Need implementation');
    }
}
