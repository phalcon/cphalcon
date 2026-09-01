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

namespace Phalcon\Tests\Unit\Annotations;

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reader;
use Phalcon\Annotations\Reflection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

final class ReflectionTest extends AbstractUnitTestCase
{
    /**
     * @return void
     */
    protected function setUp(): void
    {
        parent::setUp();

        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-26
     */
    public function testAnnotationsReflection(): void
    {
        $reader = new Reader();

        $reflection = new Reflection($reader->parse('TestClass'));

        $constantsAnnotations = $reflection->getConstantsAnnotations();
        $this->assertIsArray($constantsAnnotations);

        $annotations = $constantsAnnotations['TEST_CONST1'];
        $this->assertInstanceOf(Collection::class, $annotations);
        $this->assertTrue($annotations->has('Simple'));

        $methodsAnnotations = $reflection->getMethodsAnnotations();
        $this->assertIsArray($methodsAnnotations);
        $this->assertInstanceOf(
            Collection::class,
            $methodsAnnotations['testMethod1']
        );

        $total = 0;

        foreach ($methodsAnnotations as $method => $annotations) {
            $this->assertIsString($method);

            $number = 0;

            foreach ($annotations as $annotation) {
                $this->assertInstanceOf(Annotation::class, $annotation);
                $number++;
                $total++;
            }

            $this->assertGreaterThan(0, $number);
        }

        $this->assertEquals(14, $total);

        /** @var Collection $annotations */
        $annotations = $methodsAnnotations['testMethod1'];

        $this->assertTrue($annotations->has('Simple'));
        $this->assertFalse($annotations->has('NoSimple'));

        $annotation = $annotations->get('Simple');
        $this->assertEquals('Simple', $annotation->getName());
        $this->assertEquals([], $annotation->getArguments());
        $this->assertEquals(0, $annotation->numberArguments());
        $this->assertFalse($annotation->hasArgument('none'));

        $annotation = $annotations->get('NamedMultipleParams');
        $this->assertEquals('NamedMultipleParams', $annotation->getName());
        $this->assertEquals(2, $annotation->numberArguments());
        $this->assertEquals(
            ['first' => 'First', 'second' => 'Second'],
            $annotation->getArguments()
        );
        $this->assertTrue($annotation->hasArgument('first'));
        $this->assertEquals('First', $annotation->getArgument('first'));
        $this->assertFalse($annotation->hasArgument('none'));

        $propertiesAnnotations = $reflection->getPropertiesAnnotations();
        $this->assertIsArray($propertiesAnnotations);
        $this->assertInstanceOf(
            Collection::class,
            $propertiesAnnotations['testProp1']
        );

        $total = 0;

        foreach ($propertiesAnnotations as $property => $annotations) {
            $this->assertInstanceOf(
                Collection::class,
                $propertiesAnnotations['testProp1']
            );

            $number = 0;

            foreach ($annotations as $annotation) {
                $this->assertInstanceOf(Annotation::class, $annotation);
                $number++;
                $total++;
            }

            $this->assertGreaterThan(0, $number);
        }

        $this->assertEquals(10, $total);
    }
}
