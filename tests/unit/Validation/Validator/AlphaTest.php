<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Alpha;

/**
 * \Phalcon\Test\Unit\Validation\Validator\Alpha
 * Tests the \Phalcon\Validation\Validator\Alpha component
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
class AlphaTest extends UnitTest
{
    /**
     * Tests alpha validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $validation = new Validation();
        $validation->add('name', new Alpha());
        $messages = $validation->validate(['name' => 'Asd']);
        expect($messages->count())->equals(0);
        $messages = $validation->validate(['name' => 'Asd123']);
        expect($messages->count())->equals(1);
    }

    /**
     * Tests alpha validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $validation = new Validation();
        $validationMessages = [
            'name' => 'Name must be alpha.',
            'type' => 'Type must by alpha.',
        ];
        $validation->add(['name', 'type'], new Alpha([
            'message' => $validationMessages,
        ]));
        $messages = $validation->validate(['name' => 'Asd', 'type' => 'Asd']);
        expect($messages->count())->equals(0);
        $messages = $validation->validate(['name' => 'Asd123', 'type' => 'Asd']);
        expect($messages->count())->equals(1);
        expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
        $messages = $validation->validate(['name' => 'Asd123', 'type' => 'Asd123']);
        expect($messages->count())->equals(2);
        expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['name']);
        expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['type']);
    }
}
