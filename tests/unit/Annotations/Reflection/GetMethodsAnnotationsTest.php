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

namespace Phalcon\Tests\Unit\Annotations\Reflection;

use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reader;
use Phalcon\Annotations\Reflection;
use Phalcon\Tests\AbstractUnitTestCase;

use function dataDir;

final class GetMethodsAnnotationsTest extends AbstractUnitTestCase
{
    /**
     * @return void
     */
    protected function setUp(): void
    {
        parent::setUp();

        require_once supportDir('assets/Annotations/TestClass.php');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-21
     */
    public function testAnnotationsReflectionGetMethodsAnnotations(): void
    {
        $reader     = new Reader();
        $reflection = new Reflection($reader->parse('TestClass'));

        $methodsAnnotations = $reflection->getMethodsAnnotations();

        $this->assertIsArray($methodsAnnotations);

        $number = 0;

        foreach ($methodsAnnotations as $annotation) {
            $this->assertInstanceOf(Collection::class, $annotation);
            $number++;
        }

        $this->assertEquals(4, $number);
        $this->assertCount(4, $methodsAnnotations);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-26
     */
    public function testAnnotationsReflectionGetMethodsAnnotationsEmpty(): void
    {
        $reflection = new Reflection();

        $this->assertIsArray($reflection->getMethodsAnnotations());
        $this->assertEmpty($reflection->getMethodsAnnotations());
    }
}
