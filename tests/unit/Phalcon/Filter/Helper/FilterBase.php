<?php
/**
 * FilterBase.php
 * \Phalcon\Text\Helper\FilterBase
 *
 * Base class for Phalcon\Filter component
 *
 * Phalcon Framework
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

namespace Phalcon\Tests\unit\Phalcon\Filter\Helper;

use \PhalconTest\Filter as PhTFilter;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class FilterBase extends TBase
{
    /**
     * Tests integers
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     *
     * @param string    $filter
     * @param mixed     $expected
     * @param mixed     $value
     */
    protected function sanitizer($filter, $expected, $value)
    {
        $fl = new PhTFilter();
        $actual = $fl->sanitize($value, $filter);
        expect($expected)->equals($actual);
    }
}

