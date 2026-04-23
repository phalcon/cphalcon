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

use Phalcon\Session\Adapter\Redis;
use Phalcon\Tests\AbstractServicesTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Session\Fake\Adapter\FakeStreamFileGetContents;

use function cacheDir;
use function getOptionsSessionStream;
use function uniqid;

final class ReadWriteTest extends AbstractServicesTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterLibmemcachedReadWrite(): void
    {
        $adapter = $this->newService('sessionLibmemcached');

        $value = uniqid();

        $adapter->write('test1', $value);

        $actual = $adapter->read('test1');
        $this->assertEquals($value, $actual);

        $this->clearMemcached();

        $actual = $adapter->read('test1');
        $this->assertNotNull($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterNoopWrite(): void
    {
        $adapter = $this->newService('sessionNoop');

        $actual = $adapter->write('test1', uniqid());
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterNoopReadWrite(): void
    {
        $adapter = $this->newService('sessionNoop');
        $value   = uniqid();

        $adapter->write('test1', $value);

        $expected = '';
        $actual   = $adapter->read('test1');
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterRedisReadWrite(): void
    {
        /** @var Redis $adapter */
        $adapter = $this->newService('sessionRedis');
        $value   = uniqid();

        $adapter->write('test1', $value);

        $expected = $value;
        $actual   = $adapter->read('test1');
        $this->assertEquals($expected, $actual);
        $this->sendRedisCommand('del', 'sess-reds-test1');

        $actual = $adapter->read('test1');
        $this->assertNotNull($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterStreamRead(): void
    {
        $adapter = $this->newService('sessionStream');

        $value = uniqid();
        $adapter->write('test1', $value);

        $actual = $adapter->read('test1');
        $this->assertEquals($value, $actual);

        $this->safeDeleteFile(cacheDir('sessions/test1'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterStreamReadNoData(): void
    {
        $adapter = new FakeStreamFileGetContents(getOptionsSessionStream());
        $value   = uniqid();
        $adapter->write('test1', $value);

        $actual = $adapter->read('test1');
        $this->assertEmpty($actual);

        $this->safeDeleteFile(cacheDir('sessions/test1'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionAdapterStreamWrite(): void
    {
        $adapter = $this->newService('sessionStream');
        $value   = uniqid();
        $adapter->write('test1', $value);

        $file = cacheDir('sessions/test1');
        $this->assertFileExists($file);

        $this->assertFileContentsContains($file, $value);
        $this->safeDeleteFile($file);
    }
}
