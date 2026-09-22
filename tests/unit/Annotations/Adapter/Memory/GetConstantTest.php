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

namespace Phalcon\Tests\Unit\Annotations\Adapter\Memory;

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\Collection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use TestClass;

final class GetConstantTest extends AbstractUnitTestCase
{
    /**
     * A constant with a docblock gives its annotations. A constant without
     * one, and a name that does not exist, give an empty collection.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    public function testAnnotationsAdapterMemoryGetConstant(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $adapter = new Memory();

        $constant = $adapter->getConstant(TestClass::class, 'TEST_CONST1');
        $this->assertInstanceOf(Collection::class, $constant);
        $this->assertTrue($constant->has('Simple'));

        $withoutAnnotations = $adapter->getConstant(TestClass::class, 'TEST_CONST2');
        $this->assertInstanceOf(Collection::class, $withoutAnnotations);
        $this->assertCount(0, $withoutAnnotations);

        $unknown = $adapter->getConstant(TestClass::class, 'TEST_CONST_UNKNOWN');
        $this->assertInstanceOf(Collection::class, $unknown);
        $this->assertCount(0, $unknown);
    }
}
