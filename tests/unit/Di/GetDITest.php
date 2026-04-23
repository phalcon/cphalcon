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

use Phalcon\Di\Di;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Di\InjectableComponent;
use ReflectionClass;
use ReflectionException;
use stdClass;

final class GetDITest extends AbstractUnitTestCase
{
    /**
     * @author Stijn Leenknegt <stijn@diagro.be>
     * @since  2020-08-13
     */
    public function testDiInjectableGetDIContainer(): void
    {
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

        $className  = get_class($ic);
        $reflection = new ReflectionClass($className);
        $prop       = $reflection->getProperty('container');
        $prop->setAccessible(true);

        $this->assertSame($di, $prop->getValue($ic));
    }

    /**
     * @author Stijn Leenknegt <stijn@diagro.be>
     * @since  2020-08-13
     */
    public function testDiInjectableGetDIOtherContainer(): void
    {
        Di::reset();

        $di    = new Di();
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

        $className  = get_class($ic);
        $reflection = new ReflectionClass($className);

        $prop = $reflection->getProperty('container');
        $prop->setAccessible(true);

        $this->assertSame($other, $prop->getValue($ic));
        $this->assertNotEquals($di, $prop->getValue($ic));
    }
}
