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

use Codeception\Example;
use Phalcon\Filter\FilterLocator;
use Phalcon\Test\Fixtures\Filter\Sanitize\IPv4;
use UnitTester;

/**
 * Class CustomCest
 */
class CustomCest
{
    /**
     * Tests Phalcon\Filter\FilterLocator :: custom has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function filterFilterLocatorCustomHas(UnitTester $I)
    {
        $I->wantToTest('Filter\FilterLocator - custom has()');
        $services = [
            'ipv4' => function () {
                return new \Phalcon\Test\Fixtures\Filter\Sanitize\IPv4();
            },
        ];

        $locator = new FilterLocator($services);

        $actual = $locator->has('ipv4');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Filter\FilterLocator :: custom sanitizer
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function filterFilterLocatorCustomSanitizer(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\FilterLocator - custom sanitizer');
        $I->skipTest('TODO: Check why this cannot be auto loaded');
        $services = [
            'ipv4' => function () {
                return new \Phalcon\Test\Fixtures\Filter\Sanitize\IPv4();
            },
        ];

        $locator = new FilterLocator($services);

        /** @var IPv4 $sanitizer */
        $sanitizer = $locator->get('ipv4');
        $expected  = $example[1];
        $actual    = $sanitizer();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            ['00:1c:42:bf:71:22', ''],
            ['127.0.0.1', '127.0.0.1'],
        ];
    }
}
