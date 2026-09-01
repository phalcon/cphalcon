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

final class ParsePHQLTest extends AbstractUnitTestCase
{
    /**
     * Tests that two PHQL strings which previously collided under
     * zend_inline_hash_func produce distinct AST representations.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     * @issue  https://github.com/phalcon/cphalcon/issues/14791
     */
    public function testMvcModelQueryLangParsePHQLCacheCollision(): void
    {
        $phql1 = "SELECT [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users].* "
               . "FROM [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users] "
               . "WHERE _id = 'GcbN9FIoI8IC3LqBIuCu50AC02TpI8ruKOjyzd1fqOCuna' LIMIT :APL0:";

        $phql2 = "SELECT [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users].* "
               . "FROM [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users] "
               . "WHERE _id = 'GcbN9FIoI8IC3LpcIuCu50AC02TpI8ruKOjyzd1fqOCuna' LIMIT :APL0:";

        $ast1 = Lang::parsePHQL($phql1);
        $ast2 = Lang::parsePHQL($phql2);

        $this->assertNotSame($ast1, $ast2);

        // Each query must keep its own `_id`, not the other's cached value.
        $this->assertSame(
            'GcbN9FIoI8IC3LqBIuCu50AC02TpI8ruKOjyzd1fqOCuna',
            $ast1['where']['right']['value']
        );
        $this->assertSame(
            'GcbN9FIoI8IC3LpcIuCu50AC02TpI8ruKOjyzd1fqOCuna',
            $ast2['where']['right']['value']
        );
    }

    /**
     * A second, independent minimal collision pair, easier to verify than the
     * 47-character id from the issue. 'B0' and 'AQ' collide under DJBX33A:
     * 33 * 66 + 48 == 33 * 65 + 81.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     * @issue  https://github.com/phalcon/cphalcon/issues/14791
     */
    public function testMvcModelQueryLangParsePHQLCacheCollisionMinimal(): void
    {
        $phql1 = "SELECT * FROM Robots WHERE name = 'B0'";
        $phql2 = "SELECT * FROM Robots WHERE name = 'AQ'";

        $ast1 = Lang::parsePHQL($phql1);
        $ast2 = Lang::parsePHQL($phql2);

        $this->assertSame('B0', $ast1['where']['right']['value']);
        $this->assertSame('AQ', $ast2['where']['right']['value']);
    }

    /**
     * The colliding query parsed second must keep its own value regardless of
     * parse order - the bug poisons whichever query populates the cache first.
     * 'qB' and 'pc' collide under DJBX33A: 33 * 113 + 66 == 33 * 112 + 99.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     * @issue  https://github.com/phalcon/cphalcon/issues/14791
     */
    public function testMvcModelQueryLangParsePHQLCacheCollisionParseOrder(): void
    {
        $phql1 = "SELECT * FROM Robots WHERE name = 'qB'";
        $phql2 = "SELECT * FROM Robots WHERE name = 'pc'";

        // Parse the second one first to prove neither order poisons the cache.
        $ast2 = Lang::parsePHQL($phql2);
        $ast1 = Lang::parsePHQL($phql1);

        $this->assertSame('pc', $ast2['where']['right']['value']);
        $this->assertSame('qB', $ast1['where']['right']['value']);
    }

    /**
     * The same PHQL parsed twice must return an equal AST - a cache hit for a
     * matching key must yield the correct representation.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     * @issue  https://github.com/phalcon/cphalcon/issues/14791
     */
    public function testMvcModelQueryLangParsePHQLCacheReturnsSameAst(): void
    {
        $phql = "SELECT * FROM Robots WHERE name = 'cacheHit'";

        $ast1 = Lang::parsePHQL($phql);
        $ast2 = Lang::parsePHQL($phql);

        $this->assertSame($ast1, $ast2);
    }

    /**
     * The IN list is built in linear time; 40,000 items used to take
     * seconds.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcModelQueryLangParsePHQLLargeInList(): void
    {
        $count = 40000;
        $phql  = 'SELECT * FROM Robots WHERE id IN ('
            . implode(',', array_fill(0, $count, '1')) . ')';

        $start  = microtime(true);
        $actual = Lang::parsePHQL($phql);
        $spent  = microtime(true) - $start;

        $this->assertIsArray($actual);
        $this->assertLessThan(3.0, $spent);
    }

    /**
     * With literals disabled the scanner still allocates the literal token;
     * the parser must release it when it rejects the statement.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcModelQueryLangParsePHQLRejectedLiteralDoesNotLeak(): void
    {
        $previous = ini_get('phalcon.orm.enable_literals');
        ini_set('phalcon.orm.enable_literals', '0');

        $phql = 'SELECT * FROM Robots WHERE name = "' . str_repeat('x', 1000) . '"';

        try {
            $before = memory_get_usage();

            for ($i = 0; $i < 5000; $i++) {
                try {
                    Lang::parsePHQL($phql);
                } catch (Exception $ex) {
                    // Expected: literals are disabled.
                }
            }

            $delta = memory_get_usage() - $before;
        } finally {
            ini_set('phalcon.orm.enable_literals', $previous);
        }

        // 5,000 x 1 KB literals leaked ~5.5 MB before the fix.
        $this->assertLessThan(1048576, $delta);
    }

    /**
     * A backslash as the last byte of a quoted string must be a scanning
     * error, not an escape that swallows the terminator.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcModelQueryLangParsePHQLTrailingBackslashInString(): void
    {
        foreach (['"abc\\', "'abc\\"] as $literal) {
            $caught = null;

            try {
                Lang::parsePHQL('SELECT * FROM Robots WHERE name = ' . $literal);
            } catch (Exception $ex) {
                $caught = $ex;
            }

            $this->assertNotNull($caught, $literal);
            $this->assertStringContainsString('Scanning error', $caught->getMessage());
        }
    }
}
