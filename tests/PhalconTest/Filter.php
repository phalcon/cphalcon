<?php
/**
 * Filter.php
 * \PhalconTest\Filter
 *
 * Filter proxy class
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

namespace PhalconTest;

use \Phalcon\Filter as PhFilter;

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
