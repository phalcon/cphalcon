<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Migrations;

use Phalcon\Db\Adapter\AdapterInterface;

class StringPrimaryMigration
{
    public function __invoke(AdapterInterface $db)
    {
        $sql = <<<SQL
drop table if exists `table_with_uuid_primary`;
SQL;
        $db->execute($sql);

        $sql = <<<SQL
create table table_with_uuid_primary
(
    `uuid` CHAR(36) NOT NULL,
    `int_field` INT NULL,
    PRIMARY KEY (`uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
SQL;
        $db->execute($sql);

        $sql = <<<SQL
insert into `table_with_uuid_primary` (`uuid`, `int_field`) VALUES
    ('5741bfd7-6870-40b7-adf6-cbacb515b9a9', 1),
    ('1c53079c-249e-0c63-af8d-52413bfa2a2b', 2);
SQL;
        $db->execute($sql);
    }
}
