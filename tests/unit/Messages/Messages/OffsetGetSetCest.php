<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Messages\Messages;

use Phalcon\Messages\Exception;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use UnitTester;

class OffsetGetSetCest
{
    /**
     * Tests Phalcon\Messages\Messages :: offsetGet()/offsetSet()
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2020-09-09
     * @author Phalcon Team <team@phalcon.io>
     */
    public function messagesMessagesOffsetGetSet(UnitTester $I): void
    {
        $I->wantToTest('Messages\Messages - offsetGet()/offsetSet()');

        $messages = new Messages(
            [
                0 => new Message(
                    'This is a message #1',
                    'MyField1',
                    'MyType1',
                    111,
                    [
                        'My1' => 'Metadata1',
                    ]
                ),
                1 => new Message(
                    'This is a message #2',
                    'MyField2',
                    'MyType2',
                    222,
                    [
                        'My2' => 'Metadata2',
                    ]
                ),
            ]
        );

        $messages->offsetSet(
            2,
            new Message(
                'This is a message #3',
                'MyField3',
                'MyType3',
                777,
                [
                    'My3' => 'Metadata3',
                ]
            )
        );
        $I->assertCount(3, $messages);

        $message = $messages->offsetGet(2);
        $I->assertInstanceOf(Message::class, $message);


        $I->assertEquals('This is a message #3', $message->getMessage());
        $I->assertEquals('MyField3', $message->getField());
        $I->assertEquals('MyType3', $message->getType());
        $I->assertEquals(777, $message->getCode());
        $I->assertEquals(['My3' => 'Metadata3'], $message->getMetaData());
    }

    /**
     * Tests Phalcon\Messages\Messages :: offsetSet() - exception
     *
     * @param UnitTester $I
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessagesOffsetSetException(UnitTester $I): void
    {
        $I->wantToTest('Messages\Messages - offsetSet() - exception');

        $I->expectThrowable(
            new Exception('The message must be an object'),
            function () {
                $messages = new Messages();

                $messages->offsetSet(2, 'message');
            }
        );
    }
}
