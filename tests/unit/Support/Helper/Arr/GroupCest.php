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

use Phalcon\Support\Helper\Arr\Group;
use stdClass;
use UnitTester;

/**
 * Class GroupCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class GroupCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: group()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrGroup(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - group()');

        $object     = new Group();
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

        $actual = $object($collection, 'age');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: group() - object
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrGroupObject(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - group() - object');

        $object      = new Group();
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
        $actual   = $object($collection, 'name');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: group() - function
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrGroupFunction(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - group() - function');

        $object     = new Group();
        $collection = ['one', 'two', 'three'];

        $expected = [
            3 => ['one', 'two'],
            5 => ['three'],
        ];
        $actual   = $object($collection, 'strlen');
        $I->assertEquals($expected, $actual);
    }
}
