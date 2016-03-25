<?php

namespace Phalcon\Test\Proxy\Queue;

use Phalcon\Queue\Beanstalk as PhBeanstalk;

/**
 * \Phalcon\Test\Proxy\Queue\Beanstalk
 * Beanstalk proxy class for \Phalcon\Queue\Beanstalk
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Queue
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Beanstalk extends PhBeanstalk
{
    public function __construct($options = null)
    {
        parent::__construct($options);
    }

    public function connect()
    {
        return parent::connect();
    }

    public function put($data, array $options = null)
    {
        return parent::put($data, $options);
    }

    public function reserve($timeout = null)
    {
        return parent::reserve($timeout);
    }

    public function choose($tube)
    {
        return parent::choose($tube);
    }

    public function watch($tube)
    {
        return parent::watch($tube);
    }

    public function stats()
    {
        return parent::stats();
    }

    public function statsTube($tube)
    {
        return parent::statsTube($tube);
    }

    public function listTubes()
    {
        return parent::listTubes();
    }

    public function peekReady()
    {
        return parent::peekReady();
    }

    public function peekBuried()
    {
        return parent::peekBuried();
    }

    public function read($length = 0)
    {
        return parent::read($length);
    }

    protected function write($data)
    {
        return parent::write($data);
    }

    public function disconnect()
    {
        return parent::disconnect();
    }
}
