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
 * Class PersonasMigration
 */
class PersonasMigration extends AbstractMigration
{
    protected $table = 'personas';

    /**
     * @param string $cedula
     * @param int    $tipoDocumentoId
     * @param string $nombres
     * @param string $telefono
     * @param float  $cupo
     * @param string $estado
     */
    public function insert(
        string $cedula,
        int $tipoDocumentoId = 1,
        string $nombres = 'Test Name',
        string $telefono = '1234567890',
        float $cupo = 0.0,
        string $estado = 'A'
    ): int {
        $sql    = <<<SQL
insert into personas (cedula, tipo_documento_id, nombres, telefono, cupo, estado)
values (:cedula, :tipoDocumentoId, :nombres, :telefono, :cupo, :estado)
SQL;
        $params = [
            ':cedula'          => $cedula,
            ':tipoDocumentoId' => $tipoDocumentoId,
            ':nombres'         => $nombres,
            ':telefono'        => $telefono,
            ':cupo'            => $cupo,
            ':estado'          => $estado,
        ];

        return $this->execute($sql, $params);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `personas`;
            ",
            "
create table `personas`
(
    `cedula`            char(15)        not null,
    `tipo_documento_id` int(3) unsigned not null,
    `nombres`           varchar(100)    not null default '',
    `telefono`          varchar(20)              default null,
    `cupo`              decimal(16, 2)  not null,
    `estado`            enum ('A','I','X') not null,
    primary key (`cedula`)
);
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists personas;
            ",
            "
create table personas
(
    cedula            text    not null,
    tipo_documento_id integer not null,
    nombres           text    not null default '',
    telefono          text             default null,
    cupo              real    not null default 0,
    estado            text    not null default 'A',
    primary key (cedula)
);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists personas;
            ",
            "
create table personas
(
    cedula            char(15)       not null,
    tipo_documento_id smallint       not null,
    nombres           varchar(100)   not null default '',
    telefono          varchar(20)             default null,
    cupo              numeric(16, 2) not null,
    estado            char(1)        not null default 'A',
    primary key (cedula)
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}

