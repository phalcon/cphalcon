<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\CreditCard;

/**
 * \Phalcon\Test\Unit\Validation\Validator\CreditCardTest
 * Tests the \Phalcon\Validation\Validator\CreditCard component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
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
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test credit card validator with single field.', function () {
            $validation = new Validation();
            $validation->add('creditCard', new CreditCard());
            $messages = $validation->validate(['creditCard' => 4601587377626131]);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['creditCard' => 46015873776261312]);
            expect($messages->count())->equals(1);
        });
    }

    /**
     * Tests credit card validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $this->specify('Test credit card validator with multiple field.', function () {
            $validation = new Validation();
            $validationMessages = [
                'creditCard' => 'CreditCard must be correct credit card value.',
                'anotherCreditCard' => 'AnotherCreditCard must be correct credit card value.',
            ];
            $validation->add(['creditCard', 'anotherCreditCard'], new CreditCard([
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['creditCard' => 4601587377626131, 'anotherCreditCard' => 4601587377626131]);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['creditCard' => 46015873776261312, 'anotherCreditCard' => 4601587377626131]);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['creditCard']);
            $messages = $validation->validate(['creditCard' => 46015873776261312, 'anotherCreditCard' => 46015873776261312]);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['creditCard']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherCreditCard']);
        });
    }
}
