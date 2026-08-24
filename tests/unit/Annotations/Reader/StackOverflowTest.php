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

namespace Phalcon\Tests\Unit\Annotations\Reader;

use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Reader;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class StackOverflowTest extends AbstractUnitTestCase
{
    /**
     * A deeply nested annotation must not silently drop the part of the
     * docblock that overflowed the parser stack. The parser must fail closed
     * and report the overflow instead of accepting a truncated annotation.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testAnnotationsReaderParseDocBlockStackOverflowFailsClosed(): void
    {
        $depth    = 300;
        $docBlock = "/**\n * @Foo("
            . str_repeat("{", $depth) . str_repeat("}", $depth)
            . ")\n */";

        $reader = new Reader();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("nested too deeply");

        $reader->parseDocBlock($docBlock);
    }
}
