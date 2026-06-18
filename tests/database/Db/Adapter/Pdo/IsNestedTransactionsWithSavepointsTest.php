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
use PHPUnit\Framework\Attributes\Group;

final class IsNestedTransactionsWithSavepointsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: isNestedTransactionsWithSavepoints() /
     * setNestedTransactionsWithSavepoints()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoIsNestedTransactionsWithSavepoints(): void
    {
        $db = $this->container->get('db');

        $this->assertFalse($db->isNestedTransactionsWithSavepoints());

        $db->setNestedTransactionsWithSavepoints(true);
        $this->assertTrue($db->isNestedTransactionsWithSavepoints());

        $db->setNestedTransactionsWithSavepoints(false);
        $this->assertFalse($db->isNestedTransactionsWithSavepoints());
    }
}
