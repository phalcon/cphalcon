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

class AppendMessageCest
{
    /**
     * Tests Phalcon\Messages\Messages :: appendMessage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function messagesMessagesAppendMessage(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - appendMessage()');

        $messages = new Messages();

        $I->assertCount(0, $messages);

        $messages->appendMessage(
            new Message('error a', 'myField', 'MyValidator')
        );

        $I->assertCount(1, $messages);
    }
}
