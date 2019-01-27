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

use Phalcon\Html\TagLocator;
use Phalcon\Test\Fixtures\Service\HelloService;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class UnderscoreCallCest
 */
class UnderscoreCallCest
{
    use DiTrait;

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
            'helloFilter' => HelloService::class,
        ];

        $locator = new TagLocator($services);
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

    /**
     * Tests Phalcon\Service\Locator :: __call()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function htmlTagLocatorUnderscoreCallAnonymous(UnitTester $I)
    {
        $I->wantToTest('Html\TagLocator - __call()');
        $services = [
            'custom' => function ($escaper, $value) {
                return $escaper->escapeHtml($value);
            }
        ];

        $escaper = $this->newEscaper();
        $locator = new TagLocator($services);
        $actual  = $locator->has('custom');
        $I->assertTrue($actual);

        $expected = 'Jack &amp; Jill';
        $actual   = $locator->custom($escaper, 'Jack & Jill');
        $I->assertEquals($expected, $actual);
    }
}
