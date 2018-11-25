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

class GetTypeCest
{
    /**
     * Tests Phalcon\Messages\Message :: getType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessageGetType(UnitTester $I)
    {
        $I->wantToTest("Messages\Message - getType()");
        $message = new Message('This is a message #1', 'MyField', 'MyType', 111);

        $expected = 'MyType';
        $actual   = $message->getType();
        $I->assertEquals($expected, $actual);
    }
}
