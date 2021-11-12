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

namespace Phalcon\Tests\Fixtures\Cache\Adapter;

use DateInterval;
use Phalcon\Cache\Adapter\Libmemcached as CacheLibmemcached;
use Phalcon\Storage\Exception;

/**
 * Phalcon\Tests\Fixtures\Cache\Adapter
 *
 * Libmemcached adapter fixture
 */
class Libmemcached extends CacheLibmemcached
{
    public function getOptions(): array
    {
        return $this->options;
    }

    /**
     * @param DateInterval|int|null $ttl
     *
     * @return int
     * @throws Exception
     */
    public function getTtl($ttl = null): int
    {
        return parent::getTtl($ttl);
    }
}
