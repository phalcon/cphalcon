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
use UnitTester;

class RewindCest
{
    /**
     * Tests Phalcon\Messages\Messages :: rewind()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessagesRewind(UnitTester $I): void
    {
        $I->wantToTest('Messages\Messages - rewind()');

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

        $I->assertInstanceOf(
            Message::class,
            $actual
        );

        $I->assertEquals(
            'This is a message #2',
            $actual->__toString()
        );

        $messages->rewind();

        $actual = $messages->current();

        $I->assertInstanceOf(
            Message::class,
            $actual
        );

        $I->assertEquals('This is a message #1', $actual->getMessage());
        $I->assertEquals('MyField1', $actual->getField());
        $I->assertEquals('MyType1', $actual->getType());
        $I->assertEquals(111, $actual->getCode());
        $I->assertEquals(['My1' => 'Metadata1'], $actual->getMetaData());
    }
}
