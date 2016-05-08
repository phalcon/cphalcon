<?php

namespace Phalcon\Test\Proxy\Queue\Beanstalk;

use Phalcon\Queue\Beanstalk;
use Phalcon\Queue\Beanstalk\Job as PhJob;

/**
 * \Phalcon\Test\Proxy\Queue\Beanstalk\Job
 * Job proxy class for \Phalcon\Queue\Beanstalk\Job
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
class Job extends PhJob
{
    public function __construct(Beanstalk $queue, $id, $body)
    {
        parent::__construct($queue, $id, $body);
    }

    public function getId()
    {
        return parent::getId();
    }

    public function getBody()
    {
        return parent::getBody();
    }

    public function delete()
    {
        return parent::delete();
    }

    public function release($priority = 100, $delay = 0)
    {
        return parent::release($priority, $delay);
    }

    public function bury($priority = 100)
    {
        return parent::bury($priority);
    }

    public function touch()
    {
        return parent::touch();
    }

    public function kick()
    {
        return parent::kick();
    }

    public function stats()
    {
        return parent::stats();
    }

    public function __wakeup()
    {
        parent::__wakeup();
    }
}
