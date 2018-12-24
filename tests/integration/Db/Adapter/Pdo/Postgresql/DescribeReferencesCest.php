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
use Phalcon\Test\Fixtures\Traits\Db\PostgresqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class DescribeReferencesCest
 */
class DescribeReferencesCest
{
    use DiTrait;
    use PostgresqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: describeReferences()
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-09-28
     */
    public function dbAdapterPdoPostgresqlDescribeReferences(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Postgresql - describeReferences()");

        $referencesNoSchema = $this->connection->describeReferences('robots_parts');
        $referencesSchema   = $this->connection->describeReferences('robots_parts', env('DATA_POSTGRES_SCHEMA'));

        $I->assertEquals($referencesNoSchema, $referencesSchema);

        $I->assertCount(2, $referencesNoSchema);

        foreach ($referencesNoSchema as $reference) {
            $I->assertCount(1, $reference->getColumns());
        }
    }
}
