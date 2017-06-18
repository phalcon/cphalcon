<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation\Message\Group;
use Phalcon\Validation\Validator\CreditCard;

/**
 * \Phalcon\Test\Unit\Validation\Validator\CreditCardTest
 * Tests the \Phalcon\Validation\Validator\CreditCard component
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
class CreditCardTest extends UnitTest
{
    /**
     * Tests credit card validator with single field
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateSingleField()
    {
        $this->specify('Test credit card validator with single field.', function () {
            $validation = new Validation();
            $validation->add('creditCard', new CreditCard());

            expect($validation->validate(['creditCard' => 4601587377626131]))->count(0);
            expect($validation->validate(['creditCard' => 46015873776261312]))->count(1);
        });
    }

    /**
     * Tests credit card validator with multiple field
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateMultipleFields()
    {
        $this->specify('Test credit card validator with multiple field.', function () {
            $validation = new Validation();

            $validationMessages = [
                'creditCard'        => 'CreditCard must be correct credit card value.',
                'anotherCreditCard' => 'AnotherCreditCard must be correct credit card value.',
            ];

            $validation->add(['creditCard', 'anotherCreditCard'], new CreditCard([
                'message' => $validationMessages,
            ]));

            $messages = $validation->validate(
                [
                    'creditCard'        => 4601587377626131,
                    'anotherCreditCard' => 4601587377626131,
                ]
            );

            expect($messages->count())->equals(0);

            $messages = $validation->validate(
                [
                    'creditCard'        => 46015873776261312,
                    'anotherCreditCard' => 4601587377626131,
                ]
            );

            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['creditCard']);



            $messages = $validation->validate(
                [
                    'creditCard'        => 46015873776261312,
                    'anotherCreditCard' => 46015873776261312,
                ]
            );

            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['creditCard']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherCreditCard']);
        });
    }

    /**
     * Tests detect valid card numbers
     *
     * @test
     * @author Caio Almeida <caio.f.r.amd@gmail.com>
     * @since  2015-09-06
     */
    public function shouldDetectValidCreditCard()
    {
        $this->specify(
            "The CreditCard validator can't detect valid card number correctly.",
            function ($number) {
                $validation = new Validation();
                $validation->add('creditCard', new CreditCard());

                expect($validation->validate(['creditCard' => $number]))->count(0);
            },
            ['examples' => $this->validCardNumberProvider()]
        );
    }

    /**
     * Tests detect invalid card numbers
     *
     * @test
     * @author Caio Almeida <caio.f.r.amd@gmail.com>
     * @since  2015-09-06
     */
    public function shouldDetectInvalidCreditCard()
    {
        $this->specify(
            "The CreditCard validator can't detect invalid card number correctly.",
            function ($number) {
                $validation = new Validation();
                $validation->add('creditCard', new CreditCard());

                $expected = Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type'    => 'CreditCard',
                            '_message' => 'Field creditCard is not valid for a credit card number',
                            '_field'   => 'creditCard',
                            '_code'    => '0',
                        ])
                    ]
                ]);

                $actual = $validation->validate(['creditCard' => $number]);

                expect($actual)->equals($expected);
            },
            ['examples' => $this->invalidCardNumberProvider()]
        );
    }

    protected function validCardNumberProvider()
    {
        return [
            'amex'       => ['378282246310005' ],
            'visa'       => ['4012888888881881'],
            'dinners'    => ['38520000023237'  ],
            'mastercard' => ['5105105105105100'],
            'discover'   => ['6011000990139424'],
        ];
    }

    protected function invalidCardNumberProvider()
    {
        return [
            ['1203191201121221'],
            ['102030102320'    ],
            ['120120s201023'   ],
            ['20323200003230'  ],
            ['12010012'       ],
        ];
    }
}
