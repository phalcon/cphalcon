<?php
/**
 * TrimFilter.php
 * \Phalcon\Assets\Helper\TrimFilter
 *
 * Tests the \Phalcon\Assets component
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

namespace Phalcon\Tests\unit\Phalcon\Assets\Helper;

use \Phalcon\Assets\FilterInterface as PhFilterInterface;

class TrimFilter implements PhFilterInterface
{
    /**
     * Trims the input
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param $input
     *
     * @return string
     */
    public function filter($input)
    {
        return str_replace(array("\n", "\r", " ", "\t"), '', $input);
    }
}
