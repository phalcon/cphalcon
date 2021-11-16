<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo\Postgresql;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Tests\Fixtures\Traits\Db\PostgresqlTrait;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class DescribeColumnsCest
{
    use DiTrait;
    use PostgresqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: describeColumns()
     *
     * @issue  https://github.com/phalcon/phalcon-devtools/issues/853
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-09-28
     */
    public function dbAdapterPdoPostgresqlDescribeColumns(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Postgresql - describeColumns()");

        $expected = [
            new Column(
                'id',
                [
                    'type'          => 14,
                    'typeReference' => -1,
                    'typeValues'    => null,
                    'isNumeric'     => true,
                    'size'          => 0,
                    'scale'         => 0,
                    'default'       => "nextval('images_id_seq'::regclass)",
                    'unsigned'      => false,
                    'notNull'       => true,
                    'primary'       => false,
                    'autoIncrement' => true,
                    'first'         => true,
                    'after'         => null,
                    'bindType'      => 1,
                ]
            ),
            new Column(
                'base64',
                [
                    'type'          => 6,
                    'typeReference' => -1,
                    'typeValues'    => null,
                    'isNumeric'     => false,
                    'size'          => null,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'primary'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'id',
                    'bindType'      => 2,
                ]
            ),
        ];


        $actual = $this->connection->describeColumns('images');

        $I->assertEquals($expected, $actual);


        $actual = $this->connection->describeColumns(
            'images',
            env('DATA_POSTGRES_SCHEMA')
        );

        $I->assertEquals($expected, $actual);
    }
}
