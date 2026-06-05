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

final class SetShowFilesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugSetShowFiles(): void
    {
        $debug = new Debug();

        $this->assertInstanceOf(Debug::class, $debug->setShowFiles(false));
        $this->assertFalse($this->readShowFiles($debug));

        $this->assertInstanceOf(Debug::class, $debug->setShowFiles(true));
        $this->assertTrue($this->readShowFiles($debug));
    }

    private function readShowFiles(Debug $debug): bool
    {
        $property = new ReflectionProperty(Debug::class, 'showFiles');

        return (bool) $property->getValue($debug);
    }
}
