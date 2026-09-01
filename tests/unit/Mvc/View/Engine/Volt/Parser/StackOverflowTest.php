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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Parser;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View\Exception;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class StackOverflowTest extends AbstractUnitTestCase
{
    private Compiler $compiler;

    public function setUp(): void
    {
        $this->compiler = new Compiler();
    }

    /**
     * A deeply nested Volt expression must not silently drop the part of the
     * template that overflowed the parser stack. The parser must fail closed
     * and report the overflow instead of accepting a truncated expression.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testMvcViewEngineVoltParserStackOverflowFailsClosed(): void
    {
        $depth  = 300;
        $source = "{{ " . str_repeat("(", $depth) . "1" . str_repeat(")", $depth) . " }}";

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("nested too deeply");

        $this->compiler->parse($source);
    }
}
