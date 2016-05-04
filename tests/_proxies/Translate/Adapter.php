<?php

namespace Phalcon\Test\Proxy\Translate;

use Phalcon\Translate\Adapter as PhAdapter;
use Phalcon\Translate\InterpolatorInterface;

/**
 * \Phalcon\Test\Proxy\Translate\Adapter
 * Adapter proxy class for \Phalcon\Translate\Adapter
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Translate
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
abstract class Adapter extends PhAdapter
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

    public function setInterpolator(InterpolatorInterface $interpolator)
    {
        return parent::setInterpolator($interpolator);
    }

    protected function replacePlaceholders($translation, $placeholders = null)
    {
        return parent::replacePlaceholders($translation, $placeholders);
    }
}
