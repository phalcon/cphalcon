<?php

namespace Phalcon\Test\Proxy\Paginator\Adapter;

use Phalcon\Paginator\Adapter\NativeArray as PhNativeArray;

/**
 * \Phalcon\Test\Proxy\Paginator\Adapter\NativeArray
 * Beanstalk proxy class for \Phalcon\Paginator\Adapter\NativeArray
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Paginator\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class NativeArray extends PhNativeArray
{
    public function __construct($config)
    {
        parent::__construct($config);
    }

    public function getPaginate()
    {
        return parent::getPaginate();
    }
}
