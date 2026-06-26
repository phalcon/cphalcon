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

namespace Phalcon\Tests\Unit\Queue\Adapter;

use Phalcon\Queue\Adapter\Memory\MemoryMessage;
use Phalcon\Tests\AbstractUnitTestCase;

final class AbstractMessageTest extends AbstractUnitTestCase
{
    public function testConvenienceHeaderAccessorsRoundTrip(): void
    {
        $message = new MemoryMessage();

        $message->setCorrelationId('corr-1');
        $message->setMessageId('msg-1');
        $message->setReplyTo('reply-queue');
        $message->setTimestamp(1234567890);

        $this->assertSame('corr-1', $message->getCorrelationId());
        $this->assertSame('msg-1', $message->getMessageId());
        $this->assertSame('reply-queue', $message->getReplyTo());
        $this->assertSame(1234567890, $message->getTimestamp());
    }

    public function testTimestampNullWhenUnsetAndCastToIntWhenStringy(): void
    {
        $message = new MemoryMessage();
        $this->assertNull($message->getTimestamp());

        // a stringy header value is coerced to int
        $message->setHeader('timestamp', '99');
        $this->assertSame(99, $message->getTimestamp());
    }
}
