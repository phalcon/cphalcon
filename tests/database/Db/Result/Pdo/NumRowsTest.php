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

namespace Phalcon\Tests\Database\Db\Result\Pdo;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class NumRowsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getPdoConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 101);
        $migration->insert(2, 1, 1, 'title 2', 102);
        $migration->insert(3, 2, 1, 'title 3', 103);
        $migration->insert(4, 2, 1, 'title 4', 104);
        $migration->insert(5, 3, 1, 'title 5', 105);
    }

    /**
     * Statement shapes numRows() has to survive.
     *
     * On SQLite none of these can be answered by PDO, so each one is counted by
     * wrapping the statement in a sub-select. Wrapping it verbatim - rather than
     * pulling it apart with a regex and rebuilding it - is what keeps the last
     * three working:
     *
     *  - 'multiline'  the old `/^SELECT\s+(.*)/i` had no `s` modifier, so the
     *                 rebuilt statement stopped at the first newline and blew up
     *                 with "no tables specified"
     *  - 'cte'        does not start with SELECT, so the old regex never matched
     *                 and numRows() returned null through an `int` signature
     *  - 'countGroup' the old code short-circuited anything starting with
     *                 "SELECT COUNT(*) " to a hard-coded 1, which is only right
     *                 without a GROUP BY
     *
     * @return array<string, array{0: string, 1: int}>
     */
    public static function getExamples(): array
    {
        return [
            'plain'      => ['SELECT * FROM co_invoices', 5],
            'multiline'  => ["SELECT *\nFROM co_invoices", 5],
            'cte'        => [
                'WITH inv AS (SELECT * FROM co_invoices) SELECT * FROM inv',
                5,
            ],
            'count'      => ['SELECT COUNT(*) FROM co_invoices', 1],
            'countGroup' => [
                'SELECT COUNT(*) FROM co_invoices GROUP BY inv_cst_id',
                3,
            ],
            'limit'      => ['SELECT * FROM co_invoices LIMIT 2', 2],
            'orderBy'    => ['SELECT * FROM co_invoices ORDER BY inv_id DESC', 5],
            'where'      => ['SELECT * FROM co_invoices WHERE inv_cst_id = 2', 2],
        ];
    }

    /**
     * Tests Phalcon\Db\Result\Pdo :: numRows()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbResultPdoNumRows(): void
    {
        $db     = $this->container->get('db');
        $result = $db->query('SELECT * FROM co_invoices');

        $this->assertEquals(5, $result->numRows());
    }

    /**
     * The count survives the cursor having been drained - it is worked out from
     * the statement, not from what is left to read.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    public function testDbResultPdoNumRowsAfterExhaustion(): void
    {
        $db     = $this->container->get('db');
        $result = $db->query('SELECT * FROM co_invoices');

        while ($result->fetch()) {
            // drain
        }

        $this->assertSame(5, $result->numRows());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[DataProvider('getExamples')]
    public function testDbResultPdoNumRowsStatementShapes(
        string $sql,
        int $expected
    ): void {
        $db     = $this->container->get('db');
        $result = $db->query($sql);

        $this->assertSame($expected, $result->numRows());
    }

    /**
     * Bound values have to reach the counting statement too, or the count comes
     * back for the unfiltered set.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    public function testDbResultPdoNumRowsWithBindParams(): void
    {
        $db     = $this->container->get('db');
        $result = $db->query(
            'SELECT * FROM co_invoices WHERE inv_cst_id = :cst_id',
            ['cst_id' => 2]
        );

        $this->assertSame(2, $result->numRows());
    }
}
