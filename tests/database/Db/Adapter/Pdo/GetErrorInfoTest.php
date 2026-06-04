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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Throwable;

final class GetErrorInfoTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: getErrorInfo()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoGetErrorInfo(): void
    {
        $db = $this->container->get('db');

        $info = $db->getErrorInfo();
        $this->assertIsArray($info);
        $this->assertCount(3, $info);

        try {
            $db->query('SELECT * FROM definitely_not_a_real_table_zzz');
        } catch (Throwable $e) {
            // expected
        }

        $infoAfter = $db->getErrorInfo();
        $this->assertIsArray($infoAfter);
        $this->assertCount(3, $infoAfter);
    }
}
