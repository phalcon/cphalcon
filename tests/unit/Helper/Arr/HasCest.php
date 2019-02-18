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

namespace Phalcon\Test\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

/**
 * Class HasCest
 */
class HasCest
{
    /**
     * Tests Phalcon\Helper\Arr :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function helperArrHas(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - has()');
        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $actual   = Arr::has($collection, 1);
        $I->assertTrue($actual);

        $actual   = Arr::has($collection, 'suffix');
        $I->assertTrue($actual);

        $actual   = Arr::has($collection, 'unknown');
        $I->assertFalse($actual);
    }
}
