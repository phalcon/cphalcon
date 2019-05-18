<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Annotations\Adapter;

use function dataDir;
use Phalcon\Annotations\Adapter\Memory;
use UnitTester;

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

        $classAnnotations = $adapter->get('TestClass');

        $I->assertInternalType('object', $classAnnotations);

        $I->assertInstanceOf(
            \Phalcon\Annotations\Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            \Phalcon\Annotations\Collection::class,
            $classAnnotations->getClassAnnotations()
        );

        $classAnnotations = $adapter->get('TestClass');

        $I->assertInternalType('object', $classAnnotations);

        $I->assertInstanceOf(
            \Phalcon\Annotations\Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            \Phalcon\Annotations\Collection::class,
            $classAnnotations->getClassAnnotations()
        );

        $classAnnotations = $adapter->get('User\TestClassNs');

        $I->assertInternalType('object', $classAnnotations);

        $I->assertInstanceOf(
            \Phalcon\Annotations\Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            \Phalcon\Annotations\Collection::class,
            $classAnnotations->getClassAnnotations()
        );

        $classAnnotations = $adapter->get('User\TestClassNs');

        $I->assertInternalType('object', $classAnnotations);

        $I->assertInstanceOf(
            \Phalcon\Annotations\Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            \Phalcon\Annotations\Collection::class,
            $classAnnotations->getClassAnnotations()
        );

        $property = $adapter->getProperty('TestClass', 'testProp1');

        $I->assertInternalType('object', $property);

        $I->assertInstanceOf(
            \Phalcon\Annotations\Collection::class,
            $property
        );

        $I->assertEquals(
            4,
            $property->count()
        );
    }
}
