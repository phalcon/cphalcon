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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo\Mysql;

use Phalcon\Tests\AbstractDatabaseTestCase;

final class ExecutePreparedTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: executePrepared()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDbAdapterPdoMysqlExecutePrepared(): void
    {
        $this->markTestSkipped('Need implementation');
    }
}
