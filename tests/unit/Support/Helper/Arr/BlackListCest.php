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

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Phalcon\Support\Helper\Arr\Blacklist;
use stdClass;
use UnitTester;

/**
 * Class BlackListCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class BlackListCest
{
    /**
     * Unit Tests Phalcon\Support\Helper\Arr :: blackList()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrBlackList(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - blackList()');

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
            99,
            48,
            31,
            9,
            'key-45',
            null,
            -228,
            new stdClass(),
            [],
            3.501,
            false,
            'key-2',
            'key-3',
        ];

        $object   = new Blacklist();
        $expected = [
            'value-1',
            12        => 'value-5',
            ' key-6 ' => 'value-6',
            'key-8'   => 'value-8',
        ];
        $actual   = $object->__invoke($value, $blackList);

        $I->assertSame($expected, $actual);
    }
}
