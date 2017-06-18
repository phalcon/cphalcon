<?php

namespace Phalcon\Test\Unit\Filter;

/**
 * \Phalcon\Test\Unit\Filter\FilterUrlTest
 * Tests the \Phalcon\Filter component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Zamrony P. Juhara <zamronypj@yahoo.com>
 * @package   Phalcon\Test\Unit\Filter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FilterUrlTest extends Helper\FilterBase
{
    /**
     * Tests Url
     *
     * @author Zamrony P. Juhara <zamronypj@yahoo.com>
     * @since  2017-03-23
     */
    public function testSanitizeUrl()
    {
        $this->specify(
            "sanitizing url does not return the correct url",
            function () {
                $expected = 'http://juhara.com';
                $value    = 'http://juhara��.co�m';
                $this->sanitizer('url', $expected, $value);
            }
        );
    }
}
