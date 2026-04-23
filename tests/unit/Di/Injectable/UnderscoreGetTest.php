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

use Phalcon\Di\Di;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Di\InjectableComponent;
use stdClass;

use function spl_object_hash;

final class UnderscoreGetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiInjectableUnderscoreGetException(): void
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $this->markTestSkipped('Need to fix Windows new lines...');
        }

        Di::reset();
        $container = new Di();

        $container->set('component', InjectableComponent::class);

        $component = $container->get('component');

        $expected = 'Access to undefined property unknown';
        $actual   = '';
        set_error_handler(
            function (int $errno, string $errstr) use (&$actual): bool {
                $actual = $errstr;

                return true;
            },
            E_USER_NOTICE
        );
        $result = $component->unknown;
        restore_error_handler();
        $this->assertStringContainsString($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDiInjectableUnderscoreGetPersistent(): void
    {
        Di::reset();
        $container = new Di();

        // Register sessionBag as a closure that receives the class name
        $container->set(
            'sessionBag',
            function (string $name): stdClass {
                $obj       = new stdClass();
                $obj->name = $name;

                return $obj;
            }
        );

        $container->set('component', InjectableComponent::class);

        /** @var InjectableComponent $component */
        $component  = $container->get('component');
        $persistent = $component->persistent;

        $class = stdClass::class;
        $this->assertInstanceOf($class, $persistent);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiInjectableUnderscoreGetIsset(): void
    {
        Di::reset();
        $container = new Di();

        $stdClass = function () {
            return new stdClass();
        };

        $container->set('std', $stdClass);
        $container->set('component', InjectableComponent::class);

        $component = $container->get('component');
        $actual    = $component->getDI();
        $this->assertSame($container, $actual);

        $class  = stdClass::class;
        $actual = $component->std;
        $this->assertInstanceOf($class, $actual);

        $expected = spl_object_hash($container);
        $actual   = spl_object_hash($component->di);
        $this->assertSame($expected, $actual);

        $actual = isset($component->di);
        $this->assertTrue($actual);

        $actual = isset($component->component);
        $this->assertTrue($actual);

        $actual = isset($component->std);
        $this->assertTrue($actual);
    }
}
