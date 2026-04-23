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
use Phalcon\Tests\AbstractUnitTestCase;

final class OffsetGetSetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testMessagesMessagesOffsetGetSet(): void
    {
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
        $this->assertCount(3, $messages);

        $message = $messages->offsetGet(2);
        $this->assertInstanceOf(Message::class, $message);


        $this->assertSame('This is a message #3', $message->getMessage());
        $this->assertSame('MyField3', $message->getField());
        $this->assertSame('MyType3', $message->getType());
        $this->assertSame(777, $message->getCode());
        $this->assertSame(['My3' => 'Metadata3'], $message->getMetaData());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testMessagesMessagesOffsetSetException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The message must be an object');

        $messages = new Messages();
        $messages->offsetSet(2, 'message');
    }
}
