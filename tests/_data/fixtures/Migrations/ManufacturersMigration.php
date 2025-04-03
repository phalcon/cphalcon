<?php

declare(strict_types=1);

namespace Phalcon\Tests\Fixtures\Migrations;

/**
 * Class ManufacturersMigration
 */
class ManufacturersMigration extends AbstractMigration
{
    protected $table = "co_manufacturers";

    /**
     * @param int         $id
     * @param string      $name
     * @param string|null $country
     * @param int         $foundedYear
     *
     * @return int
     */
    public function insert(
        $id,
        string $name,
        ?string $country,
        int $foundedYear
    ): int {
        $id          = $id ?: 'null';
        $country     = $country ? "'{$country}'" : 'null';
        $sql    = <<<SQL
insert into co_manufacturers (
    id, name, country, founded_year
) values (
    {$id}, '{$name}', {$country}, {$foundedYear}
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_manufacturers`;",
            "
CREATE TABLE `co_manufacturers` (
    `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
    `name` VARCHAR(100) NOT NULL,
    `country` VARCHAR(100) NULL,
    `founded_year` INT NOT NULL,
    PRIMARY KEY (`id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            "
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists co_manufacturers;",
            "
create table co_manufacturers (
    id integer constraint co_manufacturers_pk primary key autoincrement,
    name text not null,
    country text null,
    founded_year integer not null
);
            "
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists co_manufacturers;",
            "
create table co_manufacturers
(
    id serial not null
    constraint manufacturers_pk
      primary key,
    name varchar(100) not null,
    country varchar(100) null,
    founded_year int not null
);
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
