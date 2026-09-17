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

namespace Phalcon\Tests\Support\Fake;

use Phalcon\Cache\Cache;

/**
 * Cache whose set() always fails, so setMultiple() reports a failure.
 */
final class FakeCache extends Cache
{
    public function set(string $key, mixed $value, mixed $ttl = null): bool
    {
        return false;
    }
}
