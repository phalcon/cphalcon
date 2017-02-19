<?php

namespace Phalcon\Test\Proxy\Assets\Filters;

use Phalcon\Assets\Filters\Jsmin as PhJs;

/**
 * \Phalcon\Test\Proxy\Assets\Filters\Jsmin
 * Jsmin Filter proxy class for \Phalcon\Assets\Filters\Jsmin
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Assets\Filters
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Jsmin extends PhJs
{
    public function filter($content)
    {
        return parent::filter($content);
    }
}
