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

namespace Phalcon\Test\Unit\Messages\Message;

use Phalcon\Messages\Message;
use UnitTester;

class GetSetMessageCest
{
    /**
     * Tests Phalcon\Messages\Message :: getMessage()/setMessage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function messagesMessageGetSetMessage(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - getMessage()/setMessage()');


        $expected = 'This is a message #1';

        $message = new Message($expected);

        $I->assertEquals(
            $expected,
            $message->getMessage()
        );


        $expected = 'This is a message #2';

        $message->setMessage($expected);

        $I->assertEquals(
            $expected,
            $message->getMessage()
        );
    }
}
