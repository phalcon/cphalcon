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

class ConstructCest
{
    /**
     * Tests Phalcon\Messages\Message :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessageConstruct(UnitTester $I)
    {
        $I->wantToTest("Messages\Message - __construct()");
        $message = new Message('This is a message #1', 'MyField', 'MyType', 111);

        $expected = 'This is a message #1';
        $actual   = $message->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = 'MyField';
        $actual   = $message->getField();
        $I->assertEquals($expected, $actual);

        $expected = 'MyType';
        $actual   = $message->getType();
        $I->assertEquals($expected, $actual);

        $expected = 111;
        $actual   = $message->getCode();
        $I->assertEquals($expected, $actual);
    }
}
