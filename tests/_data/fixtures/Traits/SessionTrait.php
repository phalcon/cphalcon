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
        return new Libmemcached(getOptionsLibmemcached());
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
        return new Redis($this->getOptionsRedis());
    }
}
