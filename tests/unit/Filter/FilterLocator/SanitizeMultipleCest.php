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

namespace Phalcon\Test\Unit\Filter\FilterLocator;

use Phalcon\Filter\FilterLocatorFactory;
use UnitTester;

/**
 * Class SanitizeMultipleCest
 */
class SanitizeMultipleCest
{
    /**
     * Tests sanitizing string with filters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function filterFilterLocatorSanitizeStringWithMultipleFilters(UnitTester $I)
    {
        $locator = new FilterLocatorFactory();
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
    public function filterFilterLocatorSanitizeArray(UnitTester $I)
    {
        $locator = new FilterLocatorFactory();
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
    public function filterFilterLocatorSanitizeArrayWithMultipleFilters(UnitTester $I)
    {
        $locator = new FilterLocatorFactory();
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
    public function filterFilterLocatorSanitizeWithMultipleFiltersMoreParameters(UnitTester $I)
    {
        $locator = new FilterLocatorFactory();
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
