<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Validation\Validator;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Date;
use stdClass;

class DateCest
{
    /**
     * Tests date validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorSingleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'date',
            new Date()
        );


        $messages = $validation->validate(
            [
                'date' => '2016-06-05',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'date' => '2016-06-32',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );
    }

    /**
     * Tests date validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorMultipleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validationMessages = [
            'date'        => 'Date must be correct date format Y-m-d.',
            'anotherDate' => 'AnotherDate must be correct date format d-m-Y.',
        ];

        $validation->add(
            ['date', 'anotherDate'],
            new Date(
                [
                    'format'  => [
                        'date'        => 'Y-m-d',
                        'anotherDate' => 'd-m-Y',
                    ],
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(
            [
                'date'        => '2016-06-05',
                'anotherDate' => '05-06-2017',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );

        $messages = $validation->validate(
            [
                'date'        => '2016-06-32',
                'anotherDate' => '05-06-2017',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );

        $expected = $validationMessages['date'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'date'        => '2016-06-32',
                'anotherDate' => '32-06-2017',
            ]
        );

        $I->assertEquals(
            2,
            $messages->count()
        );

        $expected = $validationMessages['date'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['anotherDate'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests detect valid dates
     *
     * @author       Gustavo Verzola <verzola@gmail.com>
     * @since        2015-03-09
     *
     * @dataProvider shouldDetectValidDatesProvider
     */
    public function shouldDetectValidDates(IntegrationTester $I, Example $example)
    {
        $date   = $example[0];
        $format = $example[1];

        $validation = new Validation();

        $validation->add(
            'date',
            new Date(
                [
                    'format' => $format,
                ]
            )
        );

        $messages = $validation->validate(
            [
                'date' => $date,
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );
    }

    /**
     * Tests detect invalid dates
     *
     * @author       Gustavo Verzola <verzola@gmail.com>
     * @since        2015-03-09
     *
     * @dataProvider shouldDetectInvalidDatesProvider
     */
    public function shouldDetectInvalidDates(IntegrationTester $I, Example $example)
    {
        $date   = $example[0];
        $format = $example[1];

        $validation = new Validation();

        $validation->add(
            'date',
            new Date(
                [
                    'format' => $format,
                ]
            )
        );

        $expected = new Messages(
            [
                new Message(
                    'Field date is not a valid date',
                    'date',
                    Date::class,
                    0
                ),
            ]
        );

        $actual = $validation->validate(
            [
                'date' => $date,
            ]
        );

        $I->assertEquals($expected, $actual);
    }

    protected function shouldDetectValidDatesProvider(): array
    {
        return [
            ['2012-01-01', 'Y-m-d'],
            ['2013-31-12', 'Y-d-m'],
            ['01/01/2014', 'd/m/Y'],
            ['12@12@2015', 'd@m@Y'],
        ];
    }

    protected function shouldDetectInvalidDatesProvider(): array
    {
        return [
            ['', 'Y-m-d'],
            [false, 'Y-m-d'],
            [null, 'Y-m-d'],
            [new stdClass(), 'Y-m-d'],
            ['2015-13-01', 'Y-m-d'],
            ['2015-01-32', 'Y-m-d'],
            ['2015-01', 'Y-m-d'],
            ['2015-01-01', 'd-m-Y'],
        ];

        foreach ($dates as $item) {
            $date   = $item[0];
            $format = $item[1];

            $validation = new Validation();

            $validation->add(
                'date',
                new Date(
                    [
                        'format' => $format,
                    ]
                )
            );

            $expected = new Messages(
                [
                    new Message(
                        'Field date is not a valid date',
                        'date',
                        Date::class,
                        0
                    ),
                ]
            );

            $actual = $validation->validate(
                [
                    'date' => $date,
                ]
            );

            $I->assertEquals($expected, $actual);
        }
    }
}
