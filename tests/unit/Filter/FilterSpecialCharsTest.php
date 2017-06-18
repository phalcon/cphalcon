<?php

namespace Phalcon\Test\Unit\Filter;

/**
 * \Phalcon\Test\Unit\Filter\FilterSpecialCharsTest
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
class FilterSpecialCharsTest extends Helper\FilterBase
{
    /**
     * Tests Sanitize special characters
     *
     * @author Zamrony P. Juhara <zamronypj@yahoo.com>
     * @since  2017-03-23
     */
    public function testSanitizeSpecialChars()
    {
        $this->specify(
            "sanitizing special characters does not return correct string",
            function () {
                $expected = 'This is &#60;html&#62; tags';
                $value    = 'This is <html> tags';
                $this->sanitizer('special_chars', $expected, $value);
            }
        );
    }
}
