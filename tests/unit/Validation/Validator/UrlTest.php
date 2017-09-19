<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;

/**
 * \Phalcon\Test\Unit\Validation\Validator\UrlTest
 * Tests the \Phalcon\Validation\Validator\Url component
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
class UrlTest extends UnitTest
{
    /**
     * Tests url validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test url validator with single field.', function () {
            $validation = new Validation();

            $validation->add('url', new Validation\Validator\Url());

            $messages = $validation->validate([]);

            $expectedMessages = Validation\Message\Group::__set_state(
                [
                    '_messages' => [
                        0 => Validation\Message::__set_state(
                            [
                                '_type'    => 'Url',
                                '_message' => 'Field url must be a url',
                                '_field'   => 'url',
                                '_code'    => 0,
                            ]
                        )
                    ]
                ]
            );

            expect($expectedMessages)->equals($messages);

            $messages = $validation->validate(['url' => 'x=1']);
            expect($expectedMessages)->equals($messages);

            $messages = $validation->validate(['url' => 'http://phalconphp.com']);
            expect($messages)->count(0);
        });
    }

    /**
     * Tests url validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $this->specify('Test url validator with multiple field.', function () {
            $validation = new Validation();
            $validationMessages = [
                'url' => 'Url must be correct url.',
                'anotherUrl' => 'AnotherUrl must be correct url.',
            ];
            $validation->add(['url', 'anotherUrl'], new Validation\Validator\Url([
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['url' => 'http://google.com', 'anotherUrl' => 'http://google.com']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['url' => '://google.', 'anotherUrl' => 'http://google.com']);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['url']);
            $messages = $validation->validate(['url' => '://google.', 'anotherUrl' => '://google.']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['url']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['anotherUrl']);
        });
    }

    public function testCustomMessage()
    {
        $this->specify(
            'Test URL validator works with a custom message.',
            function () {
                $validation = new Validation();

                $validation->add(
                    'url',
                    new Validation\Validator\Url(
                        [
                            'message' => 'The url is not valid'
                        ]
                    )
                );

                $messages = $validation->validate([]);

                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'Url',
                                    '_message' => 'The url is not valid',
                                    '_field'   => 'url',
                                    '_code'    => '0',
                                ]
                            )
                        ]
                    ]
                );

                expect($expectedMessages)->equals($messages);

                $messages = $validation->validate(['url' => 'x=1']);
                expect($expectedMessages)->equals($messages);

                $messages = $validation->validate(['url' => 'http://phalconphp.com']);
                expect($messages)->count(0);
            }
        );
    }
}
