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

namespace Phalcon\Tests\Unit\Cache\Adapter;

use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Cache\Adapter\RedisCluster;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Cache\Adapter\Weak;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use stdClass;

use function extension_loaded;
use function sleep;
use function uniqid;

final class GetSetForeverTest extends AbstractUnitTestCase
{
    /**
     * Adapters, their options, the extension they need and whether they honor
     * a TTL. Memory keeps entries for the life of the process, so there is no
     * expiring key to contrast a "forever" one against.
     *
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                Apcu::class,
                [],
                'apcu',
                true,
            ],
            [
                Libmemcached::class,
                [
                    'client'  => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
                'memcached',
                true,
            ],
            [
                Memory::class,
                [],
                '',
                false,
            ],
            [
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
                'redis',
                true,
            ],
            [
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
                'redis',
                true,
            ],
            [
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                '',
                true,
            ],
        ];
    }

    /**
     * Every adapter is primed first, then a single wait covers all of them.
     * Each adapter that honors a TTL also stores a key that expires during
     * that wait, so the surviving "forever" key is shown to have outlived an
     * entry that did expire.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testCacheAdapterGetSetForever(): void
    {
        $serializer = new SerializerFactory();
        $primed     = [];

        foreach (self::getExamples() as [$class, $options, $extension, $honorsTtl]) {
            if (!empty($extension) && !extension_loaded($extension)) {
                continue;
            }

            $adapter    = new $class($serializer, $options);
            $foreverKey = uniqid();
            $shortKey   = uniqid();

            $this->assertTrue($adapter->setForever($foreverKey, "test"), $class);

            if ($honorsTtl) {
                $this->assertTrue($adapter->set($shortKey, "test", 1), $class);
            }

            $primed[] = [$class, $adapter, $foreverKey, $shortKey, $honorsTtl];
        }

        if ([] === $primed) {
            $this->markTestSkipped('No cache adapters available');
        }

        sleep(2);

        foreach ($primed as [$class, $adapter, $foreverKey, $shortKey, $honorsTtl]) {
            if ($honorsTtl) {
                $this->assertFalse($adapter->has($shortKey), $class);
            }

            $this->assertTrue($adapter->has($foreverKey), $class);

            /**
             * Delete it
             */
            $this->assertTrue($adapter->delete($foreverKey), $class);
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-07-17
     */
    public function testCacheAdapterWeakGetSetForever(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Weak($serializer);

        $key    = uniqid();
        $obj    = new stdClass();
        $result = $adapter->setForever($key, "test");
        $this->assertFalse($result);
        $result = $adapter->setForever($key, $obj);
        $this->assertTrue($result);
        $result = $adapter->has($key);
        $this->assertTrue($result);
        /**
         * Delete it
         */
        $result = $adapter->delete($key);
        $this->assertTrue($result);
    }
}
