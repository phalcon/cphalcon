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
 * Class ResetCest
 */
class ResetCest
{
    /**
     * Tests Phalcon\Http\Response\Headers :: reset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpResponseHeadersReset(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Headers - reset()');
        $I->skipTest('Need implementation');
    }
}
