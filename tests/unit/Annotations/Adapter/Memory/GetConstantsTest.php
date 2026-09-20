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

final class GetConstantsTest extends AbstractUnitTestCase
{
    /**
     * Only the constants that have annotations are in the map.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    public function testAnnotationsAdapterMemoryGetConstants(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $adapter = new Memory();

        $constants = $adapter->getConstants(TestClass::class);

        $this->assertArrayHasKey('TEST_CONST1', $constants);
        $this->assertArrayNotHasKey('TEST_CONST2', $constants);
        $this->assertInstanceOf(Collection::class, $constants['TEST_CONST1']);
    }
}
