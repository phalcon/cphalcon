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
use TypeError;
use UnitTester;

/**
 * Class AppendMessagesCest
 */
class AppendMessagesCest
{
    /**
     * Tests Phalcon\Messages\Messages :: appendMessages() - array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesAppendMessagesArray(UnitTester $I)
    {
        $I->wantToTest("Messages\Messages - appendMessages()");
        $messages = new Messages();
        $messages->appendMessage(new Message('This is a message #3', 'MyField3', 'MyType3', 111));
        $I->assertCount(1, $messages);

        $newMessages = new Messages();
        $newMessages->appendMessage(new Message('This is a message #1', 'MyField1', 'MyType1', 111));
        $newMessages->appendMessage(new Message('This is a message #2', 'MyField2', 'MyType2', 222));
        $I->assertCount(2, $newMessages);

        $messages->appendMessages($newMessages);
        $I->assertCount(3, $messages);
    }

    /**
     * Tests Phalcon\Messages\Messages :: __construct() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesConstructException(UnitTester $I)
    {
        $I->wantToTest("Messages\Messages - appendMessages() - exception");
        $I->expectThrowable(
            new TypeError(
                'Argument 1 passed to Phalcon\Messages\Messages::appendMessage() ' .
                'must implement interface Phalcon\Messages\MessageInterface, boolean given'
            ),
            function () {
                (new Messages())->appendMessage(true);
            }
        );
    }
}
