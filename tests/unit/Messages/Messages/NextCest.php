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

class NextCest
{
    /**
     * Tests Phalcon\Messages\Messages :: next()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testNext(UnitTester $I)
    {
        $messages = new Messages(
            [
                new Message('This is a message #1', 'MyField1', 'MyType1', 111),
                new Message('This is a message #2', 'MyField2', 'MyType2', 222),
            ]
        );

        $messages->next();

        $class  = Message::class;
        $actual = $messages->current();
        $I->assertInstanceOf($class, $actual);

        $expected = Message::__set_state(
            [
                '_message' => 'This is a message #2',
                '_field'   => 'MyField2',
                '_type'    => 'MyType2',
                '_code'    => 222,
            ]
        );
        $I->assertEquals($expected, $actual);
    }
}
