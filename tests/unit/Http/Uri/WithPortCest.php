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

namespace Phalcon\Test\Unit\Http\Uri;

use UnitTester;

/**
 * Class WithPortCest
 */
class WithPortCest
{
    /**
     * Tests Phalcon\Http\Uri :: withPort()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpUriWithPort(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - withPort()');
        $I->skipTest('Need implementation');
    }
}
