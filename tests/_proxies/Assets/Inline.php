<?php

namespace Phalcon\Test\Proxy\Assets;

use Phalcon\Assets\Inline as PhInline;

/**
 * \Phalcon\Test\Proxy\Assets\Inline
 * Inline proxy class for \Phalcon\Assets\Inline
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Assets
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
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

    public function setAttributes(array $attributes)
    {
        return parent::setAttributes($attributes);
    }
}
