<?php

namespace Phalcon\Test\Proxy\Di;

use Phalcon\Di\FactoryDefault as PhFactoryDefault;

/**
 * \Phalcon\Test\Proxy\Di\FactoryDefault
 * Escaper proxy class for \Phalcon\Di\FactoryDefault
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Di
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FactoryDefault extends PhFactoryDefault
{
    public function __construct()
    {
        parent::__construct();
    }
}
