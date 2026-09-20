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

final class GetMethodFallbackTest extends AbstractUnitTestCase
{
    /**
     * A method name that does not match the case of the declaration is found
     * by the second pass, which compares without case. A name that matches no
     * method gives an empty collection.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    public function testAnnotationsAdapterMemoryGetMethodFallback(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $adapter = new Memory();

        $methodAnnotations = $adapter->getMethod(TestClass::class, 'TESTMETHOD1');
        $this->assertInstanceOf(Collection::class, $methodAnnotations);
        $this->assertTrue($methodAnnotations->has('Simple'));

        $unknown = $adapter->getMethod(TestClass::class, 'unknownMethod');
        $this->assertInstanceOf(Collection::class, $unknown);
        $this->assertCount(0, $unknown);
    }
}
