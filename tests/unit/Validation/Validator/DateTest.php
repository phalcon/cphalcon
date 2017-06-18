<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation\Message\Group;
use Phalcon\Validation\Validator\Date;

/**
 * \Phalcon\Test\Unit\Validation\Validator\DateTest
 * Tests the \Phalcon\Validation\Validator\Date component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DateTest extends UnitTest
{
    /**
     * Tests date validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test date validator with single field.', function () {
            $validation = new Validation();
            $validation->add('date', new Date());

            expect($validation->validate(['date' => '2016-06-05']))->count(0);
            expect($validation->validate(['date' => '2016-06-32']))->count(1);
        });
    }

    /**
     * Tests date validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $this->specify('Test date validator with multiple field.', function () {
            $validation = new Validation();
            $validationMessages = [
                'date'       =>'Date must be correct date format Y-m-d.',
                'anotherDate'=>'AnotherDate must be correct date format d-m-Y.'
            ];

            $validation->add(['date', 'anotherDate'], new Date([
                'format'=>[
                    'date'=>'Y-m-d',
                    'anotherDate'=>'d-m-Y'
                ],
                'message'=>$validationMessages
            ]));


            expect($validation->validate(['date' => '2016-06-05', 'anotherDate' => '05-06-2017']))->count(0);

            $messages = $validation->validate(['date' => '2016-06-32', 'anotherDate' => '05-06-2017']);
            expect($messages)->count(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['date']);

            $messages = $validation->validate(['date' => '2016-06-32', 'anotherDate' => '32-06-2017']);
            expect($messages)->count(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['date']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherDate']);
        });
    }

    /**
     * Tests detect valid dates
     *
     * @test
     * @author Gustavo Verzola <verzola@gmail.com>
     * @since  2015-03-09
     */
    public function shouldDetectValidDates()
    {
        $this->specify(
            "The Date validator can't detect valid dates correctly.",
            function ($date, $format) {
                $validation = new Validation();
                $validation->add('date', new Date(['format' => $format]));

                expect($validation->validate(['date' => $date]))->count(0);
            },
            ['examples' => $this->validDatesProvider()]
        );
    }

    /**
     * Tests detect invalid dates
     *
     * @test
     * @author Gustavo Verzola <verzola@gmail.com>
     * @since  2015-03-09
     */
    public function shouldDetectInvalidDates()
    {
        $this->specify(
            "The Date validator can't detect invalid dates correctly.",
            function ($date, $format) {
                $validation = new Validation();
                $validation->add('date', new Date(['format' => $format]));

                $expected = Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type'    => 'Date',
                            '_message' => 'Field date is not a valid date',
                            '_field'   => 'date',
                            '_code'    => '0',
                        ])
                    ]
                ]);

                $actual = $validation->validate(['date' => $date]);

                expect($actual)->equals($expected);
            },
            ['examples' => $this->invalidDatesProvider()]
        );
    }

    protected function invalidDatesProvider()
    {
        return [
            ['',            'Y-m-d'],
            [false,         'Y-m-d'],
            [null,          'Y-m-d'],
            [new \stdClass, 'Y-m-d'],
            ['2015-13-01',  'Y-m-d'],
            ['2015-01-32',  'Y-m-d'],
            ['2015-01',     'Y-m-d'],
            ['2015-01-01',  'd-m-Y'],
        ];
    }

    protected function validDatesProvider()
    {
        return [
            ['2012-01-01', 'Y-m-d'],
            ['2013-31-12', 'Y-d-m'],
            ['01/01/2014', 'd/m/Y'],
            ['12@12@2015', 'd@m@Y'],
        ];
    }
}
