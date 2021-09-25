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

namespace Phalcon\Tests\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

class HasCest
{
    /**
     * Tests Phalcon\Helper\Arr :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function helperArrHas(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - has()');

        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $I->assertTrue(
            Arr::has($collection, 1)
        );

        $I->assertTrue(
            Arr::has($collection, 'suffix')
        );

        $I->assertFalse(
            Arr::has($collection, 'unknown')
        );
    }
}
