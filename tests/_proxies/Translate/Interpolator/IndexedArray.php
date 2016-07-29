<?php

namespace Phalcon\Test\Proxy\Translate\Interpolator;

use Phalcon\Translate\Interpolator\IndexedArray as PhIndexedArray;

/**
 * \Phalcon\Test\Proxy\Translate\Interpolator\IndexedArray
 * IndexedArray Interpolator proxy class for \Phalcon\Translate\Interpolator\IndexedArray
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Translate\Interpolator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class IndexedArray extends PhIndexedArray
{
    public function replacePlaceholders($translation, $placeholders = null)
    {
        return parent::replacePlaceholders($translation, $placeholders);
    }
}
