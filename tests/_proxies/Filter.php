<?php

namespace Phalcon\Test\Proxy;

use Phalcon\Filter as PhFilter;

/**
 * \Phalcon\Test\Proxy\Filter
 * Filter proxy class for \Phalcon\Filter
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Filter extends PhFilter
{
    public function add($name, $handler)
    {
        return parent::add($name, $handler);
    }

    public function sanitize($value, $filters, $noRecursive = false)
    {
        return parent::sanitize($value, $filters, $noRecursive);
    }

    public function getFilters()
    {
        return parent::getFilters();
    }
}
