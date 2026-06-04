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

use function env;

final class SharedLockTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: sharedLock()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoSharedLock(): void
    {
        $db = $this->container->get('db');

        $expected = [
            'mysql'  => 'SELECT 1 LOCK IN SHARE MODE',
            'pgsql'  => 'SELECT 1 FOR SHARE',
            'sqlite' => 'SELECT 1',
        ][env('driver')];

        $this->assertSame($expected, $db->sharedLock('SELECT 1'));
    }
}
