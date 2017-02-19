<?php

namespace Phalcon\Test\Proxy\Mvc\Model\Metadata;

use Phalcon\Mvc\Model\Metadata\Libmemcached as PhLibmemcached;

/**
 * \Phalcon\Test\Proxy\Mvc\Model\Metadata\Libmemcached
 * Apc adapter proxy class for \Phalcon\Mvc\Model\Metadata\Libmemcached
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Mvc\Model\Metadata
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Libmemcached extends PhLibmemcached
{
    public function __construct($options = null)
    {
        parent::__construct($options);
    }

    public function read($key)
    {
        return parent::read($key);
    }

    public function write($key, $data)
    {
        parent::write($key, $data);
    }

    public function reset()
    {
        parent::reset();
    }
}
