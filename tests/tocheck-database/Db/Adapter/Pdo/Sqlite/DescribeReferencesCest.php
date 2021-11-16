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

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;
use Phalcon\Db\Reference;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class DescribeReferencesCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiModelsManager();
        $this->setDiModelsMetadata();
        $this->setDiSqlite();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: describeReferences()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteDescribeReferences(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $expectedReferences = [
            'foreign_key_0' => new Reference(
                'foreign_key_0',
                [
                    'referencedTable'   => 'parts',
                    'columns'           => ['parts_id'],
                    'referencedColumns' => ['id'],
                    'referencedSchema'  => null,
                ]
            ),
            'foreign_key_1' => new Reference(
                'foreign_key_1',
                [
                    'referencedTable'   => 'robots',
                    'columns'           => ['robots_id'],
                    'referencedColumns' => ['id'],
                    'referencedSchema'  => null,
                ]
            ),
        ];

        $I->assertEquals(
            $expectedReferences,
            $connection->describeReferences('robots_parts')
        );
    }
}
