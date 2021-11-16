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

namespace Phalcon\Tests\Fixtures\Storage\Adapter;

use DateInterval;
use Exception;
use Phalcon\Storage\Adapter\Libmemcached as StorageLibmemcached;

/**
 * Phalcon\Tests\Fixtures\Storage\Adapter
 *
 * Libmemcached adapter fixture
 */
class Libmemcached extends StorageLibmemcached
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
