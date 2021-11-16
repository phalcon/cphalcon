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

class NextCest
{
    /**
     * Tests Phalcon\Messages\Messages :: next()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessagesNext(UnitTester $I): void
    {
        $I->wantToTest('Messages\Messages - next()');

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

        $message = $messages->current();

        $I->assertInstanceOf(
            Message::class,
            $message
        );


        $I->assertEquals('This is a message #2', $message->getMessage());
        $I->assertEquals('MyField2', $message->getField());
        $I->assertEquals('MyType2', $message->getType());
        $I->assertEquals(222, $message->getCode());
        $I->assertEquals(['My2' => 'Metadata2'], $message->getMetaData());
    }
}
