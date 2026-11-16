<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Support\Debug;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use ReflectionProperty;

final class DebugVarTest extends AbstractUnitTestCase
{
    /**
     * @issue https://github.com/phalcon/cphalcon/issues/17746
     */
    public function testDebugVarStoresTheBacktraceWithNoArgumentsOrObjects(): void
    {
        $debug = new Debug();
        $debug->debugVar('test variable');

        $property = new ReflectionProperty(Debug::class, 'data');
        /** @var list<array{0: mixed, 1: list<array<string, mixed>>, 2: int}> $data */
        $data  = $property->getValue($debug);
        $frame = $data[0][1][0];

        $this->assertSame('debugVar', $frame['function']);
        $this->assertArrayNotHasKey('args', $frame);
        $this->assertArrayNotHasKey('object', $frame);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-04
     */
    public function testSupportDebugDebugVar(): void
    {
        $debug  = new Debug();
        $result = $debug->debugVar('test variable');

        $this->assertInstanceOf(Debug::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-11
     */
    public function testSupportDebugDebugVarAndClearVars(): void
    {
        $debug = new Debug();
        $debug->debugVar('first variable');
        $debug->debugVar('second variable');

        $result = $debug->clearVars();
        $this->assertInstanceOf(Debug::class, $result);
    }
}
