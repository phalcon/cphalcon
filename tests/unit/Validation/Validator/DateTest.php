<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Date;

/**
 * \Phalcon\Test\Unit\Validation\Validator\DateTest
 * Tests the \Phalcon\Validation\Validator\Date component
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
            $messages = $validation->validate(['date' => '2016-06-05']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['date' => '2016-06-32']);
            expect($messages->count())->equals(1);
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
        $this->specify('Test date validator with multiple field.', function() {
           $validation = new Validation();
            $validationMessages = [
                'date'=>'Date must be correct date formay Y-m-d.',
                'anotherDate'=>'AnotherDate must be correct date format d-m-Y.'
            ];
            $validation->add(['date','anotherDate'], new Date([
                'format'=>[
                    'date'=>'Y-m-d',
                    'anotherDate'=>'d-m-Y'
                ],
                'message'=>$validationMessages
            ]));
            $messages = $validation->validate(['date' => '2016-06-05', 'anotherDate' => '05-06-2016']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['date' => '2016-06-32', 'anotherDate' => '05-06-2016']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['date']);
            $messages = $validation->validate(['date' => '2016-06-32', 'anotherDate' => '32-06-2016']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['date']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherDate']);
        });
    }
}
