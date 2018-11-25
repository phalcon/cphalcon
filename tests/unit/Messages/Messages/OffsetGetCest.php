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

class OffsetGetCest
{
    /**
     * Tests Phalcon\Messages\Messages :: offsetGet()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesOffsetGet(UnitTester $I)
    {
        $I->wantToTest("Messages\Messages - offsetGet()");
        $messages = new Messages(
            [
                1 => new Message('This is a message #1', 'MyField1', 'MyType1', 111),
                2 => new Message('This is a message #2', 'MyField2', 'MyType2', 222),
            ]
        );

        $message = $messages->offsetGet(2);
        $class   = Message::class;
        $actual  = $message;
        $I->assertInstanceOf($class, $actual);

        $expected = Message::__set_state(
            [
                '_message' => 'This is a message #2',
                '_field'   => 'MyField2',
                '_type'    => 'MyType2',
                '_code'    => 222,
            ]
        );
        $actual   = $message;
        $I->assertEquals($expected, $actual);
    }
}
