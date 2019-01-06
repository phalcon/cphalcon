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
 * Class AppendMessageCest
 */
class AppendMessageCest
{
    /**
     * Tests Phalcon\Messages\Messages :: appendMessage()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesAppendMessage(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - appendMessage()');
        $messages = new Messages();
        $I->assertCount(0, $messages);

        $messages->appendMessage(new Message('error a', 'myField', 'MyValidator'));

        $I->assertCount(1, $messages);
    }
}
