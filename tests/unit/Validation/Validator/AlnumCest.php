<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Validator\Alnum;
use UnitTester;

class AlnumCest
{
    /**
     * Tests alnum validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('name', new Alnum());
        $messages = $validation->validate(['name' => 'SomeValue123']);

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123!@#']);

        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests alnum validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField(UnitTester $I)
    {
        $validation         = new Validation();
        $validationMessages = [
            'name' => 'Name must be alnum',
            'type' => 'Type must be alnum',
        ];
        $validation->add(
            [
                'name',
                'type',
            ],
            new Alnum(
                [
                    'message' => $validationMessages,
                ]
            )
        );
        $messages = $validation->validate(['name' => 'SomeValue123', 'type' => 'SomeValue123']);

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123!@#', 'type' => 'SomeValue123']);

        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['name' => 'SomeValue123!@#', 'type' => 'SomeValue123!@#']);

        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['name'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['type'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }
}
