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
use function func_get_args;
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
            'md5' => function ($input) {
                return md5($input);
            },
        ];

        $locator = new FilterLocator($services);

        $actual = $locator->has('md5');
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
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-01-19
     */
    public function filterFilterLocatorCustomSanitizer(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\FilterLocator - custom sanitizer');
        $services = [
            'md5' => function () {
                $args  = func_get_args();
                $param = $args[0] ?? '';

                return md5($param);
            },
        ];

        $locator = new FilterLocator($services);

        /** @var IPv4 $sanitizer */
        $sanitizer = $locator->get('md5');
        $expected  = $example[1];
        $actual    = $sanitizer($example[0]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            ['Phalcon', '0c72dd6ed577ad56621483e7a752b09f'],
            ['Framework', '07782c22a88d1e82a09910124a9225a2'],
        ];
    }
}
