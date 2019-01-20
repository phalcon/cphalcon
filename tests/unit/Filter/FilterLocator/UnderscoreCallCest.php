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

namespace Phalcon\Test\Unit\Filter\Locator;

use Phalcon\Filter\Locator;
use Phalcon\Test\Fixtures\Filter\HelloFilter;
use UnitTester;

/**
 * Class UnderscoreCallCest
 */
class UnderscoreCallCest
{
    /**
     * Tests Phalcon\Filter\Locator :: __call()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function serviceLocatorUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest('Filter\Locator - __call()');
        $services = [
            'helloFilter' => function () {
                return new HelloFilter();
            },
        ];

        $locator = new Locator($services);
        $actual  = $locator->has('helloFilter');
        $I->assertTrue($actual);

        /** @var object $service */
        $expected = 'Hello Phalcon [count: 1]';
        $actual   = $locator->helloFilter('Phalcon');
        $I->assertEquals($expected, $actual);

        $expected = 'Hello Phalcon [count: 2]';
        $actual   = $locator->helloFilter('Phalcon');
        $I->assertEquals($expected, $actual);
    }
}
