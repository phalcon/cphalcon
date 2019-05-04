<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Session\Adapter\Libmemcached;
use Phalcon\Session\Adapter\Noop;
use Phalcon\Session\Adapter\Redis;
use Phalcon\Session\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;

/**
 * Trait SessionTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
trait SessionTrait
{
    /**
     * @return Stream
     */
    protected function getSessionStream(): Stream
    {
        return new Stream(getOptionsSessionStream());
    }

    /**
     * @return Libmemcached
     */
    protected function getSessionLibmemcached(): Libmemcached
    {
        $factory = new SerializerFactory();
        return new Libmemcached($factory, getOptionsLibmemcached());
    }

    /**
     * @return Noop
     */
    protected function getSessionNoop(): Noop
    {
        return new Noop();
    }

    /**
     * @return Redis
     */
    protected function getSessionRedis(): Redis
    {
        $factory = new SerializerFactory();
        return new Redis($factory, $this->getOptionsRedis());
    }
}
