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

use Phalcon\Filter\FilterLocator;
use Phalcon\Test\Fixtures\Service\HelloService;
use UnitTester;

/**
 * Class UnderscoreCallCest
 */
class UnderscoreCallCest
{
    /**
     * Tests Phalcon\Filter\FilterLocator :: __call()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function filterFilterLocatorUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest('Filter\FilterLocator - __call()');
        $services = [
            'helloFilter' => HelloService::class,
        ];

        $locator = new FilterLocator($services);
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
