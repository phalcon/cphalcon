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

class SetCodeCest
{
    /**
     * Tests Phalcon\Messages\Message :: setCode()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessageSetCode(UnitTester $I)
    {
        $I->wantToTest("Messages\Message - setCode()");
        $message = new Message('This is a message #1');
        $message->setCode(111);

        $expected = 111;
        $actual   = $message->getCode();
        $I->assertEquals($expected, $actual);
    }
}
