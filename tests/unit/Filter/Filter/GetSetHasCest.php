<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Filter;

use Phalcon\Filter\Filter;
use Phalcon\Test\Fixtures\Service\HelloService;
use UnitTester;

class GetSetHasCest
{
    /**
     * Tests Phalcon\Filter\Filter :: get()/set()/has() - has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function filterFilterGetSetHasHas(UnitTester $I)
    {
        $I->wantToTest('Filter\Filter - get()/set()/has() - has()');
        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new Filter($services);

        $actual = $locator->has('helloFilter');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Filter\Filter :: get()/set()/has() - get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterFilterLocatorGetSetHasGet(UnitTester $I)
    {
        $I->wantToTest('Filter\Filter - get()/set()/has() - get()');
        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new Filter($services);
        $actual  = $locator->has('helloFilter');
        $I->assertTrue($actual);

        $class  = HelloService::class;
        $actual = $locator->get('helloFilter');
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Filter\Filter :: get()/set()/has() - get() same
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterFilterGetSetHasGetSame(UnitTester $I)
    {
        $I->wantToTest('Filter\Filter - get()/set()/has() - get() - same');
        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new Filter($services);
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
     * Tests Phalcon\Filter\Filter :: get()/set()/has() - set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterFilterGetSetHasSet(UnitTester $I)
    {
        $I->wantToTest('Filter\Filter - get()/set()/has() - set()');
        $locator = new Filter();

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
