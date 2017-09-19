<?php

namespace Phalcon\Test\Unit\Filter\Helper;

use Phalcon\Filter;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Filter\Helper\FilterBase
 * Base test class for \Phalcon\Filter component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Filter\Helper
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FilterBase extends UnitTest
{
    /**
     * Tests integers
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     *
     * @param string $filter
     * @param mixed  $expected
     * @param mixed  $value
     */
    protected function sanitizer($filter, $expected, $value)
    {
        $fl = new Filter();
        $actual = $fl->sanitize($value, $filter);
        expect($expected)->equals($actual);
    }
}
