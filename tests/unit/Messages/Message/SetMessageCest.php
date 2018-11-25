<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Messages\Message;

use Phalcon\Messages\Message;
use UnitTester;

class SetMessageCest
{
    /**
     * Tests Phalcon\Messages\Message :: setMessage()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessageSetMessage(UnitTester $I)
    {
        $I->wantToTest("Messages\Message - setMessage()");
        $message = new Message('This is a message #1');
        $message->setMessage('This is a message #2');

        $expected = 'This is a message #2';
        $actual   = $message->getMessage();
        $I->assertEquals($expected, $actual);
    }
}
