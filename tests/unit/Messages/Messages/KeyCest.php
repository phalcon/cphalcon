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
 * Class KeyCest
 */
class KeyCest
{
    /**
     * Tests Phalcon\Messages\Messages :: key()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesKey(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - key()');
        $messages = new Messages(
            [
                0 => new Message('This is a message #1', 'MyField1', 'MyType1', 111),
                1 => new Message('This is a message #2', 'MyField2', 'MyType2', 222),
            ]
        );

        $messages->next();

        $expected = 1;
        $actual   = $messages->key();
        $I->assertEquals($expected, $actual);
    }
}
