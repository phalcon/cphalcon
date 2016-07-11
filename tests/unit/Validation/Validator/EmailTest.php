<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Email;

/**
 * \Phalcon\Test\Unit\Validation\Validator\EmailTest
 * Tests the \Phalcon\Validation\Validator\Email component
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
class EmailTest extends UnitTest
{
    /**
     * Tests email validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test email validator with single field.', function () {
            $validation = new Validation();
            $validation->add('email', new Email());
            $messages = $validation->validate(['email' => 'test@somemail.com']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['email' => 'rootlocalhost']);
            expect($messages->count())->equals(1);
        });
    }

    /**
     * Tests email validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $this->specify('Test email validator with multiple field.', function () {
            $validation = new Validation();
            $validationMessages = [
                'email' => 'Email must be correct email.',
                'anotherEmail' => 'AnotherEmail must be correct email.',
            ];
            $validation->add(['email', 'anotherEmail'], new Email([
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['email' => 'test@somemail.com', 'anotherEmail' => 'test@somemail.com']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['email' => 'rootlocalhost', 'anotherEmail' => 'test@somemail.com']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['email']);
            $messages = $validation->validate(['email' => 'rootlocalhost', 'anotherEmail' => 'rootlocalhost']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['email']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherEmail']);
        });
    }
}
