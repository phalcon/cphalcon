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
use Phalcon\Annotations\Collection;
use Phalcon\Tests\Fixtures\Traits\AnnotationsTrait;
use TestClass;
use UnitTester;

use function array_keys;
use function dataDir;

class GetMethodsCest
{
    use AnnotationsTrait;

    /**
     * Tests Phalcon\Annotations\Adapter :: getMethods()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-12-30
     */
    public function annotationsAdapterGetMethods(
        UnitTester $I,
        Example $example
    ) {
        $I->wantToTest('Annotations\Adapter getMethods()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $class   = $example['class'];
        $params  = $example['params'];
        $adapter = new $class($params);

        $methodAnnotations = $adapter->getMethods(
            TestClass::class
        );

        $keys     = array_keys($methodAnnotations);
        $expected = [
            'testMethod1',
            'testMethod3',
            'testMethod4',
            'testMethod5',
        ];
        $actual   = $keys;
        $I->assertSame($expected, $actual);

        foreach ($methodAnnotations as $methodAnnotation) {
            $expected = Collection::class;
            $actual   = $methodAnnotation;
            $I->assertInstanceOf($expected, $actual);
        }

        $I->safeDeleteFile('testclass.php');
    }
}
