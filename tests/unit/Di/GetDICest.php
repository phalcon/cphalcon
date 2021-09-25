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

namespace Phalcon\Tests\Unit\Di;

use InjectableComponent;
use Phalcon\Di;
use ReflectionClass;
use ReflectionException;
use stdClass;
use UnitTester;

final class GetDICest
{
    /**
     * Unit Tests Phalcon\Di\Injectable :: getDI()
     *
     * Test when an Injectable object has no DI set and a call has been made to getDI(),
     * should set the container property.
     * It's tested with the Controller class
     *
     * @throws ReflectionException
     * @since  2020-08-13
     * @author Stijn Leenknegt <stijn@diagro.be>
     */
    public function diInjectableGetDIContainer(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - getDI()');

        require_once dataDir('fixtures/Di/InjectableComponent.php');

        Di::reset();

        $di = new Di();
        $di->set('std', function () {
            return new stdClass();
        });

        // No DI is set in this Injectable object
        $ic = new InjectableComponent();

        /**
         * Calls __get which calls getDI() method,
         * which should not set the container to
         * the default DI
         */
        $std = $ic->std;

        $className = get_class($ic);
        $reflection = new ReflectionClass($className);
        $prop = $reflection->getProperty('container');
        $prop->setAccessible(true);

        $I->assertEquals($di, $prop->getValue($ic));
    }

    /**
     * Unit Tests Phalcon\Di\Injectable :: getDI()
     *
     * Test when an Injectable object has set another DI.
     * Setting the container to the default DI, should not happen!
     *
     * @throws ReflectionException
     * @since  2020-08-13
     * @author Stijn Leenknegt <stijn@diagro.be>
     */
    public function diInjectableGetDIOtherContainer(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - getDI()');

        require_once dataDir('fixtures/Di/InjectableComponent.php');

        Di::reset();

        $di = new Di();
        $other = new Di();
        $other->set('std', function () {
            return new stdClass();
        });

        // No DI is set in this Injectable object
        $ic = new InjectableComponent();
        $ic->setDI($other);

        /**
         * Calls __get which calls getDI() method,
         * which should not set the container to
         * the default DI
         */
        $std = $ic->std;

        $className = get_class($ic);
        $reflection = new ReflectionClass($className);

        $prop = $reflection->getProperty('container');
        $prop->setAccessible(true);

        $I->assertEquals($other, $prop->getValue($ic));
        $I->assertNotEquals($di, $prop->getValue($ic));
    }
}
