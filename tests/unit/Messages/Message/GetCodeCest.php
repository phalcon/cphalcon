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

class GetCodeCest
{
    /**
     * Tests Phalcon\Messages\Message :: getCode()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessageGetCode(UnitTester $I)
    {
        $I->wantToTest("Messages\Message - getCode()");
        $message = new Message('This is a message #1', 'MyField', 'MyType', 111);

        $expected = 111;
        $actual   = $message->getCode();
        $I->assertEquals($expected, $actual);
    }
}
