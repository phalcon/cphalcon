<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation\Validator\Digit;

/**
 * \Phalcon\Test\Unit\Validation\Validator\DigitTest
 * Tests the \Phalcon\Validation\Validator\Digit component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
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
class DigitTest extends UnitTest
{
    /**
     * Tests digit validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify(
            'The Digit Validator does not validate correctly',
            function () {
                $validation = new Validation();
                $validation->add('amount', new Digit());

                $messages = $validation->validate(['amount' => '123']);
                expect($messages->count())->equals(0);

                $messages = $validation->validate(['amount' => '123abc']);
                expect($messages->count())->equals(1);
            }
        );
    }

    /**
     * Tests digit validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $this->specify(
            'The Digit Validator does not validate multiple field',
            function () {
                $validation = new Validation();
                $validationMessages = [
                    'amount' => 'Amount must be digit.',
                    'price' => 'Price must be digit.',
                ];
                $validation->add(['amount', 'price'], new Digit([
                    'message' => $validationMessages,
                ]));

                $messages = $validation->validate(['amount' => '123', 'price' => '123']);
                expect($messages->count())->equals(0);

                $messages = $validation->validate(['amount' => '123abc', 'price' => '123']);
                expect($messages->count())->equals(1);
                expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['amount']);

                $messages = $validation->validate(['amount' => '123abc', 'price' => '123abc']);
                expect($messages->count())->equals(2);
                expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['amount']);
                expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['price']);
            }
        );
    }

    public function testShouldValidateIntOrStringOfDigits()
    {
        $this->specify(
            'The Digit Validator does not validate digits correctly',
            function ($digit) {
                $validation = new Validation();
                $validation->add('amount', new Digit());

                $messages = $validation->validate(['amount' => $digit]);

                expect($messages)->count(0);
            },
            [
                'examples' => [
                    ['123'],
                    [123],
                    [PHP_INT_MAX],
                    [0xFFFFFF],
                    [100000],
                    [-100000],
                    [0],
                    ["0"],
                    ["00001233422003400"],
                ]
            ]
        );
    }
}
