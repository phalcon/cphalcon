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

use Codeception\Example;
use Phalcon\Annotations\Reflection;
use Phalcon\Tests\Fixtures\Traits\AnnotationsTrait;
use TestClass;
use UnitTester;

use function dataDir;
use function outputDir;

class ReadWriteCest
{
    use AnnotationsTrait;

    /**
     * Tests Phalcon\Annotations\Adapter :: read()/write()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-12-30
     */
    public function annotationsAdapterReadWrite(UnitTester $I, Example $example)
    {
        $I->wantToTest('Annotations\Adapter read()/write()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $class   = $example['class'];
        $params  = $example['params'];
        $adapter = new $class($params);

        $classAnnotations = $adapter->get(TestClass::class);

        $adapter->write('testwrite', $classAnnotations);

        $I->assertFileExists(
            outputDir('tests/annotations/testclass.php')
        );

        $newClass = $adapter->read('testwrite');
        $expected = Reflection::class;
        $actual   = $newClass;
        $I->assertInstanceOf($expected, $actual);

        $I->safeDeleteFile('testwrite.php');
        $I->safeDeleteFile('testclass.php');
    }
}
