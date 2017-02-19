<?php

namespace Phalcon\Test\Proxy\Annotations;

use Phalcon\Annotations\Reflection as PhReflection;

/**
 * \Phalcon\Test\Proxy\Annotations\Reflection
 * Role proxy class for \Phalcon\Annotations\Reflection
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Annotations
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Reflection extends PhReflection
{
    public function __construct($reflectionData = null)
    {
        parent::__construct($reflectionData);
    }

    public function getClassAnnotations()
    {
        return parent::getClassAnnotations();
    }

    public function getMethodsAnnotations()
    {
        return parent::getMethodsAnnotations();
    }

    public function getPropertiesAnnotations()
    {
        return parent::getPropertiesAnnotations();
    }

    public function getReflectionData()
    {
    }

    public static function __set_state($data)
    {
        return parent::__set_state($data);
    }
}
