<?php

namespace Phalcon\Test\Unit\Annotations;

use Phalcon\Annotations\Reader;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Annotations\Reflection;

/**
 * \Phalcon\Test\Unit\Annotations\ReflectionTest
 * Tests for \Phalcon\Annotations\Reflection component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Annotations
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ReflectionTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();
        require_once PATH_DATA . 'annotations/TestClass.php';
    }

    /**
     * Tests creating empty Reflection object
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-26
     */
    public function testEmptyReflection()
    {
        $this->specify(
            'Incorrect initialization Reflection object without $reflectionData parameter',
            function () {
                $reflection = new Reflection();

                expect($reflection->getClassAnnotations())->equals(null);
                expect($reflection->getMethodsAnnotations())->equals(null);
                expect($reflection->getPropertiesAnnotations())->equals(null);
            }
        );
    }

    /**
     * Tests parsing a real class
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-26
     */
    public function testParsingARealClass()
    {
        $this->specify(
            'Parsing a real class does not return correct result',
            function () {
                $reader = new Reader();
                $reflection = new Reflection($reader->parse('TestClass'));

                $classAnnotations = $reflection->getClassAnnotations();
                expect(get_class($classAnnotations))->equals('Phalcon\Annotations\Collection');

                $number = 0;
                foreach ($classAnnotations as $annotation) {
                    expect(get_class($annotation))->equals('Phalcon\Annotations\Annotation');
                    $number++;
                }

                expect($number)->equals(9);
                expect($classAnnotations)->count(9);
            }
        );
    }

    /**
     * Tests parsing class annotations
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-26
     */
    public function testClassAnnotations()
    {
        $this->specify(
            'Reflection does not parse annotations correctly',
            function () {
                $reader = new Reader();
                $reflection = new Reflection($reader->parse('TestClass'));

                $methodsAnnotations = $reflection->getMethodsAnnotations();

                expect(gettype($methodsAnnotations))->equals('array');
                expect(get_class($methodsAnnotations['testMethod1']))->equals('Phalcon\Annotations\Collection');

                $total = 0;
                foreach ($methodsAnnotations as $method => $annotations) {
                    expect(gettype($method))->equals('string');

                    $number = 0;
                    foreach ($annotations as $annotation) {
                        expect(get_class($annotation))->equals('Phalcon\Annotations\Annotation');
                        $number++;
                        $total++;
                    }
                    expect($number > 0)->true();
                }

                expect($total)->equals(14);

                /** @var \Phalcon\Annotations\Collection $annotations */
                $annotations = $methodsAnnotations['testMethod1'];

                expect($annotations->has('Simple'))->true();
                expect($annotations->has('NoSimple'))->false();

                $annotation = $annotations->get('Simple');
                expect($annotation->getName())->equals('Simple');
                expect($annotation->getArguments())->equals(null);
                expect($annotation->numberArguments())->equals(0);
                expect($annotation->hasArgument('none'))->false();

                $annotation = $annotations->get('NamedMultipleParams');
                expect($annotation->getName())->equals('NamedMultipleParams');
                expect($annotation->numberArguments())->equals(2);
                expect($annotation->getArguments())->equals(['first' => 'First', 'second' => 'Second']);
                expect($annotation->hasArgument('first'))->true();
                expect($annotation->getArgument('first'))->equals('First');
                expect($annotation->hasArgument('none'))->false();

                $propertiesAnnotations = $reflection->getPropertiesAnnotations();
                expect(is_array($propertiesAnnotations))->true();
                expect(get_class($propertiesAnnotations['testProp1']))->equals('Phalcon\Annotations\Collection');

                $total = 0;
                foreach ($propertiesAnnotations as $property => $annotations) {
                    expect(get_class($propertiesAnnotations['testProp1']))->equals('Phalcon\Annotations\Collection');

                    $number = 0;
                    foreach ($annotations as $annotation) {
                        expect(get_class($annotation))->equals('Phalcon\Annotations\Annotation');
                        $number++;
                        $total++;
                    }

                    expect($number > 0)->true();
                }

                expect($total)->equals(10);
            }
        );
    }
}
