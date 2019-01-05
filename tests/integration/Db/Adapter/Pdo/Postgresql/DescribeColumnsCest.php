<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Postgresql;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Test\Fixtures\Traits\Db\PostgresqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class DescribeColumnsCest
 */
class DescribeColumnsCest
{
    use DiTrait;
    use PostgresqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: describeColumns()
     *
     * @param IntegrationTester $I
     *
     * @issue  https://github.com/phalcon/phalcon-devtools/issues/853
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-09-28
     */
    public function dbAdapterPdoPostgresqlDescribeColumns(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Postgresql - describeColumns()");
        $expected = [
            Column::__set_state(
                [
                    '_columnName'    => 'id',
                    '_schemaName'    => null,
                    '_type'          => 14,
                    '_typeReference' => -1,
                    '_typeValues'    => null,
                    '_isNumeric'     => true,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => "nextval('images_id_seq'::regclass)",
                    '_unsigned'      => false,
                    '_notNull'       => true,
                    '_primary'       => false,
                    '_autoIncrement' => true,
                    '_first'         => true,
                    '_after'         => null,
                    '_bindType'      => 1,
                ]
            ),
            Column::__set_state(
                [
                    '_columnName'    => 'base64',
                    '_schemaName'    => null,
                    '_type'          => 6,
                    '_typeReference' => -1,
                    '_typeValues'    => null,
                    '_isNumeric'     => false,
                    '_size'          => null,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_primary'       => false,
                    '_autoIncrement' => false,
                    '_first'         => false,
                    '_after'         => 'id',
                    '_bindType'      => 2,
                ]
            ),
        ];

        $actual = $this->connection->describeColumns('images');
        $I->assertEquals($expected, $actual);

        $actual = $this->connection->describeColumns('images', env('DATA_POSTGRES_SCHEMA'));
        $I->assertEquals($expected, $actual);
    }
}
