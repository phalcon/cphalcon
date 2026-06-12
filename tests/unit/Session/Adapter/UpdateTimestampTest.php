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

use Phalcon\Tests\AbstractServicesTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function cacheDir;
use function clearstatcache;
use function filemtime;
use function time;
use function touch;
use function uniqid;

final class UpdateTimestampTest extends AbstractServicesTestCase
{
    use DiTrait;

    /**
     * @issue  17129
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterLibmemcachedUpdateTimestamp(): void
    {
        $adapter = $this->newService('sessionLibmemcached');

        $value = uniqid();
        $adapter->write('test1', $value);

        $actual = $adapter->updateTimestamp('test1', $value);
        $this->assertTrue($actual);

        $actual = $adapter->read('test1');
        $this->assertEquals($value, $actual);

        $adapter->destroy('test1');
    }

    /**
     * @issue  17129
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterNoopUpdateTimestamp(): void
    {
        $adapter = $this->newService('sessionNoop');

        $actual = $adapter->updateTimestamp('test1', uniqid());
        $this->assertTrue($actual);
    }

    /**
     * @issue  17129
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterRedisUpdateTimestamp(): void
    {
        $adapter = $this->newService('sessionRedis');

        $value = uniqid();
        $adapter->write('test1', $value);

        $actual = $adapter->updateTimestamp('test1', $value);
        $this->assertTrue($actual);

        $actual = $adapter->read('test1');
        $this->assertEquals($value, $actual);

        $adapter->destroy('test1');
    }

    /**
     * Updating the timestamp must refresh the file modification time without
     * changing the session data
     *
     * @issue  17129
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterStreamUpdateTimestamp(): void
    {
        $adapter = $this->newService('sessionStream');

        $value = uniqid();
        $adapter->write('test1', $value);

        $file = cacheDir('sessions/test1');
        touch($file, time() - 100);
        clearstatcache();

        $actual = $adapter->updateTimestamp('test1', $value);
        $this->assertTrue($actual);

        clearstatcache();
        $this->assertGreaterThan(time() - 10, filemtime($file));

        $this->assertFileContentsContains($file, $value);
        $this->safeDeleteFile($file);
    }
}
