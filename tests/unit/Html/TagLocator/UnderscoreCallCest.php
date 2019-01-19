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

namespace Phalcon\Test\Unit\Html\TagLocator;

use Phalcon\Service\Locator;
use Phalcon\Test\Fixtures\Service\HelloService;
use UnitTester;

/**
 * Class UnderscoreCallCest
 */
class UnderscoreCallCest
{
    /**
     * Tests Phalcon\Service\Locator :: __call()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function htmlTagLocatorUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest('Html\TagLocator - __call()');
        $services = [
            'helloService' => function () {
                return new HelloService();
            },
        ];

        $locator = new Locator($services);
        $actual  = $locator->has('helloService');
        $I->assertTrue($actual);

        /** @var object $service */
        $expected = 'Hello Phalcon [count: 1]';
        $actual   = $locator->helloService('Phalcon');
        $I->assertEquals($expected, $actual);

        $expected = 'Hello Phalcon [count: 2]';
        $actual   = $locator->helloService('Phalcon');
        $I->assertEquals($expected, $actual);
    }
}
