<?php

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

class ValidCest
{
    /**
     * Tests Phalcon\Messages\Messages :: valid()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testValid(UnitTester $I)
    {
        $messages = new Messages(
            [
                new Message('This is a message #1', 'MyField1', 'MyType1', 111),
                new Message('This is a message #2', 'MyField2', 'MyType2', 222),
            ]
        );

        $messages->rewind();

        $actual = $messages->valid();
        $I->assertTrue($actual);

        $messages->next();
        $actual = $messages->valid();
        $I->assertTrue($actual);

        $messages->next();
        $actual = $messages->valid();
        $I->assertFalse($actual);
    }
}
