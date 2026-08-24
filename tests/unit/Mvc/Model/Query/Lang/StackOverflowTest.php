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

namespace Phalcon\Tests\Unit\Mvc\Model\Query\Lang;

use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Query\Lang;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class StackOverflowTest extends AbstractUnitTestCase
{
    /**
     * A deeply nested PHQL statement must not silently drop the part of the
     * query that overflowed the parser stack. The parser must fail closed and
     * report the overflow instead of accepting a truncated statement.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testMvcModelQueryLangParsePHQLStackOverflowFailsClosed(): void
    {
        $depth = 300;
        $phql  = "SELECT * FROM Robots WHERE id = "
            . str_repeat("(", $depth) . "1" . str_repeat(")", $depth);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("nested too deeply");

        Lang::parsePHQL($phql);
    }
}
