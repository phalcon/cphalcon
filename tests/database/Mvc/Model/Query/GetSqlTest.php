<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Query\Exceptions\ColumnNotInDomain;
use Phalcon\Mvc\Model\Query\Exceptions\DuplicateCommonTableExpression;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class GetSqlTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use RecordsTrait;

    /**
     * @var InvoicesMigration
     */
    private $invoiceMigration;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();

        $this->invoiceMigration = new InvoicesMigration(self::getConnection());
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/14657
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-06
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryGetSql(): void
    {
        $phql = sprintf('SELECT i.inv_id, i.inv_cst_id FROM [%s] AS i', Invoices::class);

        $query = new Query($phql, $this->container);

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'SELECT `i`.`inv_id` AS `inv_id`, `i`.`inv_cst_id` AS `inv_cst_id` FROM `%s` AS `i`',
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'SELECT "i"."inv_id" AS "inv_id", "i"."inv_cst_id" AS "inv_cst_id" FROM "%s" AS "i"',
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertEquals(
            [
                'sql'       => $sql,
                'bind'      => [],
                'bindTypes' => [],
            ],
            $query->getSql()
        );
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-10
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithCommonTableExpression(): void
    {
        $phql = sprintf(
            'WITH recent (id) AS (SELECT i.inv_id FROM [%s] AS i) SELECT recent.id FROM recent',
            Invoices::class
        );

        $query = new Query($phql, $this->container);

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'WITH `recent` (`id`) AS (SELECT `i`.`inv_id` AS `inv_id` FROM `%s` AS `i`) '
                . 'SELECT `recent`.`id` AS `id` FROM `recent`',
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'WITH "recent" ("id") AS (SELECT "i"."inv_id" AS "inv_id" FROM "%s" AS "i") '
                . 'SELECT "recent"."id" AS "id" FROM "recent"',
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertEquals(
            [
                'sql'       => $sql,
                'bind'      => [],
                'bindTypes' => [],
            ],
            $query->getSql()
        );
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-12
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithCommonTableExpressionUnion(): void
    {
        $phql = sprintf(
            'WITH recent (id) AS ('
            . 'SELECT i.inv_id FROM [%s] AS i '
            . 'UNION SELECT i.inv_cst_id FROM [%s] AS i'
            . ') SELECT recent.id FROM recent',
            Invoices::class,
            Invoices::class
        );

        $query = new Query($phql, $this->container);

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'WITH `recent` (`id`) AS ('
                . 'SELECT `i`.`inv_id` AS `inv_id` FROM `%s` AS `i` '
                . 'UNION SELECT `i`.`inv_cst_id` AS `inv_cst_id` FROM `%s` AS `i`'
                . ') SELECT `recent`.`id` AS `id` FROM `recent`',
                $this->invoiceMigration->getTable(),
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'WITH "recent" ("id") AS ('
                . 'SELECT "i"."inv_id" AS "inv_id" FROM "%s" AS "i" '
                . 'UNION SELECT "i"."inv_cst_id" AS "inv_cst_id" FROM "%s" AS "i"'
                . ') SELECT "recent"."id" AS "id" FROM "recent"',
                $this->invoiceMigration->getTable(),
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertEquals(
            [
                'sql'       => $sql,
                'bind'      => [],
                'bindTypes' => [],
            ],
            $query->getSql()
        );
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-12
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithRecursiveCommonTableExpression(): void
    {
        $phql = sprintf(
            'WITH RECURSIVE recent (id) AS ('
            . 'SELECT i.inv_id FROM [%s] AS i '
            . 'UNION ALL SELECT recent.id FROM recent'
            . ') SELECT recent.id FROM recent',
            Invoices::class
        );

        $query = new Query($phql, $this->container);

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'WITH RECURSIVE `recent` (`id`) AS ('
                . 'SELECT `i`.`inv_id` AS `inv_id` FROM `%s` AS `i` '
                . 'UNION ALL SELECT `recent`.`id` AS `id` FROM `recent`'
                . ') SELECT `recent`.`id` AS `id` FROM `recent`',
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'WITH RECURSIVE "recent" ("id") AS ('
                . 'SELECT "i"."inv_id" AS "inv_id" FROM "%s" AS "i" '
                . 'UNION ALL SELECT "recent"."id" AS "id" FROM "recent"'
                . ') SELECT "recent"."id" AS "id" FROM "recent"',
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertEquals(
            [
                'sql'       => $sql,
                'bind'      => [],
                'bindTypes' => [],
            ],
            $query->getSql()
        );
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-10
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryBuilderGetSqlWithCommonTableExpression(): void
    {
        $subBuilder = new Builder(
            [
                'models'  => ['i' => Invoices::class],
                'columns' => ['i.inv_id'],
            ],
            $this->container
        );

        $builder = new Builder(null, $this->container);
        $builder
            ->addWith('recent', $subBuilder, ['id'])
            ->columns('recent.id')
            ->from('recent');

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'WITH `recent` (`id`) AS (SELECT `i`.`inv_id` AS `inv_id` FROM `%s` AS `i`) '
                . 'SELECT `recent`.`id` AS `id` FROM `recent`',
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'WITH "recent" ("id") AS (SELECT "i"."inv_id" AS "inv_id" FROM "%s" AS "i") '
                . 'SELECT "recent"."id" AS "id" FROM "recent"',
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertEquals(
            [
                'sql'       => $sql,
                'bind'      => [],
                'bindTypes' => [],
            ],
            $builder->getQuery()->getSql()
        );
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithCommonTableExpressionWildcard(): void
    {
        $phql = sprintf(
            'WITH recent (id, title) AS ('
            . 'SELECT i.inv_id, i.inv_title FROM [%s] AS i'
            . ') SELECT * FROM recent',
            Invoices::class
        );

        $query = new Query($phql, $this->container);

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'WITH `recent` (`id`, `title`) AS ('
                . 'SELECT `i`.`inv_id` AS `inv_id`, `i`.`inv_title` AS `inv_title` '
                . 'FROM `%s` AS `i`) '
                . 'SELECT `recent`.`id` AS `id`, `recent`.`title` AS `title` FROM `recent`',
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'WITH "recent" ("id", "title") AS ('
                . 'SELECT "i"."inv_id" AS "inv_id", "i"."inv_title" AS "inv_title" '
                . 'FROM "%s" AS "i") '
                . 'SELECT "recent"."id" AS "id", "recent"."title" AS "title" FROM "recent"',
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertSame($sql, $query->getSql()['sql']);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithCommonTableExpressionDomainWildcard(): void
    {
        $phql = sprintf(
            'WITH recent AS ('
            . 'SELECT i.inv_id, i.inv_title FROM [%s] AS i'
            . ') SELECT recent.* FROM recent',
            Invoices::class
        );

        $query = new Query($phql, $this->container);

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'WITH `recent` AS ('
                . 'SELECT `i`.`inv_id` AS `inv_id`, `i`.`inv_title` AS `inv_title` '
                . 'FROM `%s` AS `i`) '
                . 'SELECT `recent`.`inv_id` AS `inv_id`, '
                . '`recent`.`inv_title` AS `inv_title` FROM `recent`',
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'WITH "recent" AS ('
                . 'SELECT "i"."inv_id" AS "inv_id", "i"."inv_title" AS "inv_title" '
                . 'FROM "%s" AS "i") '
                . 'SELECT "recent"."inv_id" AS "inv_id", '
                . '"recent"."inv_title" AS "inv_title" FROM "recent"',
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertSame($sql, $query->getSql()['sql']);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithUnnamedCommonTableExpressionColumn(): void
    {
        $phql = sprintf(
            'WITH totals AS (SELECT COUNT(*) FROM [%s]) '
            . 'SELECT * FROM totals',
            Invoices::class
        );

        $query = new Query($phql, $this->container);

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'WITH `totals` (`column_0`) AS (SELECT COUNT(*) FROM `%s`) '
                . 'SELECT `totals`.`column_0` AS `column_0` FROM `totals`',
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'WITH "totals" ("column_0") AS (SELECT COUNT(*) FROM "%s") '
                . 'SELECT "totals"."column_0" AS "column_0" FROM "totals"',
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertSame($sql, $query->getSql()['sql']);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithOverlappingCommonTableExpressionColumns(): void
    {
        $phql = sprintf(
            'WITH first_rows (id) AS ('
            . 'SELECT i.inv_id FROM [%s] AS i WHERE i.inv_id = 1'
            . '), second_rows (id) AS ('
            . 'SELECT i.inv_id FROM [%s] AS i WHERE i.inv_id = 2'
            . ') SELECT first_rows.*, second_rows.* '
            . 'FROM first_rows, second_rows',
            Invoices::class,
            Invoices::class
        );

        $query = new Query($phql, $this->container);

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'WITH `first_rows` (`id`) AS ('
                . 'SELECT `i`.`inv_id` AS `inv_id` FROM `%s` AS `i` '
                . 'WHERE `i`.`inv_id` = 1), '
                . '`second_rows` (`id`) AS ('
                . 'SELECT `i`.`inv_id` AS `inv_id` FROM `%s` AS `i` '
                . 'WHERE `i`.`inv_id` = 2) '
                . 'SELECT `first_rows`.`id` AS `id`, '
                . '`second_rows`.`id` AS `second_rows_id` '
                . 'FROM `first_rows`, `second_rows`',
                $this->invoiceMigration->getTable(),
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'WITH "first_rows" ("id") AS ('
                . 'SELECT "i"."inv_id" AS "inv_id" FROM "%s" AS "i" '
                . 'WHERE "i"."inv_id" = 1), '
                . '"second_rows" ("id") AS ('
                . 'SELECT "i"."inv_id" AS "inv_id" FROM "%s" AS "i" '
                . 'WHERE "i"."inv_id" = 2) '
                . 'SELECT "first_rows"."id" AS "id", '
                . '"second_rows"."id" AS "second_rows_id" '
                . 'FROM "first_rows", "second_rows"',
                $this->invoiceMigration->getTable(),
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertSame($sql, $query->getSql()['sql']);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithCommonTableExpressionColumnBeforeOverlappingModelColumn(): void
    {
        $phql = sprintf(
            'WITH recent (inv_id) AS ('
            . 'SELECT i.inv_id FROM [%s] AS i WHERE i.inv_id = 1'
            . ') SELECT recent.*, i.inv_id '
            . 'FROM recent, [%s] AS i WHERE i.inv_id = 2',
            Invoices::class,
            Invoices::class
        );

        $query = new Query($phql, $this->container);

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'WITH `recent` (`inv_id`) AS ('
                . 'SELECT `i`.`inv_id` AS `inv_id` FROM `%s` AS `i` '
                . 'WHERE `i`.`inv_id` = 1) '
                . 'SELECT `recent`.`inv_id` AS `recent_inv_id`, '
                . '`i`.`inv_id` AS `inv_id` '
                . 'FROM `recent`, `%s` AS `i` WHERE `i`.`inv_id` = 2',
                $this->invoiceMigration->getTable(),
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'WITH "recent" ("inv_id") AS ('
                . 'SELECT "i"."inv_id" AS "inv_id" FROM "%s" AS "i" '
                . 'WHERE "i"."inv_id" = 1) '
                . 'SELECT "recent"."inv_id" AS "recent_inv_id", '
                . '"i"."inv_id" AS "inv_id" '
                . 'FROM "recent", "%s" AS "i" WHERE "i"."inv_id" = 2',
                $this->invoiceMigration->getTable(),
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertSame($sql, $query->getSql()['sql']);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithCommonTableExpressionUnionOrderLimit(): void
    {
        $phql = sprintf(
            'WITH recent (id) AS ('
            . 'SELECT i.inv_id AS id FROM [%s] AS i ORDER BY id LIMIT 5 '
            . 'UNION SELECT i.inv_cst_id AS id FROM [%s] AS i'
            . ') SELECT recent.id FROM recent',
            Invoices::class,
            Invoices::class
        );

        $query = new Query($phql, $this->container);

        if ('mysql' === $this->invoiceMigration->getDriverName()) {
            $sql = sprintf(
                'WITH `recent` (`id`) AS ('
                . 'SELECT `i`.`inv_id` AS `id` FROM `%s` AS `i` '
                . 'UNION SELECT `i`.`inv_cst_id` AS `id` FROM `%s` AS `i` '
                . 'ORDER BY `id` LIMIT 5'
                . ') SELECT `recent`.`id` AS `id` FROM `recent`',
                $this->invoiceMigration->getTable(),
                $this->invoiceMigration->getTable()
            );
        } else {
            $sql = sprintf(
                'WITH "recent" ("id") AS ('
                . 'SELECT "i"."inv_id" AS "id" FROM "%s" AS "i" '
                . 'UNION SELECT "i"."inv_cst_id" AS "id" FROM "%s" AS "i" '
                . 'ORDER BY "id" LIMIT 5'
                . ') SELECT "recent"."id" AS "id" FROM "recent"',
                $this->invoiceMigration->getTable(),
                $this->invoiceMigration->getTable()
            );
        }

        $this->assertSame($sql, $query->getSql()['sql']);
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithDuplicateCommonTableExpression(): void
    {
        $this->expectException(DuplicateCommonTableExpression::class);
        $this->expectExceptionMessage(
            "Common table expression 'recent' is defined more than once"
        );

        $phql = sprintf(
            'WITH recent AS (SELECT inv_id FROM [%s]), '
            . 'recent AS (SELECT inv_cst_id FROM [%s]) '
            . 'SELECT recent.inv_id FROM recent',
            Invoices::class,
            Invoices::class
        );

        (new Query($phql, $this->container))->getSql();
    }

    /**
     * @author QUAD69 <https://github.com/QUAD69>
     * @since  2026-06-25
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryGetSqlWithUnknownCommonTableExpressionColumn(): void
    {
        $this->expectException(ColumnNotInDomain::class);
        $this->expectExceptionMessage(
            "Column 'missing' does not belong to the model or alias 'recent'"
        );

        $phql = sprintf(
            'WITH recent (id) AS (SELECT inv_id FROM [%s]) '
            . 'SELECT recent.missing FROM recent',
            Invoices::class
        );

        (new Query($phql, $this->container))->getSql();
    }
}
