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

class AppendMessagesCest
{
    /**
     * Tests Phalcon\Messages\Messages :: appendMessages() - array
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessagesAppendMessagesArray(UnitTester $I): void
    {
        $I->wantToTest('Messages\Messages - appendMessages()');

        $messages = new Messages();

        $messages->appendMessage(
            new Message(
                'This is a message #3',
                'MyField3',
                'MyType3',
                111
            )
        );

        $I->assertCount(1, $messages);

        $newMessages = new Messages();

        $newMessages->appendMessage(
            new Message(
                'This is a message #1',
                'MyField1',
                'MyType1',
                111
            )
        );

        $newMessages->appendMessage(
            new Message(
                'This is a message #2',
                'MyField2',
                'MyType2',
                222
            )
        );

        $I->assertCount(2, $newMessages);

        $messages->appendMessages($newMessages);

        $I->assertCount(3, $messages);

        /**
         * Array of messages
         */
        $arrayMessages = [
            new Message(
                'This is a message #10',
                'MyField10',
                'MyType10',
                1010
            ),
            new Message(
                'This is a message #11',
                'MyField11',
                'MyType11',
                1111
            ),
            new Message(
                'This is a message #12',
                'MyField12',
                'MyType12',
                1212
            ),
        ];

        $messages->appendMessages($arrayMessages);
        $I->assertCount(6, $messages);
    }

    /**
     * Tests Phalcon\Messages\Messages :: appendMessages() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessagesAppendMessagesException(UnitTester $I): void
    {
        $I->wantToTest('Messages\Messages - appendMessage() - exception');

        $I->expectThrowable(
            new Exception('The messages must be iterable'),
            function () {
                (new Messages())->appendMessages(true);
            }
        );
    }
}
