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

namespace Phalcon\Tests\Support\Migrations;

/**
 * Class InvoicesCustomersFkMigration
 *
 * Creates the `co_customers_fk` (parent) and `co_invoices_fk` (child)
 * tables with an explicit foreign key from
 * `co_invoices_fk.inv_cst_id` to `co_customers_fk.cst_id`.
 *
 * Used by DescribeReferencesTest only. Caller is expected to invoke
 * `create()` in setUp and `drop()` in tearDown to keep the global
 * schema clean.
 */
class InvoicesCustomersFkMigration extends AbstractMigration
{
    protected $table = 'co_invoices_fk';

    public function insert(): int
    {
        return 0;
    }

    public function drop(): void
    {
        $this->connection->exec('DROP TABLE IF EXISTS co_invoices_fk;');
        $this->connection->exec('DROP TABLE IF EXISTS co_customers_fk;');
    }

    protected function getSqlMysql(): array
    {
        return [
            "DROP TABLE IF EXISTS `co_invoices_fk`;",
            "DROP TABLE IF EXISTS `co_customers_fk`;",
            "
CREATE TABLE `co_customers_fk` (
    `cst_id`   int(10) NOT NULL AUTO_INCREMENT,
    `cst_name` varchar(100) NULL,
    PRIMARY KEY (`cst_id`)
) ENGINE=InnoDB;
            ",
            "
CREATE TABLE `co_invoices_fk` (
    `inv_id`     int(10) NOT NULL AUTO_INCREMENT,
    `inv_cst_id` int(10) NOT NULL,
    `inv_title`  varchar(100) NULL,
    PRIMARY KEY (`inv_id`),
    KEY `co_invoices_fk_inv_cst_id_index` (`inv_cst_id`),
    CONSTRAINT `co_invoices_fk_cst_fk`
        FOREIGN KEY (`inv_cst_id`)
        REFERENCES `co_customers_fk` (`cst_id`)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "DROP TABLE IF EXISTS co_invoices_fk;",
            "DROP TABLE IF EXISTS co_customers_fk;",
            "
CREATE TABLE co_customers_fk (
    cst_id   serial PRIMARY KEY,
    cst_name varchar(100)
);
            ",
            "
CREATE TABLE co_invoices_fk (
    inv_id     serial PRIMARY KEY,
    inv_cst_id integer NOT NULL,
    inv_title  varchar(100),
    CONSTRAINT co_invoices_fk_cst_fk
        FOREIGN KEY (inv_cst_id)
        REFERENCES co_customers_fk (cst_id)
        ON UPDATE CASCADE ON DELETE RESTRICT
);
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "DROP TABLE IF EXISTS co_invoices_fk;",
            "DROP TABLE IF EXISTS co_customers_fk;",
            "
CREATE TABLE co_customers_fk (
    cst_id   integer CONSTRAINT co_customers_fk_pk PRIMARY KEY AUTOINCREMENT,
    cst_name text
);
            ",
            "
CREATE TABLE co_invoices_fk (
    inv_id     integer CONSTRAINT co_invoices_fk_pk PRIMARY KEY AUTOINCREMENT,
    inv_cst_id integer NOT NULL,
    inv_title  text,
    CONSTRAINT co_invoices_fk_cst_fk
        FOREIGN KEY (inv_cst_id)
        REFERENCES co_customers_fk (cst_id)
        ON UPDATE CASCADE ON DELETE RESTRICT
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
