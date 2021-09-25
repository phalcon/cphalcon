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

class BlackListCest
{
    /**
     * Unit Tests Phalcon\Helper\Arr :: blackList()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    public function helperArrBlackList(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - blackList()');

        $value = [
            'value-1',
            'key-2'   => 'value-2',
            'key-3'   => 'value-3',
            9         => 'value-4',
            12        => 'value-5',
            ' key-6 ' => 'value-6',
            99        => 'value-7',
            'key-8'   => 'value-8',
        ];

        $blackList = [
            99, 48, 31, 9, 'key-45', null, -228, new stdClass(), [], 3.501, false, 'key-2', 'key-3',
        ];

        $expected = [
            'value-1',


            12        => 'value-5',
            ' key-6 ' => 'value-6',

            'key-8' => 'value-8',
        ];

        $actual = Arr::blackList($value, $blackList);

        $I->assertSame($expected, $actual);
    }
}
