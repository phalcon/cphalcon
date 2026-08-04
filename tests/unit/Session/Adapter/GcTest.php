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

use Phalcon\Session\Exception;
use Phalcon\Talon\PHPUnit\AbstractServicesTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Session\Fake\FakeStreamGlob;

use function file_put_contents;
use function Phalcon\Tests\Support\Traits\getOptionsSessionStream;
use function sleep;
use function time;
use function touch;
use function uniqid;

final class GcTest extends AbstractServicesTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterLibmemcachedGc(): void
    {
        $adapter = $this->newService('sessionLibmemcached');

        /**
         * Add two session keys
         */
        $this->setMemcachedKey('sess-memc-gc_1', uniqid(), 1);
        $this->setMemcachedKey('sess-memc-gc_2', uniqid(), 1);
        /**
         * Sleep to make sure that the time expired
         */
        sleep(2);
        $actual = $adapter->gc(1);
        $this->assertNotFalse($actual);
        $this->assertTrue($this->doesNotHaveMemcachedKey('sess-memc-gc_1'));
        $this->assertTrue($this->doesNotHaveMemcachedKey('sess-memc-gc_2'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterNoopGc(): void
    {
        $adapter = $this->newService('sessionNoop');

        $actual = $adapter->gc(1);
        $this->assertNotFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterRedisGc(): void
    {
        $adapter = $this->newService('sessionRedis');

        $actual = $adapter->gc(1);
        $this->assertNotFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterStreamGc(): void
    {
        $adapter = $this->newService('sessionStream');

        $fileOne = Talon::settings()->outputPath('tests/cache/sessions/gc_1');
        $fileTwo = Talon::settings()->outputPath('tests/cache/sessions/gc_2');

        /**
         * Add two session files
         */
        $actual = file_put_contents($fileOne, uniqid());
        $this->assertNotFalse($actual);

        $actual = file_put_contents($fileTwo, uniqid());
        $this->assertNotFalse($actual);

        /**
         * `gc()` collects on `filemtime()`, so backdating the files expires
         * them with nothing to wait for
         */
        $this->assertTrue(touch($fileOne, time() - 100));
        $this->assertTrue(touch($fileTwo, time() - 100));

        $actual = $adapter->gc(1);
        $this->assertNotFalse($actual);

        $this->assertFileDoesNotExist($fileOne);
        $this->assertFileDoesNotExist($fileTwo);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterStreamGcGlobThrowsException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Unexpected gc error');

        $adapter = new FakeStreamGlob(getOptionsSessionStream());

        $actual = $adapter->gc(1);
    }
}
