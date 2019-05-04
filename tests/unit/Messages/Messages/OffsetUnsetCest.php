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

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Messages\Messages :: offsetUnset()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-12
     */
    public function messagesMessagesOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - offsetUnset()');

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

        $I->assertCount(2, $messages);

        $messages->offsetUnset(0);

        $I->assertNull(
            $messages->offsetUnset(1)
        );

        /**
         * Unset discards the offset so we need to get 0 again
         */
        $message = $messages->offsetGet(0);

        $I->assertInstanceOf(
            Message::class,
            $message
        );



        $expected = Message::__set_state(
            [
                '_message'  => 'This is a message #2',
                '_field'    => 'MyField2',
                '_type'     => 'MyType2',
                '_code'     => 222,
                '_metaData' => [
                    'My2' => 'Metadata2',
                ],
            ]
        );

        $I->assertEquals($expected, $message);
    }
}
