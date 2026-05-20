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

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Support\Debug;
use Phalcon\Tests\AbstractUnitTestCase;
use ReflectionProperty;

final class SetShowBackTraceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugSetShowBackTrace(): void
    {
        $debug = new Debug();

        $this->assertInstanceOf(Debug::class, $debug->setShowBackTrace(false));
        $this->assertFalse($this->readShowBackTrace($debug));

        $this->assertInstanceOf(Debug::class, $debug->setShowBackTrace(true));
        $this->assertTrue($this->readShowBackTrace($debug));
    }

    private function readShowBackTrace(Debug $debug): bool
    {
        $property = new ReflectionProperty(Debug::class, 'showBackTrace');

        return (bool) $property->getValue($debug);
    }
}
