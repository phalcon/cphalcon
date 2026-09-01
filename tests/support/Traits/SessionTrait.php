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

namespace Phalcon\Tests\Support\Traits;

use Phalcon\Session\Adapter\Libmemcached;
use Phalcon\Session\Adapter\Noop;
use Phalcon\Session\Adapter\Redis;
use Phalcon\Session\Adapter\Stream;

trait SessionTrait
{
    /**
     * @return array[]
     */
    public static function getClassNames(): array
    {
        return [
            ['sessionLibmemcached'],
            ['sessionNoop'],
            ['sessionRedis'],
            ['sessionStream'],
        ];
    }

    /**
     * @return \class-string[][]
     */
    public static function getClasses(): array
    {
        return [
            [Libmemcached::class],
            [Noop::class],
            [Redis::class],
            [Stream::class],
        ];
    }
}
