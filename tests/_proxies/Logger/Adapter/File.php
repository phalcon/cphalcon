<?php

namespace Phalcon\Test\Proxy\Logger\Adapter;

use Phalcon\Logger\Adapter\File as PhFile;

/**
 * \Phalcon\Test\Proxy\Logger\Adapter\File
 * File proxy class for \Phalcon\Logger\Adapter\File
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Logger\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class File extends PhFile
{
    public function __construct($name, $options = null)
    {
        parent::__construct($name, $options);
    }

    public function getPath()
    {
        return parent::getPath();
    }

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

    public function __wakeup()
    {
        parent::__wakeup();
    }
}
