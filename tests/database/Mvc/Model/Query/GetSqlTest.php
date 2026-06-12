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
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
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
}
