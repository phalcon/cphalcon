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

namespace Phalcon\Test\Unit\Service\Locator;

use Phalcon\Service\Locator;
use Phalcon\Test\Fixtures\Service\HelloService;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class UnderscoreCallCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Service\Locator :: __call()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function serviceLocatorUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest('Html\Locator - __call()');

        $services = [
            'helloFilter' => HelloService::class,
        ];

        $locator = new Locator($services);

        $I->assertTrue(
            $locator->has('helloFilter')
        );

        $I->assertEquals(
            'Hello Phalcon [count: 1]',
            $locator->helloFilter('Phalcon')
        );

        $I->assertEquals(
            'Hello Phalcon [count: 2]',
            $locator->helloFilter('Phalcon')
        );
    }

    /**
     * Tests Phalcon\Service\Locator :: __call()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function serviceLocatorUnderscoreCallAnonymous(UnitTester $I)
    {
        $I->wantToTest('Html\Locator - __call()');

        $services = [
            'custom' => function ($escaper, $value) {
                return $escaper->escapeHtml($value);
            }
        ];

        $escaper = $this->newEscaper();

        $locator = new Locator($services);

        $I->assertTrue(
            $locator->has('custom')
        );

        $I->assertEquals(
            'Jack &amp; Jill',
            $locator->custom(
                $escaper,
                'Jack & Jill'
            )
        );
    }
}
