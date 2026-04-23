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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\CreditCard;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\CreditCard;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorCreditCardValidateEmpty(): void
    {
        $validation = new Validation();
        $validator  = new CreditCard(['allowEmpty' => true,]);
        $validation->add('creditCard', $validator);
        $entity             = new stdClass();
        $entity->creditCard = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'creditCard');
        $this->assertTrue($result);
    }

    /**
     * @author Caio Almeida <caio.f.r.amd@gmail.com>
     * @since  2015-09-06
     */
    public function testFilterValidationValidatorCreditCardValidateInvalidCreditCard(): void
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

            $validation->add(
                'creditCard',
                new CreditCard()
            );


            $expected = new Messages(
                [
                    new Message(
                        'Field creditCard is not valid for a credit card number',
                        'creditCard',
                        CreditCard::class,
                        0
                    ),
                ]
            );

            $actual = $validation->validate(
                [
                    'creditCard' => $number,
                ]
            );

            $this->assertEquals($expected, $actual);
        }
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorCreditCardValidateMultipleFields(): void
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

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'creditCard'        => 46015873776261312,
                'anotherCreditCard' => 4601587377626131,
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );


        $this->assertSame(
            $validationMessages['creditCard'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'creditCard'        => 46015873776261312,
                'anotherCreditCard' => 46015873776261312,
            ]
        );

        $this->assertSame(
            2,
            $messages->count()
        );


        $this->assertSame(
            $validationMessages['creditCard'],
            $messages->offsetGet(0)->getMessage()
        );


        $this->assertSame(
            $validationMessages['anotherCreditCard'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorCreditCardValidateSingleField(): void
    {
        $validation = new Validation();

        $validation->add('creditCard', new CreditCard());

        $expected = 0;
        $actual   = $validation->validate(
            [
                'creditCard' => 4601587377626131,
            ]
        );
        $this->assertCount($expected, $actual);

        $expected = 1;
        $actual   = $validation->validate(
            [
                'creditCard' => 46015873776261312,
            ]
        );
        $this->assertCount($expected, $actual);
    }

    /**
     * @author Caio Almeida <caio.f.r.amd@gmail.com>
     * @since  2015-09-06
     */
    public function testFilterValidationValidatorCreditCardValidateValidCreditCard(): void
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

            $validation->add(
                'creditCard',
                new CreditCard()
            );

            $this->assertCount(
                0,
                $validation->validate(
                    [
                        'creditCard' => $number,
                    ]
                )
            );
        }
    }
}
