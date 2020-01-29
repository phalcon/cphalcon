<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Cache\Adapter;

use Phalcon\Cache\Adapter\Libmemcached as CacheLibmemcached;
use Phalcon\Storage\Exception;

/**
 * Phalcon\Test\Fixtures\Cache\Adapter
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
     * @param \DateInterval|int|null $ttl
     *
     * @return int
     * @throws Exception
     */
    public function getTtl($ttl = null): int
    {
        return parent::getTtl($ttl);
    }
}
