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

class OffsetExistsCest
{
    /**
     * Tests Phalcon\Messages\Messages :: offsetExists()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessagesOffsetExists(UnitTester $I): void
    {
        $I->wantToTest('Messages\Messages - offsetExists()');

        $messages = new Messages(
            [
                1 => new Message(
                    'This is a message #1',
                    'MyField1',
                    'MyType1',
                    111
                ),
                2 => new Message(
                    'This is a message #2',
                    'MyField2',
                    'MyType2',
                    222
                ),
            ]
        );

        $I->assertFalse(
            $messages->offsetExists(0)
        );

        $I->assertTrue(
            $messages->offsetExists(1)
        );

        $I->assertTrue(
            $messages->offsetExists(2)
        );
    }
}
