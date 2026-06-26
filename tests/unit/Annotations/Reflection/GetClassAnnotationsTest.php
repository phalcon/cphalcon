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

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reader;
use Phalcon\Annotations\Reflection;
use Phalcon\Tests\AbstractUnitTestCase;

use function dataDir;

final class GetClassAnnotationsTest extends AbstractUnitTestCase
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
     * @since  2016-01-26
     */
    public function testAnnotationsReflectionGetClassAnnotations(): void
    {
        $reader = new Reader();

        $reflection       = new Reflection($reader->parse('TestClass'));
        $classAnnotations = $reflection->getClassAnnotations();

        $this->assertInstanceOf(Collection::class, $classAnnotations);

        $number = 0;

        foreach ($classAnnotations as $annotation) {
            $this->assertInstanceOf(Annotation::class, $annotation);
            $number++;
        }

        $this->assertEquals(9, $number);
        $this->assertCount(9, $classAnnotations);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-26
     */
    public function testAnnotationsReflectionGetClassAnnotationsEmpty(): void
    {
        $reflection = new Reflection();

        $this->assertNull($reflection->getClassAnnotations());
    }
}
