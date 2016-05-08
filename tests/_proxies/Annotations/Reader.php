<?php

namespace Phalcon\Test\Proxy\Annotations;

use Phalcon\Annotations\Reader as PhReader;

/**
 * \Phalcon\Test\Proxy\Annotations\Reader
 * Role proxy class for \Phalcon\Annotations\Reader
 *
 * @copyright (c) 2011-2016 Phalcon Team
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
class Reader extends PhReader
{
    public function parse($className)
    {
        return parent::parse($className);
    }

    public static function parseDocBlock($docBlock, $file = null, $line = null)
    {
        return parent::parseDocBlock($docBlock, $file, $line);
    }
}
