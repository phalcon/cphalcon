<?php

namespace Phalcon\Test\Proxy\Image\Adapter;

use Phalcon\Image\Adapter\Gd as PhGd;

/**
 * \Phalcon\Test\Proxy\Image\Adapter\Gd
 * Config proxy class for \Phalcon\Image\Adapter\Gd
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Image\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Gd extends PhGd
{
    public static function check()
    {
        return parent::check();
    }

    public function __construct($file, $width = null, $height = null)
    {
        parent::__construct($file, $width, $height);
    }

    public function __destruct()
    {
        parent::__destruct();
    }
}
