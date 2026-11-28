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

namespace Phalcon\Tests\Benchmarks\Cache;

use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Cache;
use Phalcon\Di\Di;
use Phalcon\Storage\SerializerFactory;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class CacheBench
{
    private const ROBOTS = ['one', 'two', 'three'];

    private Cache $cache;

    private int $counter = 0;

    public function setUp(): void
    {
        Di::reset();

        $this->cache = $this->newCache();
        $this->cache->set('robots', self::ROBOTS);
    }

    /**
     * The two factories, the memory adapter and the cache, as one request
     * makes them.
     */
    public function benchCreate(): void
    {
        $cache = $this->newCache();

        if (false !== $cache->has('missing')) {
            throw new RuntimeException('Unexpected value: true');
        }
    }

    public function benchGet(): void
    {
        $actual = $this->cache->get('robots');

        if (self::ROBOTS !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: %s', var_export($actual, true)));
        }
    }

    /**
     * set() of a key that exists, with a new value on each call.
     */
    public function benchSet(): void
    {
        $this->counter++;

        if (true !== $this->cache->set('counter', $this->counter)) {
            throw new RuntimeException('Unexpected value: false');
        }
    }

    private function newCache(): Cache
    {
        $factory = new AdapterFactory(new SerializerFactory());

        return new Cache($factory->newInstance('memory'));
    }
}
