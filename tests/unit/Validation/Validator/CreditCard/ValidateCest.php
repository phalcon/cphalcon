<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator\CreditCard;

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\CreditCard;
use UnitTester;

class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\CreditCard :: validate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorCreditCardValidate(UnitTester $I)
    {
        $I->skipTest("Need implementation");
    }
    /**
     * Tests Phalcon\Validation\Validator\CreditCard :: validate() - single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorCreditCardValidateSingleField(UnitTester $I)
    {
        $validation = new Validation();
        $validation->add('creditCard', new CreditCard());

        $expected = 0;
        $actual   = count($validation->validate(['creditCard' => 4601587377626131]));
        $I->assertEquals($expected, $actual);

        $expected = 1;
        $actual   = count($validation->validate(['creditCard' => 46015873776261312]));
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\CreditCard :: validate() - multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorCreditCardValidateMultipleFields(UnitTester $I)
    {
        $validation = new Validation();

        $validationMessages = [
            'creditCard'        => 'CreditCard must be correct credit card value.',
            'anotherCreditCard' => 'AnotherCreditCard must be correct credit card value.',
        ];

        $validation->add(
            ['creditCard', 'anotherCreditCard'],
            new CreditCard(
                [
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(
            [
                'creditCard'        => 4601587377626131,
                'anotherCreditCard' => 4601587377626131,
            ]
        );

        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'creditCard'        => 46015873776261312,
                'anotherCreditCard' => 4601587377626131,
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['creditCard'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'creditCard'        => 46015873776261312,
                'anotherCreditCard' => 46015873776261312,
            ]
        );

        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['creditCard'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['anotherCreditCard'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\CreditCard :: validate() - valid card numbers
     *
     * @author Caio Almeida <caio.f.r.amd@gmail.com>
     * @since  2015-09-06
     */
    public function validationValidatorCreditCardValidateValidCreditCard(UnitTester $I)
    {
        $providers = [
            'amex'       => '378282246310005',
            'visa'       => '4012888888881881',
            'dinners'    => '38520000023237',
            'mastercard' => '5105105105105100',
            'discover'   => '6011000990139424',
        ];

        foreach ($providers as $number) {
            $validation = new Validation();
            $validation->add('creditCard', new CreditCard());

            $expected = 0;
            $actual   = count($validation->validate(['creditCard' => $number]));
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Validation\Validator\CreditCard :: validate() - invalid card numbers
     *
     * @author Caio Almeida <caio.f.r.amd@gmail.com>
     * @since  2015-09-06
     */
    public function validationValidatorCreditCardValidateInvalidCreditCard(UnitTester $I)
    {
        $cards = [
            '1203191201121221',
            '102030102320',
            '120120s201023',
            '20323200003230',
            '12010012',
        ];

        foreach ($cards as $number) {
            $validation = new Validation();
            $validation->add('creditCard', new CreditCard());

            $expected = Messages::__set_state(
                [
                    '_messages' => [
                        Message::__set_state(
                            [
                                '_type'    => 'CreditCard',
                                '_message' => 'Field creditCard is not valid for a credit card number',
                                '_field'   => 'creditCard',
                                '_code'    => '0',
                            ]
                        ),
                    ],
                ]
            );

            $actual = $validation->validate(['creditCard' => $number]);
            $I->assertEquals($expected, $actual);
        }
    }
}
