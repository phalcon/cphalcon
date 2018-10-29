<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Adapter\Pdo\Postgresql;

use Helper\Db\Adapter\Pdo\PostgresqlTrait;
use Phalcon\Test\Unit\Db\Adapter\Pdo\TablesBase;

class TablesCest extends TablesBase
{
    use PostgresqlTrait;

    /**
     * Returns the list of the tables in the database
     *
     * @return array
     */
    protected function getListTables(): array
    {
        return [
            'customers',
            'dialect_table',
            'dialect_table_intermediate',
            'dialect_table_remote',
            'foreign_key_child',
            'foreign_key_parent',
            'images',
            'parts',
            'personas',
            'personnes',
            'ph_select',
            'prueba',
            'robots',
            'robots_parts',
            'subscriptores',
            'table_with_string_field',
            'tipo_documento',

        ];
    }
}
