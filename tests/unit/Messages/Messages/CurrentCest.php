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

class CurrentCest
{
    /**
     * Tests Phalcon\Messages\Messages :: current()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesCurrent(UnitTester $I)
    {
        $I->wantToTest("Messages\Messages - current()");
        $messages = new Messages(
            [
                new Message('This is a message #1', 'MyField1', 'MyType1', 111),
                new Message('This is a message #2', 'MyField2', 'MyType2', 222),
            ]
        );

        $class  = Message::class;
        $actual = $messages->current();
        $I->assertInstanceOf($class, $actual);

        $expected = Message::__set_state(
            [
                '_message' => 'This is a message #1',
                '_field'   => 'MyField1',
                '_type'    => 'MyType1',
                '_code'    => 111,
            ]
        );
        $I->assertEquals($expected, $actual);
    }
}
