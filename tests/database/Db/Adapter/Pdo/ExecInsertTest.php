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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use Phalcon\Db\Adapter\Pdo\AbstractPdo;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Column;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\DialectMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class ExecInsertTest extends AbstractDatabaseTestCase
{
    use DiTrait;

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
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: describeColumns()
     *
     * @return void
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     */
    #[Group('mysql')]
    public function testDbAdapterPdoInsert(): void
    {
        $connection = self::getConnection();
        $migration  = new DialectMigration($connection);
        $sql        = <<<SQL
insert into co_dialect (
    field_primary,
    field_blob,
    field_binary,
    field_bit,
    field_bigint,
    field_boolean,
    field_char,
    field_decimal,
    field_enum,
    field_integer,
    field_json,
    field_float,
    field_date,
    field_datetime,
    field_time,
    field_timestamp,
    field_mediumint,
    field_smallint,
    field_tinyint,
    field_longtext,
    field_mediumtext,
    field_tinytext,
    field_text,
    field_varbinary,
    field_varchar
) values (
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?
)
SQL;
        $values     = [
            10,                          // field_primary,
            'abcdefgh',                  // field_blob,
            'bin',                       // field_binary,
            1,                           // field_bit,
            33,                          // field_bigint,
            true,                        // field_boolean,
            'a',                         // field_char,
            1.2,                         // field_decimal,
            'xs',                        // field_enum,
            4,                           // field_integer,
            '{}',                        // field_json,
            2.3,                         // field_float,
            '2020-09-09',                // field_date,
            '2020-09-09 01:02:03',       // field_datetime,
            '01:02:03',                  // field_time,
            '2020-09-09 01:02:03',       // field_timestamp,
            4,                           // field_mediumint,
            3,                           // field_smallint,
            2,                           // field_tinyint,
            'abcdefg',                   // field_longtext,
            'abcde',                     // field_mediumtext,
            'ab',                        // field_tinytext,
            'abc',                       // field_text,
            'vbin',                      // field_varbinary,
            'abcdef',                    // field_varchar
        ];
        $types      = [
            Column::BIND_PARAM_INT,      // field_primary,
            Column::BIND_PARAM_BLOB,     // field_blob,
            Column::BIND_PARAM_BLOB,     // field_binary,
            Column::BIND_PARAM_INT,      // field_bit,
            Column::BIND_PARAM_INT,      // field_bigint,
            Column::BIND_PARAM_BOOL,     // field_boolean,
            Column::BIND_PARAM_STR,      // field_char,
            Column::BIND_PARAM_DECIMAL,  // field_decimal,
            Column::BIND_PARAM_STR,      // field_enum,
            Column::BIND_PARAM_INT,      // field_integer,
            Column::BIND_PARAM_STR,      // field_json,
            Column::BIND_PARAM_DECIMAL,  // field_float,
            Column::BIND_PARAM_STR,      // field_date,
            Column::BIND_PARAM_STR,      // field_datetime,
            Column::BIND_PARAM_STR,      // field_time,
            Column::BIND_PARAM_STR,      // field_timestamp,
            Column::BIND_PARAM_INT,      // field_mediumint,
            Column::BIND_PARAM_INT,      // field_smallint,
            Column::BIND_PARAM_INT,      // field_tinyint,
            Column::BIND_PARAM_STR,      // field_longtext,
            Column::BIND_PARAM_STR,      // field_mediumtext,
            Column::BIND_PARAM_STR,      // field_tinytext,
            Column::BIND_PARAM_STR,      // field_text,
            Column::BIND_PARAM_BLOB,     // field_varbinary,
            Column::BIND_PARAM_STR,      // field_varchar
        ];

        $connection = new Mysql($this->getDatabaseOptions());
        $this->assertInstanceOf(AbstractPdo::class, $connection);

        $this->assertCount(25, $values);
        $this->assertCount(25, $types);

        $result = $connection->execute($sql, $values);

        $this->assertNotFalse($result);
    }
}
