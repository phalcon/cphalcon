<?php

namespace Phalcon\Tests\Integration\Db\Dialect\Helper;

use Phalcon\Tests\Fixtures\Traits\DialectTrait;

class MysqlHelper
{
    use DialectTrait;

    protected function addForeignKeySql(
        string $foreignKeyName = '',
        string $onUpdate = '',
        string $onDelete = ''
    ): string {
        $sql = 'ALTER TABLE `foreign_key_child` ADD';

        if ($foreignKeyName) {
            $sql .= ' CONSTRAINT `' . $foreignKeyName . '`';
        }

        $sql .= ' FOREIGN KEY (`child_int`) REFERENCES `foreign_key_parent`(`refer_int`)';

        if ($onDelete) {
            $sql .= ' ON DELETE ' . $onDelete;
        }

        if ($onUpdate) {
            $sql .= ' ON UPDATE ' . $onUpdate;
        }

        return $sql;
    }

    protected function getForeignKeySql(string $foreignKeyName): string
    {
        $sql = "SELECT
                COUNT(`CONSTRAINT_NAME`)
            FROM information_schema.REFERENTIAL_CONSTRAINTS
            WHERE TABLE_NAME = 'foreign_key_child' AND
                `UPDATE_RULE` = 'CASCADE' AND
                `DELETE_RULE` = 'RESTRICT' AND
                `CONSTRAINT_NAME` = '{$foreignKeyName}'";

        return $sql;
    }
}
