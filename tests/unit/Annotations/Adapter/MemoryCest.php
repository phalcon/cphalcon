<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Annotations\Adapter;

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reflection;
use TestClass;
use UnitTester;
use User\TestClassNs;

use function dataDir;

class MemoryCest
{
    public function testMemoryAdapter(UnitTester $I)
    {
        $I->seeFileFound(
            dataDir('fixtures/Annotations/TestClass.php')
        );

        $I->seeFileFound(
            dataDir('fixtures/Annotations/TestClassNs.php')
        );

        require_once dataDir('fixtures/Annotations/TestClass.php');
        require_once dataDir('fixtures/Annotations/TestClassNs.php');

        $adapter = new Memory();

        $classAnnotations = $adapter->get(
            TestClass::class
        );

        $I->assertTrue(is_object($classAnnotations));

        $I->assertInstanceOf(
            Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            Collection::class,
            $classAnnotations->getClassAnnotations()
        );

        $classAnnotations = $adapter->get(
            TestClass::class
        );

        $I->assertTrue(is_object($classAnnotations));

        $I->assertInstanceOf(
            Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            Collection::class,
            $classAnnotations->getClassAnnotations()
        );

        $classAnnotations = $adapter->get(
            TestClassNs::class
        );

        $I->assertTrue(is_object($classAnnotations));

        $I->assertInstanceOf(
            Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            Collection::class,
            $classAnnotations->getClassAnnotations()
        );

        $classAnnotations = $adapter->get(
            TestClassNs::class
        );

        $I->assertTrue(is_object($classAnnotations));

        $I->assertInstanceOf(
            Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            Collection::class,
            $classAnnotations->getClassAnnotations()
        );

        $property = $adapter->getProperty(
            TestClass::class,
            'testProp1'
        );

        $I->assertTrue(is_object($property));

        $I->assertInstanceOf(
            Collection::class,
            $property
        );

        $I->assertEquals(
            4,
            $property->count()
        );
    }
}
