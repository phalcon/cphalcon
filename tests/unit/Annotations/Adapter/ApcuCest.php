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

use Phalcon\Annotations\Adapter\Apcu;
use UnitTester;

class ApcuCest
{
    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('apcu');

        require_once dataDir('fixtures/Annotations/TestClass.php');
        require_once dataDir('fixtures/Annotations/TestClassNs.php');
    }

    public function testApcAdapter(UnitTester $I)
    {
        $adapter = new Apcu();

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

        $I->assertEquals(4, $property->count());
    }
}
