<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Messages\Message;

use Phalcon\Messages\Message;
use UnitTester;

class ToStringCest
{
    /**
     * Tests Phalcon\Messages\Message :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessageToString(UnitTester $I): void
    {
        $I->wantToTest('Messages\Message - __toString()');

        $message = new Message(
            'This is a message #1',
            'MyField',
            'MyType',
            111
        );

        $expected = 'This is a message #1';
        $actual   = $message->__toString();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Messages\Message :: __toString() - cast
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessageToStringCast(UnitTester $I): void
    {
        $I->wantToTest('Messages\Message - __toString() - cast');

        $message = new Message(
            'This is a message #1',
            'MyField',
            'MyType',
            111
        );

        $expected = 'This is a message #1';
        $actual   = (string) $message;
        $I->assertEquals($expected, $actual);
    }
}
