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
use function file_put_contents;
use function uniqid;

final class ValidateIdTest extends AbstractServicesTestCase
{
    use DiTrait;

    /**
     * @issue  17129
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterLibmemcachedValidateId(): void
    {
        $adapter = $this->newService('sessionLibmemcached');

        $adapter->write('test1', uniqid());

        $actual = $adapter->validateId('test1');
        $this->assertTrue($actual);

        $adapter->destroy('test1');

        $actual = $adapter->validateId('test1');
        $this->assertFalse($actual);
    }

    /**
     * @issue  17129
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterNoopValidateId(): void
    {
        $adapter = $this->newService('sessionNoop');

        $actual = $adapter->validateId('unknown');
        $this->assertTrue($actual);
    }

    /**
     * @issue  17129
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterRedisValidateId(): void
    {
        $adapter = $this->newService('sessionRedis');

        $adapter->write('test1', uniqid());

        $actual = $adapter->validateId('test1');
        $this->assertTrue($actual);

        $adapter->destroy('test1');

        $actual = $adapter->validateId('test1');
        $this->assertFalse($actual);
    }

    /**
     * @issue  17129
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testSessionAdapterStreamValidateId(): void
    {
        $adapter = $this->newService('sessionStream');

        file_put_contents(
            cacheDir('sessions/test1'),
            uniqid()
        );

        $actual = $adapter->validateId('test1');
        $this->assertTrue($actual);

        $this->safeDeleteFile(cacheDir('sessions/test1'));

        $actual = $adapter->validateId('test1');
        $this->assertFalse($actual);
    }
}
