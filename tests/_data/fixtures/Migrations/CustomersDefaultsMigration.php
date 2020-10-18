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

namespace Phalcon\Test\Fixtures\Migrations;

use PHPUnit\Framework\Assert;

/**
 * Class CustomersMigration
 */
class CustomersDefaultsMigration extends AbstractMigration
{
    protected $table = 'co_customers_defaults';

    /**
     * @param int|null    $id
     * @param int         $status
     * @param string|null $first
     * @param string|null $last
     *
     * @return int
     */
    public function insert(
        $id,
        int $status = 0,
        string $first = null,
        string $last = null
    ): int {
        $id  = $id ?: 'null';
        $sql = <<<SQL
insert into co_customers_defaults (
    cst_id, cst_status_flag, cst_name_first, cst_name_last
) values (
    {$id}, {$status}, '{$first}', '{$last}'
)
SQL;

        if (!$result = $this->connection->exec($sql)) {
            $table  = $this->getTable();
            $driver = $this->getDriverName();
            Assert::fail(
                sprintf("Failed to insert row #%d into table '%s' using '%s' driver", $id, $table, $driver)
            );
        }

        return $result;
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_customers_defaults`;
            ",
            "
create table co_customers_defaults
(
    `cst_id`          int(10) auto_increment primary key,
    `cst_status_flag` tinyint(1)   not null DEFAULT 1,
    `cst_name_last`   varchar(100) not null DEFAULT 'cst_default_lastName',
    `cst_name_first`  varchar(50)  not null DEFAULT 'cst_default_firstName'
);
            ",
            "
create index co_customers_defaults_cst_status_flag_index
    on `co_customers_defaults` (`cst_status_flag`);
            ",
            "
create index co_customers_defaults_cst_name_last_index
    on `co_customers_defaults` (`cst_name_last`);
            ",
            "
create index co_customers_defaults_cst_name_first_index
    on `co_customers_defaults` (`cst_name_first`);
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists co_customers_defaults;
            ",
            "
create table co_customers_defaults
(
    cst_id          integer constraint co_customers_defaults_pk primary key autoincrement,
    cst_status_flag integer      not null DEFAULT 1,
    cst_name_last   text         not null DEFAULT 'cst_default_lastName',
    cst_name_first  text         not null DEFAULT 'cst_default_firstName'
);
            ",
            "
create index co_customers_defaults_cst_status_flag_index
    on co_customers_defaults (cst_status_flag);
            ",
            "
create index co_customers_defaults_cst_name_last_index
    on co_customers_defaults (cst_name_last);
            ",
            "
create index co_customers_defaults_cst_name_first_index
    on co_customers_defaults (cst_name_first);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists co_customers_defaults;
            ",
            "
create table co_customers_defaults
(
    cst_id          serial not null constraint co_customers_defaults_pk primary key,
    cst_status_flag smallint   not null DEFAULT 1,
    cst_name_last   varchar(100) not null DEFAULT 'cst_default_lastName',
    cst_name_first  varchar(50)  not null DEFAULT 'cst_default_firstName'
);
            ",
            "
create index co_customers_defaults_cst_status_flag_index
    on co_customers_defaults (cst_status_flag);
            ",
            "
create index co_customers_defaults_cst_name_last_index
    on co_customers_defaults (cst_name_last);
            ",
            "
create index co_customers_defaults_cst_name_first_index
    on co_customers_defaults (cst_name_first);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
