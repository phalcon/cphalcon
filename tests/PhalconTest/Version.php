<?php
/**
 * Version.php
 * \PhalconTest\Version
 *
 * Version proxy class
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace PhalconTest;

use \Phalcon\Version as PhVersion;

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
