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

use function outputDir;
use Phalcon\Annotations\Adapter\Stream;
use UnitTester;

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
            \TestClass::class
        );

        $I->assertInternalType('object', $classAnnotations);

        $I->assertInstanceOf(
            \Phalcon\Annotations\Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            \Phalcon\Annotations\Collection::class,
            $classAnnotations->getClassAnnotations()
        );



        $classAnnotations = $adapter->get(
            \TestClass::class
        );

        $I->assertInternalType('object', $classAnnotations);

        $I->assertInstanceOf(
            \Phalcon\Annotations\Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            \Phalcon\Annotations\Collection::class,
            $classAnnotations->getClassAnnotations()
        );



        $classAnnotations = $adapter->get(
            \User\TestClassNs::class
        );

        $I->assertInternalType('object', $classAnnotations);

        $I->assertInstanceOf(
            \Phalcon\Annotations\Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            \Phalcon\Annotations\Collection::class,
            $classAnnotations->getClassAnnotations()
        );



        $classAnnotations = $adapter->get(
            \User\TestClassNs::class
        );

        $I->assertInternalType('object', $classAnnotations);

        $I->assertInstanceOf(
            \Phalcon\Annotations\Reflection::class,
            $classAnnotations
        );

        $I->assertInstanceOf(
            \Phalcon\Annotations\Collection::class,
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
