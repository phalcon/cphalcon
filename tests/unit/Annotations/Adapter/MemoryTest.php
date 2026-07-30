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

namespace Phalcon\Tests\Unit\Annotations\Adapter;

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reflection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use TestClass;
use User\TestClassNs;

final class MemoryTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAnnotationsAdapterMemory(): void
    {
        $this->assertFileExists(Talon::settings()->supportPath('assets/Annotations/TestClass.php'));
        $this->assertFileExists(Talon::settings()->supportPath('assets/Annotations/TestClassNs.php'));

        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');
        require_once Talon::settings()->supportPath('assets/Annotations/TestClassNs.php');

        $adapter = new Memory();

        $classAnnotations = $adapter->get(TestClass::class);

        $this->assertTrue(is_object($classAnnotations));
        $this->assertInstanceOf(Reflection::class, $classAnnotations);
        $this->assertInstanceOf(Collection::class, $classAnnotations->getClassAnnotations());

        $classAnnotations = $adapter->get(TestClass::class);

        $this->assertTrue(is_object($classAnnotations));
        $this->assertInstanceOf(Reflection::class, $classAnnotations);
        $this->assertInstanceOf(Collection::class, $classAnnotations->getClassAnnotations());

        $classAnnotations = $adapter->get(TestClassNs::class);

        $this->assertTrue(is_object($classAnnotations));
        $this->assertInstanceOf(Reflection::class, $classAnnotations);
        $this->assertInstanceOf(Collection::class, $classAnnotations->getClassAnnotations());

        $classAnnotations = $adapter->get(TestClassNs::class);

        $this->assertTrue(is_object($classAnnotations));
        $this->assertInstanceOf(Reflection::class, $classAnnotations);
        $this->assertInstanceOf(Collection::class, $classAnnotations->getClassAnnotations());

        $property = $adapter->getProperty(TestClass::class, 'testProp1');

        $this->assertTrue(is_object($property));
        $this->assertInstanceOf(Collection::class, $property);
        $this->assertEquals(4, $property->count());
    }
}
