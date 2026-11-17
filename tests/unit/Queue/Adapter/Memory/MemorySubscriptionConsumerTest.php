<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Queue\Adapter\Memory;

use Phalcon\Queue\Adapter\Memory\MemoryConnectionFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Throwable;
use TypeError;

final class MemorySubscriptionConsumerTest extends AbstractUnitTestCase
{
    /**
     * A callback that cannot be called is accepted. consume() throws the
     * TypeError of call_user_func() and the message is no longer in the
     * queue, the same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testQueueMemorySubscribeNotCallable(): void
    {
        $context = (new MemoryConnectionFactory())->createContext();
        $queue   = $context->createQueue('subscribe');
        $context->createProducer()->send($queue, $context->createMessage('hello'));

        $consumer     = $context->createConsumer($queue);
        $subscription = $context->createSubscriptionConsumer();
        $subscription->subscribe($consumer, 'nope');

        $actual = null;
        try {
            $subscription->consume(100);
        } catch (Throwable $ex) {
            $actual = [$ex::class, $ex->getMessage()];
        }

        $this->assertSame(
            [
                TypeError::class,
                'call_user_func(): Argument #1 ($callback) must be a valid callback, '
                . 'function "nope" not found or invalid function name',
            ],
            $actual
        );
        $this->assertNull($consumer->receiveNoWait());
    }
}
