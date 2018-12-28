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

namespace Phalcon\Test\Unit\Http\Response\Headers;

use UnitTester;

/**
 * Class SetRawCest
 */
class SetRawCest
{
    /**
     * Tests Phalcon\Http\Response\Headers :: setRaw()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpResponseHeadersSetRaw(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Headers - setRaw()');
        $I->skipTest('Need implementation');
    }
}
