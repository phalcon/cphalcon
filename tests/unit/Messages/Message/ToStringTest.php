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
use Phalcon\Tests\AbstractUnitTestCase;

final class ToStringTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testMessagesMessageToString(): void
    {
        $message = new Message(
            'This is a message #1',
            'MyField',
            'MyType',
            111
        );

        $expected = 'This is a message #1';
        $actual   = $message->__toString();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testMessagesMessageToStringCast(): void
    {
        $message = new Message(
            'This is a message #1',
            'MyField',
            'MyType',
            111
        );

        $expected = 'This is a message #1';
        $actual   = (string)$message;
        $this->assertSame($expected, $actual);
    }
}
