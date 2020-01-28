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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Postgresql;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\Db\PostgresqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DescribeReferencesCest
{
    use DiTrait;
    use PostgresqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: describeReferences()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-09-28
     */
    public function dbAdapterPdoPostgresqlDescribeReferences(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Postgresql - describeReferences()");

        $referencesNoSchema = $this->connection->describeReferences('robots_parts');

        $referencesSchema = $this->connection->describeReferences(
            'robots_parts',
            env('DATA_POSTGRES_SCHEMA')
        );

        $I->assertEquals($referencesNoSchema, $referencesSchema);

        $I->assertCount(2, $referencesNoSchema);

        foreach ($referencesNoSchema as $reference) {
            $I->assertCount(
                1,
                $reference->getColumns()
            );
        }
    }
}
