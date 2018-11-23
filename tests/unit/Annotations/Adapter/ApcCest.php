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

use Phalcon\Annotations\Adapter\Apc;
use UnitTester;

class ApcCest
{
    /**
     * executed before each test
     */
    public function _before(UnitTester $I, $scanario)
    {
        if (!extension_loaded('apc')) {
            $scanario->skip('Warning: apc extension is not loaded');
        }

        require_once PATH_DATA . 'fixtures/Annotations/TestClass.php';
        require_once PATH_DATA . 'fixtures/Annotations/TestClassNs.php';
    }

    public function testApcAdapter(UnitTester $I)
    {
        $adapter = new Apc();

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
