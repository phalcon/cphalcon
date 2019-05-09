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
use UnitTester;

/**
 * Class GetSetHasCest
 */
class GetSetHasCest
{
    /**
     * Tests Phalcon\Html\TagLocator :: get()/set()/has() - has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function htmlTagLocatorGetSetHasHas(UnitTester $I)
    {
        $I->wantToTest('Html\TagLocator - get()/set()/has() - has()');
        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new TagLocator($services);

        $actual = $locator->has('helloFilter');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Html\TagLocator :: get()/set()/has() - get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function serviceLocatorGetSetHasGet(UnitTester $I)
    {
        $I->wantToTest('Html\TagLocator - get()/set()/has() - get()');
        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new TagLocator($services);
        $actual  = $locator->has('helloFilter');
        $I->assertTrue($actual);

        $class  = HelloService::class;
        $actual = $locator->get('helloFilter');
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Html\TagLocator :: get()/set()/has() - get() same
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function serviceLocatorGetSetHasGetSame(UnitTester $I)
    {
        $I->wantToTest('Html\TagLocator - get()/set()/has() - get() - same');
        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new TagLocator($services);
        $actual  = $locator->has('helloFilter');
        $I->assertTrue($actual);

        /** @var object $service */
        $expected = 'Hello Phalcon [count: 1]';
        $actual   = $locator->get('helloFilter')('Phalcon');
        $I->assertEquals($expected, $actual);

        $expected = 'Hello Phalcon [count: 2]';
        $actual   = $locator->get('helloFilter')('Phalcon');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\TagLocator :: get()/set()/has() - set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function serviceLocatorGetSetHasSet(UnitTester $I)
    {
        $I->wantToTest('Html\TagLocator - get()/set()/has() - set()');
        $locator = new TagLocator();

        $actual = $locator->has('helloFilter');
        $I->assertFalse($actual);

        $locator->set(
            'helloFilter',
            function () {
                return new HelloService();
            }
        );
        $actual = $locator->has('helloFilter');
        $I->assertTrue($actual);
    }
}
