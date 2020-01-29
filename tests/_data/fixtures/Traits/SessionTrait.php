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

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Session\Adapter\Libmemcached;
use Phalcon\Session\Adapter\Noop;
use Phalcon\Session\Adapter\Redis;
use Phalcon\Session\Adapter\Stream;
use Phalcon\Storage\AdapterFactory;
use Phalcon\Storage\SerializerFactory;
use function getOptionsLibmemcached;
use function getOptionsRedis;

trait SessionTrait
{
    protected function getSessionStream(): Stream
    {
        return new Stream(
            getOptionsSessionStream()
        );
    }


    protected function getSessionLibmemcached(): Libmemcached
    {
        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);

        return new Libmemcached(
            $factory,
            getOptionsLibmemcached()
        );
    }


    protected function getSessionNoop(): Noop
    {
        return new Noop();
    }


    protected function getSessionRedis(): Redis
    {
        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);

        return new Redis(
            $factory,
            getOptionsRedis()
        );
    }
}
