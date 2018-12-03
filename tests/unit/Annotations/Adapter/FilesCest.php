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

use Phalcon\Annotations\Adapter\Files;
use UnitTester;
use function outputFolder;

class FilesCest
{
    public function testFilesAdapter(UnitTester $I)
    {
        require_once dataFolder('fixtures/Annotations/TestClass.php');
        require_once dataFolder('fixtures/Annotations/TestClassNs.php');

        $adapter = new Files(['annotationsDir' => outputFolder('tests/annotations/')]);

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

        unset($adapter);

        $I->amInPath(outputFolder('tests/annotations/'));

        $I->safeDeleteFile('testclass.php');
        $I->safeDeleteFile('user_testclassns.php');
    }
}
