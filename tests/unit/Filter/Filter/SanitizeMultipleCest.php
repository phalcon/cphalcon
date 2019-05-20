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

namespace Phalcon\Test\Unit\Filter\Filter;

use Phalcon\Filter\FilterFactory;
use UnitTester;

class SanitizeMultipleCest
{
    /**
     * Tests sanitizing string with filters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function filterFilterSanitizeStringWithMultipleFilters(UnitTester $I)
    {
        $locator = new FilterFactory();
        $filter  = $locator->newInstance();

        $value    = '    lol<<<   ';
        $expected = 'lol';
        $actual   = $filter->sanitize($value, ['string', 'trim']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests sanitizing array with filters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function filterFilterSanitizeArray(UnitTester $I)
    {
        $locator = new FilterFactory();
        $filter  = $locator->newInstance();

        $value    = [' 1 ', '  2', '3  '];
        $expected = ['1', '2', '3'];
        $actual   = $filter->sanitize($value, 'trim');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests sanitizing array with multiple filters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function filterFilterSanitizeArrayWithMultipleFilters(UnitTester $I)
    {
        $locator = new FilterFactory();
        $filter  = $locator->newInstance();

        $value    = [' <a href="a">1</a> ', '  <h1>2</h1>', '<p>3</p>'];
        $expected = ['1', '2', '3'];
        $actual   = $filter->sanitize($value, ['trim', 'striptags']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests sanitizing array with multiple filters and more parameters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function filterFilterSanitizeWithMultipleFiltersMoreParameters(UnitTester $I)
    {
        $locator = new FilterFactory();
        $filter  = $locator->newInstance();

        $value    = '  mary had a little lamb ';
        $filters  = [
            'trim',
            'replace' => [' ', '-'],
            'remove'  => ['mary'],
        ];
        $expected = '-had-a-little-lamb';
        $actual   = $filter->sanitize($value, $filters);
        $I->assertEquals($expected, $actual);
    }
}
