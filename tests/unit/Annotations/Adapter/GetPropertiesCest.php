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

class GetPropertiesCest
{
    use AnnotationsTrait;

    /**
     * Tests Phalcon\Annotations\Adapter :: getProperties()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-12-30
     */
    public function annotationsAdapterGetProperties(
        UnitTester $I,
        Example $example
    ) {
        $I->wantToTest('Annotations\Adapter getProperties()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $class   = $example['class'];
        $params  = $example['params'];
        $adapter = new $class($params);

        $propertyAnnotations = $adapter->getProperties(TestClass::class);

        $keys     = array_keys($propertyAnnotations);
        $expected = [
            'testProp1',
            'testProp3',
            'testProp4',
        ];
        $actual   = $keys;
        $I->assertSame($expected, $actual);

        foreach ($propertyAnnotations as $propertyAnnotation) {
            $expected = Collection::class;
            $actual   = $propertyAnnotation;
            $I->assertInstanceOf($expected, $actual);
        }

        $I->safeDeleteFile('testclass.php');
    }
}
