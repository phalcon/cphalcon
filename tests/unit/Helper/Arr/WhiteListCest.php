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
use stdClass;
use UnitTester;

class WhiteListCest
{
    /**
     * Unit Tests Phalcon\Helper\Arr :: whiteList()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-14
     */
    public function helperArrWhiteList(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - whiteList()');

        $value = [
            'value-1',
            ' key '  => 'value-2',
            5        => 'value-3',
            6        => 'value-4',
            7        => 'value-5',
            ' key-2' => 'value-6',
            'key-3 ' => 'value-7',
            'key-4'  => 'value-8',
        ];

        $whiteList = [
            7, 5, 0, 'key-3 ', null, -13, new stdClass(), [], 3.1415,
        ];

        $expected = [
            0        => 'value-1',
            5        => 'value-3',
            7        => 'value-5',
            'key-3 ' => 'value-7',
        ];

        $actual = Arr::whiteList($value, $whiteList);

        $I->assertSame($expected, $actual);
    }
}
