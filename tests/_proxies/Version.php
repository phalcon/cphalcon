<?php

namespace Phalcon\Test\Proxy;

use Phalcon\Version as PhVersion;

/**
 * \Phalcon\Test\Proxy\Version
 * Version proxy class for \Phalcon\Version
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Version extends PhVersion
{
    public static function get()
    {
        return parent::get();
    }

    public static function getId()
    {
        return parent::getId();
    }

    public static function getPart($part)
    {
        return parent::getPart($part);
    }
}
