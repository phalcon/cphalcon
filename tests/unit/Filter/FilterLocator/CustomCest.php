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

use Closure;
use Codeception\Example;
use Phalcon\Filter\FilterLocator;
use Phalcon\Test\Fixtures\Filter\Sanitize\IPv4;
use UnitTester;
use function func_get_args;

class CustomCest
{
    /**
     * Tests Phalcon\Filter\FilterLocator :: custom has()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function filterFilterLocatorCustomHas(UnitTester $I)
    {
        $I->wantToTest('Filter\FilterLocator - custom has()');
        $services = [
            'ipv4' => function () {
                return new IPv4();
            },
        ];

        $locator = new FilterLocator($services);

        $actual = $locator->has('ipv4');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Filter\FilterLocator :: custom sanitizer
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-01-19
     */
    public function filterFilterLocatorCustomSanitizer(UnitTester $I)
    {
        $I->wantToTest('Filter\FilterLocator - custom sanitizer');
        $services = [
            'ipv4' => function () {
                return new IPv4();
            },
        ];

        $locator = new FilterLocator($services);

        /** @var IPv4 $sanitizer */
        $sanitizer = $locator->get('ipv4');
        $I->assertInstanceOf(IPv4::class, $sanitizer);

        $expected = '127.0.0.1';
        $actual   = $sanitizer('127.0.0.1');
        $I->assertEquals($expected, $actual);

        $actual   = $sanitizer('127.0.0');
        $I->assertFalse($actual);
    }
}
