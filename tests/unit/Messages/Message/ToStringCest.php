<?php
declare(strict_types=1);

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

/**
 * Class ToStringCest
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Messages\Message :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessageToString(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - __toString()');
        $message = new Message('This is a message #1', 'MyField', 'MyType', 111);

        $expected = 'This is a message #1';
        $actual   = $message->__toString();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Messages\Message :: __toString() - cast
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessageToStringCast(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - __toString() - cast');
        $message = new Message('This is a message #1', 'MyField', 'MyType', 111);

        $expected = 'This is a message #1';
        $actual   = (string) $message;
        $I->assertEquals($expected, $actual);
    }
}
