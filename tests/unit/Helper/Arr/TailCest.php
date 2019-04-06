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
 * Class TailCest
 */
class TailCest
{
    /**
     * Tests Phalcon\Helper\Arr :: tail()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrTail(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - tail()');
        $collection = [
            'Phalcon',
            'Framework',
            'for',
            'PHP',
        ];

        $expected = [
            'Framework',
            'for',
            'PHP',
        ];
        $actual   = Arr::tail($collection);
        $I->assertEquals($expected, $actual);

        $collection = ['Phalcon'];
        $expected   = $collection;
        $actual     = Arr::tail($collection);
        $I->assertEquals($expected, $actual);
    }
}
