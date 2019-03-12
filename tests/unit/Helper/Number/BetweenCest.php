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

namespace Phalcon\Test\Unit\Helper\Number;

use Phalcon\Helper\Number;
use UnitTester;

/**
 * Class BetweenCest
 */
class BetweenCest
{
    /**
     * Tests Phalcon\Helper\Number :: between()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-17
     */
    public function helperNumberBetween(UnitTester $I)
    {
        $I->wantToTest('Helper\Number - between()');

        $actual = Number::between(5, 1, 10);
        $I->assertTrue($actual);

        $actual = Number::between(1, 1, 10);
        $I->assertTrue($actual);

        $actual = Number::between(10, 1, 10);
        $I->assertTrue($actual);

        $actual = Number::between(1, 5, 10);
        $I->assertFalse($actual);
    }
}
