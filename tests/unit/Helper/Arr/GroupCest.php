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

class GroupCest
{
    /**
     * Tests Phalcon\Helper\Arr :: group()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-07
     */
    public function helperArrGroup(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - group()');

        $collection = [
            [
                'name' => 'Paul',
                'age'  => 34,
            ],
            [
                'name' => 'Peter',
                'age'  => 31,
            ],
            [
                'name' => 'John',
                'age'  => 29,
            ],
        ];

        $expected = [
            34 => [
                [
                    'name' => 'Paul',
                    'age'  => 34,
                ],
            ],
            31 => [
                [
                    'name' => 'Peter',
                    'age'  => 31,
                ],
            ],
            29 => [
                [
                    'name' => 'John',
                    'age'  => 29,
                ],
            ],
        ];

        $actual = Arr::group($collection, 'age');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: group() - object
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-07
     */
    public function helperArrGroupObject(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - group() - object');

        $peter       = new stdClass();
        $peter->name = 'Peter';
        $peter->age  = 34;

        $paul       = new stdClass();
        $paul->name = 'Paul';
        $paul->age  = 31;

        $collection = [
            'peter' => $peter,
            'paul'  => $paul,
        ];


        $expected = [
            'Peter' => [$peter],
            'Paul'  => [$paul],
        ];

        $I->assertEquals(
            $expected,
            Arr::group($collection, 'name')
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: group() - function
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-07
     */
    public function helperArrGroupFunction(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - group() - function');

        $collection = ['one', 'two', 'three'];

        $expected = [
            3 => ['one', 'two'],
            5 => ['three'],
        ];

        $I->assertEquals(
            $expected,
            Arr::group($collection, 'strlen')
        );
    }
}
