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

namespace Phalcon\Test\Unit\Messages\Message;

use Phalcon\Messages\Message;
use UnitTester;

/**
 * Class GetSetMessageCest
 */
class GetSetMessageCest
{
    /**
     * Tests Phalcon\Messages\Message :: getMessage()/setMessage()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessageGetSetMessage(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - getMessage()/setMessage()');

        $expected = 'This is a message #1';
        $message  = new Message($expected);
        $actual   = $message->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = 'This is a message #2';
        $message->setMessage($expected);
        $actual = $message->getMessage();
        $I->assertEquals($expected, $actual);
    }
}
