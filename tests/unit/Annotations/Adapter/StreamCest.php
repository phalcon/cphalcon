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

use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reflection;
use TestClass;
use UnitTester;
use User\TestClassNs;
use function outputDir;

class StreamCest
{
    public function testStreamAdapter(UnitTester $I)
    {
        require_once dataDir('fixtures/Annotations/TestClass.php');
        require_once dataDir('fixtures/Annotations/TestClassNs.php');

        $adapter = new Stream(
            [
                'annotationsDir' => outputDir('tests/annotations/'),
            ]
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

        unset($adapter);

        $I->amInPath(
            outputDir('tests/annotations/')
        );

        $I->safeDeleteFile('testclass.php');
        $I->safeDeleteFile('user_testclassns.php');
    }
}
