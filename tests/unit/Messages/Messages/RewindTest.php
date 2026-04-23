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

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;

final class RewindTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testMessagesMessagesRewind(): void
    {
        $messages = new Messages(
            [
                new Message(
                    'This is a message #1',
                    'MyField1',
                    'MyType1',
                    111,
                    [
                        'My1' => 'Metadata1',
                    ]
                ),
                new Message(
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

        $messages->next();

        $actual = $messages->current();

        $this->assertInstanceOf(
            Message::class,
            $actual
        );

        $this->assertSame(
            'This is a message #2',
            $actual->__toString()
        );

        $messages->rewind();

        $actual = $messages->current();

        $this->assertInstanceOf(
            Message::class,
            $actual
        );

        $this->assertSame('This is a message #1', $actual->getMessage());
        $this->assertSame('MyField1', $actual->getField());
        $this->assertSame('MyType1', $actual->getType());
        $this->assertSame(111, $actual->getCode());
        $this->assertSame(['My1' => 'Metadata1'], $actual->getMetaData());
    }
}
