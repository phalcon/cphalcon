<?php

namespace Phalcon\Test\Proxy\Logger\Adapter;

use Phalcon\Logger\Adapter\Firephp as PhFirephp;

/**
 * \Phalcon\Test\Proxy\Logger\Adapter\Firephp
 * File proxy class for \Phalcon\Logger\Adapter\Firephp
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Logger\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Firephp extends PhFirephp
{
    public function getFormatter()
    {
        return parent::getFormatter();
    }

    public function logInternal($message, $type, $time, array $context)
    {
        parent::logInternal($message, $type, $time, $context);
    }

    public function close()
    {
        return parent::close();
    }
}
