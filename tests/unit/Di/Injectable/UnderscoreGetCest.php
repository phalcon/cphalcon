<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Di\Injectable;

use Exception;
use Phalcon\Di;
use Phalcon\Tests\Fixtures\Di\InjectableComponent;
use stdClass;
use UnitTester;

use function spl_object_hash;

class UnderscoreGetCest
{
    /**
     * Unit Tests Phalcon\Di\Injectable :: __get()/__isset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diInjectableUnderscoreGetIsset(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - __get()/__isset()');

        Di::reset();
        $container = new Di();

        $stdClass = function () {
            return new stdClass();
        };

        $container->set('std', $stdClass);
        $container->set('component', InjectableComponent::class);

        $component = $container->get('component');
        $actual    = $component->getDI();
        $I->assertEquals($container, $actual);

        $class  = stdClass::class;
        $actual = $component->std;
        $I->assertInstanceOf($class, $actual);

        $expected = spl_object_hash($container);
        $actual   = spl_object_hash($component->di);
        $I->assertEquals($expected, $actual);

        $actual = isset($component->di);
        $I->assertTrue($actual);

        $actual = isset($component->component);
        $I->assertTrue($actual);

        $actual = isset($component->std);
        $I->assertTrue($actual);
    }

    /**
     * Unit Tests Phalcon\Di\Injectable :: __get() - exception
     *
     * @param UnitTester $I
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diInjectableUnderscoreGetException(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - __get() - exception');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        Di::reset();
        $container = new Di();

        $container->set('component', InjectableComponent::class);

        $component = $container->get('component');

        $I->expectThrowable(
            new Exception(
                'Access to undefined property unknown at ' .
                'tests/unit/Di/Injectable/UnderscoreGetCest.php:102',
                1024
            ),
            function () use ($component) {
                $result = $component->unknown;
            }
        );
    }
}
