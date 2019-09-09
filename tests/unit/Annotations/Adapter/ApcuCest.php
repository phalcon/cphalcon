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

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reflection;
use TestClass;
use UnitTester;
use User\TestClassNs;

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

        $classAnnotations = $adapter->get(
            TestClass::class
        );

        $I->assertInternalType('object', $classAnnotations);

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

        $I->assertInternalType('object', $classAnnotations);

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

        $I->assertInternalType('object', $classAnnotations);

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

        $I->assertInternalType('object', $classAnnotations);

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

        $I->assertInternalType('object', $property);

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
