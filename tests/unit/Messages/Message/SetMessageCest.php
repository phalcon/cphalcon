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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testSetMessage(UnitTester $I)
    {
        $message = new Message('This is a message #1');
        $message->setMessage('This is a message #2');

        $expected = 'This is a message #2';
        $actual   = $message->getMessage();
        $I->assertEquals($expected, $actual);
    }
}
