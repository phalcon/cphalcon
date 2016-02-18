<?php

namespace Phalcon\Test\Proxy\Translate\Adapter;

use Phalcon\Translate\Adapter\NativeArray as PhNativeArray;

/**
 * \Phalcon\Test\Proxy\Translate\Adapter\NativeArray
 * NativeArray Adapter NativeArray proxy class for \Phalcon\Translate\Adapter\NativeArray
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Translate\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class NativeArray extends PhNativeArray
{
    public function query($index, $placeholders = null)
    {
        return parent::query($index, $placeholders);
    }

    public function exists($index)
    {
        return parent::exists($index);
    }
}
