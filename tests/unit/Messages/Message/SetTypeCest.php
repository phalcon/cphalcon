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

class SetTypeCest
{
    /**
     * Tests Phalcon\Messages\Message :: setType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessageSetType(UnitTester $I)
    {
        $I->wantToTest("Messages\Message - setType()");
        $message = new Message('This is a message #1');
        $message->setType('MyType');

        $expected = 'MyType';
        $actual   = $message->getType();
        $I->assertEquals($expected, $actual);
    }
}
