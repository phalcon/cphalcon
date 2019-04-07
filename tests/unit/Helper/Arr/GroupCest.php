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
 * Class GroupCest
 */
class GroupCest
{
    /**
     * Tests Phalcon\Helper\Arr :: group()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-07
     */
    public function helperArrGroup(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - group()');
        $collection =  [
            ['name' => 'Mashrafe', 'age' => 34],
            ['name' => 'Sakib',    'age' => 31],
            ['name' => 'Tamim',    'age' => 29],
        ];

        $expected = [
            34 => [
                [
                    'name' => 'Mashrafe',
                    'age' => 34,
                ],
            ],
            31 => [
                [
                    'name' => 'Sakib',
                    'age' => 31,
                ],
            ],
            29 => [
                [
                    'name' => 'Tamim',
                    'age' => 29,
                ],
            ],
        ];
        $actual = Arr::group($collection, 'age');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: group() - object
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-07
     */
    public function helperArrGroupObject(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - group() - object');

        $peter = new \stdClass();
        $peter->name = 'Peter';
        $peter->age = '25';

        $paul = new \stdClass();
        $paul->name = 'Paul';
        $paul->age = '25';

        $collection = [
            'peter' => $peter,
            'paul'  => $paul,
        ];


        $expected = [
            'Peter' => [$peter],
            'Paul'  => [$paul]
        ];
        $actual   = Arr::group($collection, 'name');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: group() - function
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-07
     */
    public function helperArrGroupFunction(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - group() - function');
        $collection = ['one', 'two', 'three'];

        $expected = [
            3 => ['one', 'two'],
            5 => ['three']
        ];
        $actual   = Arr::group($collection, 'strlen');
        $I->assertEquals($expected, $actual);
    }
}
