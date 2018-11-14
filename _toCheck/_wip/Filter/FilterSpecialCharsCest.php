<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Filter;

use Phalcon\Filter;
use Phalcon\Test\Unit\Filter\Helper\FilterBase;
use UnitTester;

class FilterSpecialCharsCest extends FilterBase
{
    /**
     * Tests Sanitize special characters
     *
     * @author Zamrony P. Juhara <zamronypj@yahoo.com>
     * @since  2017-03-23
     */
    public function testSanitizeSpecialChars(UnitTester $I)
    {
        $expected = 'This is &#60;html&#62; tags';
        $value    = 'This is <html> tags';
        $this->sanitizer($I, 'special_chars', $expected, $value);
    }
}
