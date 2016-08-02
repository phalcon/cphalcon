<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\InclusionIn;

/**
 * \Phalcon\Test\Unit\Validation\Validator\InclusionInTest
 * Tests the \Phalcon\Validation\Validator\InclusionIn component
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
class InclusionInTest extends UnitTest
{
    /**
     * Tests inclusion in validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test inclusion in validator with single field.', function () {
            $validation = new Validation();
            $validation->add('type', new InclusionIn([
                'domain' => ['mechanical', 'cyborg'],
            ]));
            $messages = $validation->validate(['type' => 'cyborg']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['type' => 'hydraulic']);
            expect($messages->count())->equals(1);
        });
    }

    /**
     * Tests inclusion in validator with single multiple field and single domain
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldSingleDomain()
    {
        $this->specify('Test inclusion in validator with multiple field and single domain.', function () {
            $validation = new Validation();
            $validationMessages = [
                'type' => 'Type must be mechanical or cyborg.',
                'anotherType' => 'AnotherType must be mechanical or cyborg.',
            ];
            $validation->add(['type', 'anotherType'], new InclusionIn([
                'domain' => ['mechanical', 'cyborg'],
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'cyborg']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'cyborg']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['type']);
            $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'hydraulic']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['type']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherType']);
        });
    }

    /**
     * Tests inclusion in validator with single multiple field and domain
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleFieldMultipleDomain()
    {
        $this->specify('Test inclusion in validator with multiple field domain.', function () {
            $validation = new Validation();
            $validationMessages = [
                'type' => 'Type must be mechanic or cyborg.',
                'anotherType' => 'AnotherType must be mechanic or hydraulic.',
            ];
            $validation->add(['type', 'anotherType'], new InclusionIn([
                'domain' => [
                    'type' => ['cyborg', 'mechanic'],
                    'anotherType' => ['mechanic', 'hydraulic'],
                ],
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['type' => 'cyborg', 'anotherType' => 'mechanic']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'mechanic']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['type']);
            $messages = $validation->validate(['type' => 'mechanic', 'anotherType' => 'cyborg']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['anotherType']);
            $messages = $validation->validate(['type' => 'hydraulic', 'anotherType' => 'cyborg']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['type']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherType']);
        });
    }
}
