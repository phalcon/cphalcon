<?php
/**
 * Inline.php
 * \PhalconTest\Assets\Inline
 *
 * Inline proxy class
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

namespace PhalconTest\Assets;

use \Phalcon\Assets\Inline as PhInline;

class Inline extends PhInline
{
    public function setType($type)
    {
        return parent::setType($type);
    }

    public function setFilter($filter)
    {
        return parent::setFilter($filter);
    }

    public function setAttributes($attributes)
    {
        return parent::setAttributes($attributes);
    }
}
