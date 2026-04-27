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

namespace Phalcon\Tests\Database\Db\Adapter;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetSQLVariablesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: query()
     *
     * @issue
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-31
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterGetSqlVariablesInit(): void
    {
        $db = $this->container->get('db');

        $actual = $db->getSQLVariables();
        $this->assertIsArray($actual);
        $this->assertEmpty($actual);
    }
}
