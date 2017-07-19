<?php

namespace Phalcon\Test\Unit\Filter;

/**
 * \Phalcon\Test\Unit\Filter\FilterEmailTest
 * Tests the \Phalcon\Filter component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Filter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FilterEmailTest extends Helper\FilterBase
{
    /**
     * Tests Email
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeEmail()
    {
        $this->specify(
            "sanitizing email does not return the correct email",
            function () {
                $expected = 'someone@example.com';
                $value    = 'some(one)@exa\\mple.com';
                $this->sanitizer('email', $expected, $value);

                $expected = '!first.guy@*my-domain**##.com.rx';
                $value    = '!(first.guy)
                            @*my-domain**##.com.rx//';
                $this->sanitizer('email', $expected, $value);
            }
        );
    }
}
