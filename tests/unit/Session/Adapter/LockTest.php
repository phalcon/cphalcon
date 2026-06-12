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

namespace Phalcon\Tests\Unit\Session\Adapter;

use Phalcon\Session\Adapter\Exceptions\AdapterRuntimeError;
use Phalcon\Session\Adapter\Redis;
use Phalcon\Storage\AdapterFactory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractServicesTestCase;

use function array_merge;
use function getOptionsRedis;
use function sleep;
use function uniqid;

final class LockTest extends AbstractServicesTestCase
{
    /**
     * A second adapter cannot read a locked session and throws after
     * exhausting its retries
     *
     * @issue  17126
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterRedisLockBlocksConcurrentRead(): void
    {
        $id      = uniqid('lock-');
        $lockKey = 'sess-reds-' . $id . '-lock';

        $adapterOne = $this->newRedisAdapter($this->getLockOptions());
        $adapterTwo = $this->newRedisAdapter($this->getLockOptions());

        $adapterOne->read($id);

        $caught = null;

        try {
            $adapterTwo->read($id);
        } catch (AdapterRuntimeError $exception) {
            $caught = $exception;
        }

        $this->assertInstanceOf(AdapterRuntimeError::class, $caught);

        $expected = 'Could not acquire the session lock with key: ' . $lockKey;
        $actual   = $caught->getMessage();
        $this->assertEquals($expected, $actual);

        $adapterOne->close();
        $this->sendRedisCommand('del', $lockKey);
    }

    /**
     * Releasing is token guarded: an adapter whose lock has expired must not
     * delete the lock acquired by another adapter in the meantime
     *
     * @issue  17126
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterRedisLockCloseKeepsForeignLock(): void
    {
        $id      = uniqid('lock-');
        $lockKey = 'sess-reds-' . $id . '-lock';

        $adapterOne = $this->newRedisAdapter($this->getLockOptions(1));
        $adapterTwo = $this->newRedisAdapter($this->getLockOptions(1));

        $adapterOne->read($id);
        $this->assertTrue($this->hasRedisKey($lockKey));

        sleep(2);

        $adapterTwo->read($id);
        $this->assertTrue($this->hasRedisKey($lockKey));

        $adapterOne->close();
        $this->assertTrue($this->hasRedisKey($lockKey));

        $adapterTwo->close();
        $this->assertTrue($this->doesNotHaveRedisKey($lockKey));
    }

    /**
     * Locking is opt-in: no lock key is created unless enabled
     *
     * @issue  17126
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterRedisLockDisabledByDefault(): void
    {
        $id      = uniqid('lock-');
        $lockKey = 'sess-reds-' . $id . '-lock';

        $adapter = $this->newRedisAdapter();

        $adapter->read($id);
        $this->assertTrue($this->doesNotHaveRedisKey($lockKey));

        $adapter->close();
    }

    /**
     * Reading acquires the lock and closing releases it
     *
     * @issue  17126
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterRedisLockReadAcquiresCloseReleases(): void
    {
        $id      = uniqid('lock-');
        $lockKey = 'sess-reds-' . $id . '-lock';

        $adapter = $this->newRedisAdapter($this->getLockOptions());

        $adapter->read($id);
        $this->assertTrue($this->hasRedisKey($lockKey));

        $adapter->close();
        $this->assertTrue($this->doesNotHaveRedisKey($lockKey));
    }

    /**
     * Destroying a session removes its data and releases the lock
     *
     * @issue  17126
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterRedisLockReleasedOnDestroy(): void
    {
        $id         = uniqid('lock-');
        $lockKey    = 'sess-reds-' . $id . '-lock';
        $sessionKey = 'sess-reds-' . $id;

        $adapter = $this->newRedisAdapter($this->getLockOptions());

        $adapter->read($id);
        $adapter->write($id, uniqid());
        $adapter->destroy($id);

        $this->assertTrue($this->doesNotHaveRedisKey($lockKey));
        $this->assertTrue($this->doesNotHaveRedisKey($sessionKey));
    }

    private function getLockOptions(int $expiry = 10): array
    {
        return [
            'lockingEnabled' => true,
            'lockExpiry'     => $expiry,
            'lockRetries'    => 2,
            'lockWaitTime'   => 1000,
        ];
    }

    private function newRedisAdapter(array $options = []): Redis
    {
        return new Redis(
            new AdapterFactory(new SerializerFactory()),
            array_merge(getOptionsRedis(), $options)
        );
    }
}
