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
use UnitTester;

class GetSetHasCest
{
    /**
     * Tests Phalcon\Service\Locator :: get()/set()/has() - has()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function serviceLocatorGetSetHasHas(UnitTester $I)
    {
        $I->wantToTest('Service\Locator - get()/set()/has() - has()');

        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new Locator($services);

        $I->assertTrue(
            $locator->has('helloFilter')
        );
    }

    /**
     * Tests Phalcon\Service\Locator :: get()/set()/has() - get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function serviceLocatorGetSetHasGet(UnitTester $I)
    {
        $I->wantToTest('Service\Locator - get()/set()/has() - get()');

        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new Locator($services);

        $I->assertTrue(
            $locator->has('helloFilter')
        );

        $I->assertInstanceOf(
            HelloService::class,
            $locator->get('helloFilter')
        );
    }

    /**
     * Tests Phalcon\Service\Locator :: get()/set()/has() - get() same
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function serviceLocatorGetSetHasGetSame(UnitTester $I)
    {
        $I->wantToTest('Service\Locator - get()/set()/has() - get() - same');

        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new Locator($services);

        $I->assertTrue(
            $locator->has('helloFilter')
        );

        $I->assertEquals(
            'Hello Phalcon [count: 1]',
            $locator->get('helloFilter')('Phalcon')
        );

        $I->assertEquals(
            'Hello Phalcon [count: 2]',
            $locator->get('helloFilter')('Phalcon')
        );
    }

    /**
     * Tests Phalcon\Service\Locator :: get()/set()/has() - set()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function serviceLocatorGetSetHasSet(UnitTester $I)
    {
        $I->wantToTest('Service\Locator - get()/set()/has() - set()');

        $locator = new Locator();

        $I->assertFalse(
            $locator->has('helloFilter')
        );

        $locator->set(
            'helloFilter',
            function () {
                return new HelloService();
            }
        );

        $I->assertTrue(
            $locator->has('helloFilter')
        );
    }
}
