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
use Phalcon\Annotations\Adapter\AdapterInterface;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reflection;
use Phalcon\Tests\Fixtures\Traits\AnnotationsTrait;
use TestClass;
use UnitTester;
use User\TestClassNs;

use function dataDir;
use function is_object;

class ConstructCest
{
    use AnnotationsTrait;

    /**
     * Tests Phalcon\Annotations\Adapter :: __construct()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-12-30
     */
    public function annotationsAdapterConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Annotations\Adapter __construct()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $class   = $example['class'];
        $params  = $example['params'];
        $adapter = new $class($params);

        $expected = AdapterInterface::class;
        $actual   = $adapter;
        $I->assertInstanceOf($expected, $actual);
    }

    /**
     * Tests Phalcon\Annotations\Adapter ::
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-12-30
     */
    public function annotationsAdapter(UnitTester $I, Example $example)
    {
        $I->wantToTest('Annotations\Adapter');

        $I->seeFileFound(
            dataDir('fixtures/Annotations/TestClass.php')
        );

        $I->seeFileFound(
            dataDir('fixtures/Annotations/TestClassNs.php')
        );

        require_once dataDir('fixtures/Annotations/TestClass.php');
        require_once dataDir('fixtures/Annotations/TestClassNs.php');

        $class   = $example['class'];
        $params  = $example['params'];
        $adapter = new $class($params);

        $classAnnotations = $adapter->get(TestClass::class);

        $actual = is_object($classAnnotations);
        $I->assertTrue($actual);

        $expected = Reflection::class;
        $actual   = $classAnnotations;
        $I->assertInstanceOf($expected, $actual);

        $expected = Collection::class;
        $actual   = $classAnnotations->getClassAnnotations();
        $I->assertInstanceOf($expected, $actual);

        $classAnnotations = $adapter->get(TestClassNs::class);

        $actual = is_object($classAnnotations);
        $I->assertTrue($actual);

        $expected = Reflection::class;
        $actual   = $classAnnotations;
        $I->assertInstanceOf($expected, $actual);

        $expected = Collection::class;
        $actual   = $classAnnotations->getClassAnnotations();
        $I->assertInstanceOf($expected, $actual);


        $property = $adapter->getProperty(
            TestClass::class,
            'testProp1'
        );

        $actual = is_object($property);
        $I->assertTrue($actual);

        $expected = Collection::class;
        $actual   = $property;
        $I->assertInstanceOf($expected, $actual);

        $expected = 4;
        $actual   = $property->count();
        $I->assertSame($expected, $actual);
    }
}
