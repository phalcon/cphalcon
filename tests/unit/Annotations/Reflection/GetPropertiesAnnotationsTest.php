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

final class GetPropertiesAnnotationsTest extends AbstractUnitTestCase
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
    public function testAnnotationsReflectionGetPropertiesAnnotations(): void
    {
        $reader     = new Reader();
        $reflection = new Reflection($reader->parse('TestClass'));

        $propertiesAnnotations = $reflection->getPropertiesAnnotations();

        $this->assertIsArray($propertiesAnnotations);

        $number = 0;

        foreach ($propertiesAnnotations as $annotation) {
            $this->assertInstanceOf(Collection::class, $annotation);
            $number++;
        }

        $this->assertEquals(3, $number);
        $this->assertCount(3, $propertiesAnnotations);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-26
     */
    public function testAnnotationsReflectionGetPropertiesAnnotationsEmpty(): void
    {
        $reflection = new Reflection();

        $this->assertIsArray($reflection->getPropertiesAnnotations());
        $this->assertEmpty($reflection->getPropertiesAnnotations());
    }
}
