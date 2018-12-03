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

use Phalcon\Annotations\Adapter\Memory;
use UnitTester;
use function dataFolder;
use function file_exists;

class MemoryCest
{
    public function testMemoryAdapter(UnitTester $I)
    {
        $I->assertTrue(file_exists(dataFolder('fixtures/Annotations/TestClass.php')));
        $I->assertTrue(file_exists(dataFolder('fixtures/Annotations/TestClassNs.php')));

        require_once dataFolder('fixtures/Annotations/TestClass.php');
        require_once dataFolder('fixtures/Annotations/TestClassNs.php');

        $adapter = new Memory();

        $classAnnotations = $adapter->get('TestClass');
        $I->assertInternalType('object', $classAnnotations);
        $I->assertInstanceOf('Phalcon\Annotations\Reflection', $classAnnotations);
        $I->assertInstanceOf('Phalcon\Annotations\Collection', $classAnnotations->getClassAnnotations());

        $classAnnotations = $adapter->get('TestClass');
        $I->assertInternalType('object', $classAnnotations);
        $I->assertInstanceOf('Phalcon\Annotations\Reflection', $classAnnotations);
        $I->assertInstanceOf('Phalcon\Annotations\Collection', $classAnnotations->getClassAnnotations());

        $classAnnotations = $adapter->get('User\TestClassNs');
        $I->assertInternalType('object', $classAnnotations);
        $I->assertInstanceOf('Phalcon\Annotations\Reflection', $classAnnotations);
        $I->assertInstanceOf('Phalcon\Annotations\Collection', $classAnnotations->getClassAnnotations());

        $classAnnotations = $adapter->get('User\TestClassNs');
        $I->assertInternalType('object', $classAnnotations);
        $I->assertInstanceOf('Phalcon\Annotations\Reflection', $classAnnotations);
        $I->assertInstanceOf('Phalcon\Annotations\Collection', $classAnnotations->getClassAnnotations());

        $property = $adapter->getProperty('TestClass', 'testProp1');
        $I->assertInternalType('object', $property);
        $I->assertInstanceOf('Phalcon\Annotations\Collection', $property);
        $I->assertEquals($property->count(), 4);
    }
}
