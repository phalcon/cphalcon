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

use Phalcon\Mvc\Model\Query\Lang;
use Phalcon\Tests\AbstractUnitTestCase;

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
}
