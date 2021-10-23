<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Filter\Filter;

use Closure;
use Phalcon\Filter\Filter;
use Phalcon\Tests\Fixtures\Service\HelloService;
use UnitTester;

class GetSetHasCest
{
    /**
     * Tests Phalcon\Filter :: get()/set()/has() - has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
     * Tests Phalcon\Filter :: get()/set()/has() - get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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

        $class  = Closure::class;
        $actual = $locator->get('helloFilter');
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Filter :: get()/set()/has() - get() same
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function filterFilterGetSetHasGetSame(UnitTester $I)
    {
        $I->wantToTest('Filter\Filter - get()/set()/has() - get() - same');

        $locator = new Filter(['helloFilter' => HelloService::class]);
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
     * Tests Phalcon\Filter :: get()/set()/has() - set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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

    /**
     * Tests Phalcon\Filter :: get()/set()/has() - set() closure
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function filterFilterGetSetHasSetClosure(UnitTester $I)
    {
        $I->wantToTest('Filter\Filter - get()/set()/has() - set() closure');
        $locator = new Filter();

        $actual = $locator->has('testappend');
        $I->assertFalse($actual);

        $locator->set(
            'testappend',
            function ($input) {
                return $input . 'test';
            }
        );

        $value  = 'cheese';
        $actual = $locator->sanitize($value, 'testappend');

        $expected = $value . 'test';
        $I->assertEquals($expected, $actual);
    }
}
