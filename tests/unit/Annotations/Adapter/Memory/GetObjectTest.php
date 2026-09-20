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
use Phalcon\Annotations\Reflection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use TestClass;

final class GetObjectTest extends AbstractUnitTestCase
{
    /**
     * An object gives the same reflection as its class name, and the second
     * call comes from the in-memory cache.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    public function testAnnotationsAdapterMemoryGetObject(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $adapter = new Memory();

        $classAnnotations = $adapter->get(new TestClass());

        $this->assertInstanceOf(Reflection::class, $classAnnotations);
        $this->assertInstanceOf(Collection::class, $classAnnotations->getClassAnnotations());

        $this->assertSame($classAnnotations, $adapter->get(TestClass::class));
    }
}
