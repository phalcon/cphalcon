<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Messages;

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use UnitTester;

class MessagesCest
{
    /**
     * Tests append messages
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-12
     */
    public function validationGroup(UnitTester $I)
    {
        $message1 = new Message('This a message #1', 'field1', 'Type1');
        $message2 = new Message('This a message #2', 'field2', 'Type2');
        $message3 = new Message('This a message #3', 'field3', 'Type3');

        $messages = new Messages([$message1, $message2]);

        $expected = 2;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $actual = isset($messages[0]);
        $I->assertTrue($actual);

        $actual = isset($messages[1]);
        $I->assertTrue($actual);

        $expected = $message1;
        $actual   = $messages[0];
        $I->assertEquals($expected, $actual);

        $expected = $message2;
        $actual   = $messages[1];
        $I->assertEquals($expected, $actual);

        $messages->appendMessage($message3);

        $expected = $message3;
        $actual   = $messages[2];
        $I->assertEquals($expected, $actual);

        $expected = 3;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        foreach ($messages as $position => $message) {
            $expected = $messages[$position]->getMessage();
            $actual   = $message->getMessage();
            $I->assertEquals($expected, $actual);

            $expected = $messages[$position]->getField();
            $actual   = $message->getField();
            $I->assertEquals($expected, $actual);

            $expected = $messages[$position]->getType();
            $actual   = $message->getType();
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests unsetting a message by index
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12455
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-12
     */
    public function unsettingByIndex(UnitTester $I)
    {
        $validation = new Validation();
        $validation->appendMessage(new Message('error a', 'myField', 'MyValidator'));

        $messages = $validation->getMessages();

        $expected = 1;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $expected = Message::__set_state(
            [
                '_message' => 'error a',
                '_field'   => 'myField',
                '_type'    => 'MyValidator',
                '_code'    => 0,
            ]
        );
        $actual   = $messages[0];
        $I->assertEquals($expected, $actual);


        $validation->appendMessage(new Message('error b', 'myField', 'MyValidator'));

        $messages = $validation->getMessages();

        $expected = 2;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $expected = Message::__set_state(
            [
                '_message' => 'error b',
                '_field'   => 'myField',
                '_type'    => 'MyValidator',
                '_code'    => 0,
            ]
        );
        $actual   = $messages[1];
        $I->assertEquals($expected, $actual);


        unset($messages[count($messages) - 1]);

        $expected = 1;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $expected = Message::__set_state(
            [
                '_message' => 'error a',
                '_field'   => 'myField',
                '_type'    => 'MyValidator',
                '_code'    => 0,
            ]
        );
        $actual   = $messages[0];
        $I->assertEquals($expected, $actual);

        $validation->appendMessage(new Message('error c', 'myField', 'MyValidator'));

        $expected = 2;
        $actual   = count($messages);
        $I->assertEquals($expected, $actual);

        $expected = Message::__set_state(
            [
                '_message' => 'error c',
                '_field'   => 'myField',
                '_type'    => 'MyValidator',
                '_code'    => 0,
            ]
        );
        $actual   = $messages[1];
        $I->assertEquals($expected, $actual);

        $expected = Messages::__set_state(
            [
                '_position' => 0,
                '_messages' => [
                    0 => Message::__set_state(
                        [
                            '_message' => 'error a',
                            '_field'   => 'myField',
                            '_type'    => 'MyValidator',
                            '_code'    => 0,
                        ]
                    ),
                    1 => Message::__set_state(
                        [
                            '_message' => 'error c',
                            '_field'   => 'myField',
                            '_type'    => 'MyValidator',
                            '_code'    => 0,
                        ]
                    ),
                ],
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $validation->appendMessage(new Message('error d', 'myField', 'MyValidator'));
        $validation->appendMessage(new Message('error e', 'myField', 'MyValidator'));

        $messages = $validation->getMessages();
        $messages->offsetUnset(1);

        $expected = Messages::__set_state(
            [
                '_position' => 0,
                '_messages' => [
                    0 => Message::__set_state(
                        [
                            '_message' => 'error a',
                            '_field'   => 'myField',
                            '_type'    => 'MyValidator',
                            '_code'    => 0,
                        ]
                    ),
                    1 => Message::__set_state(
                        [
                            '_message' => 'error d',
                            '_field'   => 'myField',
                            '_type'    => 'MyValidator',
                            '_code'    => 0,
                        ]
                    ),
                    2 => Message::__set_state(
                        [
                            '_message' => 'error e',
                            '_field'   => 'myField',
                            '_type'    => 'MyValidator',
                            '_code'    => 0,
                        ]
                    ),
                ],
            ]
        );
        $actual   = $validation->getMessages();
        $I->assertEquals($expected, $actual);
    }

}
