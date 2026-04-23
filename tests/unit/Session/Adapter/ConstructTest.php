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

use Phalcon\Session\Adapter\Libmemcached;
use Phalcon\Session\Adapter\Redis;
use Phalcon\Session\Adapter\Stream;
use Phalcon\Session\Exception;
use Phalcon\Storage\AdapterFactory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Support\Traits\SessionTrait;
use Phalcon\Tests\Unit\Session\Fake\Adapter\FakeStreamIsWritable;
use SessionHandlerInterface;

use function getOptionsRedis;
use function getOptionsSessionStream;

final class ConstructTest extends AbstractUnitTestCase
{
    use DiTrait;
    use SessionTrait;

    /**
     * @dataProvider getClassNames
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testSessionAdapterConstruct(
        string $name
    ): void {
        $adapter = $this->newService($name);

        $class = SessionHandlerInterface::class;
        $this->assertInstanceOf($class, $adapter);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-23
     */
    public function testSessionAdapterLibmemcachedConstructWithPrefix(): void
    {
        $options           = getOptionsLibmemcached();
        $options['prefix'] = 'my-custom-prefix-';

        $serializerFactory = new SerializerFactory();
        $factory           = new AdapterFactory($serializerFactory);

        $memcachedSession = new Libmemcached($factory, $options);

        $actual = $memcachedSession->write(
            'my-session-prefixed-key',
            'test-data'
        );

        $this->assertTrue($actual);

        $memcachedStorage = $factory->newInstance('libmemcached', $options);

        $expected = 'my-custom-prefix-';
        $actual   = $memcachedStorage->getPrefix();
        $this->assertEquals($expected, $actual);

        $expected = 'test-data';
        $actual   = $memcachedStorage->get('my-session-prefixed-key');
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-23
     */
    public function testSessionAdapterRedisConstructWithPrefix(): void
    {
        $options           = getOptionsRedis();
        $options['prefix'] = 'my-custom-prefix-';

        $serializerFactory = new SerializerFactory();
        $factory           = new AdapterFactory($serializerFactory);

        $redisSession = new Redis($factory, $options);

        $actual = $redisSession->write(
            'my-session-prefixed-key',
            'test-data'
        );

        $this->assertTrue($actual);

        $redisStorage = $factory->newInstance('redis', $options);

        $expected = 'my-custom-prefix-';
        $actual   = $redisStorage->getPrefix();
        $this->assertEquals($expected, $actual);

        $expected = 'test-data';
        $actual   = $redisStorage->get('my-session-prefixed-key');
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-23
     */
    public function testSessionAdapterStreamWithNoSavePathThrowsException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The session save path cannot be empty');

        $options = [
            'prefix'   => 'my-custom-prefix-',
            'savePath' => '',
        ];

        $streamSession = new Stream($options);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-23
     */
    public function testSessionAdapterStreamWithNotWriteableSavePathThrowsException(): void
    {
        $options  = getOptionsSessionStream();
        $savePath = $options['savePath'];
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'The session save path [' . $savePath . '] is not writable'
        );

        $streamSession = new FakeStreamIsWritable($options);
    }
}
