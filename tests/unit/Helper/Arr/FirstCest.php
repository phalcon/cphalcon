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
 * Class FirstCest
 */
class FirstCest
{
    /**
     * Tests Phalcon\Helper\Arr :: first()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrFirst(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - first()');
        $collection = [
            'Phalcon',
            'Framework',
        ];

        $expected = 'Phalcon';
        $actual   = Arr::first($collection);
        $I->assertEquals($expected, $actual);
    }
}
