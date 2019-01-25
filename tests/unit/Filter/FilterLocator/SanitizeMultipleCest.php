<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Filter;

use Phalcon\Test\Unit\Filter\Helper\FilterBase;
use UnitTester;

class FilterMultipleCest extends FilterBase
{
    /**
     * Tests sanitizing string with filters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringWithMultipleFilters(UnitTester $I)
    {
        $expected = 'lol';
        $value    = '    lol<<<   ';
        $this->sanitizer($I, ['string', 'trim'], $expected, $value);
    }

    /**
     * Tests sanitizing array with filters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeArray(UnitTester $I)
    {
        $expected = ['1', '2', '3'];
        $value    = [' 1 ', '  2', '3  '];
        $this->sanitizer($I, 'trim', $expected, $value);
    }

    /**
     * Tests sanitizing array with multiple filters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeArrayWithMultipleFilters(UnitTester $I)
    {
        $expected = ['1', '2', '3'];
        $value    = [' <a href="a">1</a> ', '  <h1>2</h1>', '<p>3</p>'];
        $this->sanitizer($I, ['trim', 'striptags'], $expected, $value);
    }
}
