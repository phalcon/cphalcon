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
 * Class OffsetExistsCest
 */
class OffsetExistsCest
{
    /**
     * Tests Phalcon\Messages\Messages :: offsetExists()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesOffsetExists(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - offsetExists()');
        $messages = new Messages(
            [
                1 => new Message('This is a message #1', 'MyField1', 'MyType1', 111),
                2 => new Message('This is a message #2', 'MyField2', 'MyType2', 222),
            ]
        );

        $actual = $messages->offsetExists(0);
        $I->assertFalse($actual);

        $actual = $messages->offsetExists(1);
        $I->assertTrue($actual);

        $actual = $messages->offsetExists(2);
        $I->assertTrue($actual);
    }
}
