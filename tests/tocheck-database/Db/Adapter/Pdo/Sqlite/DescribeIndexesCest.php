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
use Phalcon\Db\Index;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class DescribeIndexesCest
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
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: describeIndexes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteDescribeIndexes(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - describeIndexes()');

        $connection = $this->getService('db');

        $expectedIndexes = [
            'sqlite_autoindex_COMPANY_1' => new Index(
                'sqlite_autoindex_COMPANY_1',
                ['ID'],
                'PRIMARY'
            ),
            'salary_index'               => new Index(
                'salary_index',
                ['SALARY']
            ),
            'name_index'                 => new Index(
                'name_index',
                ['NAME'],
                'UNIQUE'
            ),
        ];

        $I->assertEquals(
            $expectedIndexes,
            $connection->describeIndexes('COMPANY')
        );

        $I->assertEquals(
            $expectedIndexes,
            $connection->describeIndexes('company', 'main')
        );
    }
}
