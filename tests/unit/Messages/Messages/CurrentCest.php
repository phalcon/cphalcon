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

class CurrentCest
{
    /**
     * Tests Phalcon\Messages\Messages :: current()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesCurrent(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - current()');

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

        $message = $messages->current();

        $I->assertInstanceOf(
            Message::class,
            $message
        );


        $I->assertEquals('This is a message #1', $message->getMessage());
        $I->assertEquals('MyField1', $message->getField());
        $I->assertEquals('MyType1', $message->getType());
        $I->assertEquals(111, $message->getCode());
        $I->assertEquals(['My1' => 'Metadata1'], $message->getMetaData());
    }
}
