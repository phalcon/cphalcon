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

namespace Phalcon\Tests\Unit\Helper\Number;

use Phalcon\Helper\Number;
use UnitTester;

class BetweenCest
{
    /**
     * Tests Phalcon\Helper\Number :: between()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-17
     */
    public function helperNumberBetween(UnitTester $I)
    {
        $I->wantToTest('Helper\Number - between()');

        $I->assertTrue(
            Number::between(5, 1, 10)
        );

        $I->assertTrue(
            Number::between(1, 1, 10)
        );

        $I->assertTrue(
            Number::between(10, 1, 10)
        );

        $I->assertFalse(
            Number::between(1, 5, 10)
        );
    }
}
