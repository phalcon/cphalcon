<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Messages\Messages;

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use UnitTester;

class SetStateCest
{
    /**
     * Tests Phalcon\Messages\Messages :: __set_state()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testSetState(UnitTester $I)
    {
        $messages = Messages::__set_state(
            [
                '_position' => 0,
                '_messages' => [
                    0 => Message::__set_state(
                        [
                            '_message' => 'This is a message #1',
                            '_field'   => 'MyField1',
                            '_type'    => 'MyType1',
                            '_code'    => 111,
                        ]
                    ),
                    1 => Message::__set_state(
                        [
                            '_message' => 'This is a message #2',
                            '_field'   => 'MyField2',
                            '_type'    => 'MyType2',
                            '_code'    => 222,
                        ]
                    ),
                ],
            ]
        );

        $I->assertCount(2, $messages);

        $message = $messages[0];
        $expected = 'This is a message #1';
        $actual   = $message->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = 'MyField1';
        $actual   = $message->getField();
        $I->assertEquals($expected, $actual);

        $expected = 'MyType1';
        $actual   = $message->getType();
        $I->assertEquals($expected, $actual);

        $expected = 111;
        $actual   = $message->getCode();
        $I->assertEquals($expected, $actual);

        $message = $messages[1];
        $expected = 'This is a message #2';
        $actual   = $message->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = 'MyField2';
        $actual   = $message->getField();
        $I->assertEquals($expected, $actual);

        $expected = 'MyType2';
        $actual   = $message->getType();
        $I->assertEquals($expected, $actual);

        $expected = 222;
        $actual   = $message->getCode();
        $I->assertEquals($expected, $actual);
    }
}
