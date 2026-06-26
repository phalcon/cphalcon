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
use Phalcon\Queue\Adapter\MessageEnvelope;
use Phalcon\Tests\AbstractUnitTestCase;

use function serialize;

final class MessageEnvelopeTest extends AbstractUnitTestCase
{
    public function testEncodeDecodeRoundTripPreservesBodyPropertiesHeaders(): void
    {
        $message = new MemoryMessage(
            'the-body',
            ['prop-key' => 'prop-value'],
            ['head-key' => 'head-value']
        );

        $decoded = MessageEnvelope::decode(MessageEnvelope::encode($message));

        $this->assertSame('the-body', $decoded['body']);
        $this->assertSame(['prop-key' => 'prop-value'], $decoded['properties']);
        $this->assertSame(['head-key' => 'head-value'], $decoded['headers']);
    }

    public function testDecodeReturnsNullForNonEnvelopePayload(): void
    {
        $this->assertNull(MessageEnvelope::decode(serialize('not-an-array')));
    }
}
