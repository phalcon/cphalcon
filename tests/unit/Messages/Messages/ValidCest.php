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

namespace Phalcon\Test\Unit\Messages\Messages;

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use UnitTester;

class ValidCest
{
    /**
     * Tests Phalcon\Messages\Messages :: valid()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function messagesMessagesValid(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - valid()');

        $messages = new Messages(
            [
                new Message('This is a message #1', 'MyField1', 'MyType1', 111),
                new Message('This is a message #2', 'MyField2', 'MyType2', 222),
            ]
        );


        $messages->rewind();

        $I->assertTrue(
            $messages->valid()
        );


        $messages->next();

        $I->assertTrue(
            $messages->valid()
        );


        $messages->next();

        $I->assertFalse(
            $messages->valid()
        );
    }
}
