<?php
/**
 * Adapter.php
 * \PhalconTest\Translate\Adapter
 *
 * Translate Adapter proxy class
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

namespace PhalconTest\Translate;

abstract class Adapter
{
    public function t($translateKey, $placeholders = null)
    {
        return parent::t($translateKey, $placeholders);
    }

    public function _($translateKey, $placeholders = null)
    {
        return parent::_($translateKey, $placeholders);
    }

    public function offsetSet($offset, $value)
    {
        parent::offsetSet($offset, $value);
    }

    public function offsetExists($translateKey)
    {
        return parent::offsetExists($translateKey);
    }

    public function offsetUnset($offset)
    {
        parent::offsetUnset($offset);
    }

    public function offsetGet($translateKey)
    {
        return $this->offsetGet($translateKey);
    }
}
