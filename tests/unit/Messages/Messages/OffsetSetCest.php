<?php
declare(strict_types=1);

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

/**
 * Class OffsetSetCest
 */
class OffsetSetCest
{
    /**
     * Tests Phalcon\Messages\Messages :: offsetSet()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesOffsetSet(UnitTester $I)
    {
        $I->wantToTest("Messages\Messages - offsetSet()");
        $messages = new Messages(
            [
                0 => new Message('This is a message #1', 'MyField1', 'MyType1', 111),
                1 => new Message('This is a message #2', 'MyField2', 'MyType2', 222),
            ]
        );

        $messages->offsetSet(
            2,
            new Message('This is a message #3', 'MyField3', 'MyType3', 777)
        );

        $expected = 3;
        $I->assertCount($expected, $messages);

        $message = $messages->offsetGet(2);
        $class   = Message::class;
        $actual  = $message;
        $I->assertInstanceOf($class, $actual);

        $expected = Message::__set_state(
            [
                '_message' => 'This is a message #3',
                '_field'   => 'MyField3',
                '_type'    => 'MyType3',
                '_code'    => 777,
            ]
        );
        $actual   = $message;
        $I->assertEquals($expected, $actual);
    }
}
