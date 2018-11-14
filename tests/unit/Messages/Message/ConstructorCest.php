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

class ConstructorCest
{
    /**
     * Tests Phalcon\Messages\Message :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testConstructor(UnitTester $I)
    {
        $message = new Message('This is a message #1', 'MyField', 'MyType', 123);

        $expected = 'This is a message #1';
        $actual   = $message->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = 'MyField';
        $actual   = $message->getField();
        $I->assertEquals($expected, $actual);

        $expected = 'MyType';
        $actual   = $message->getType();
        $I->assertEquals($expected, $actual);

        $expected = 123;
        $actual   = $message->getCode();
        $I->assertEquals($expected, $actual);
    }
}
