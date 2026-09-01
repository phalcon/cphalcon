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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use PDO;
use Phalcon\Db\RawValue;
use Phalcon\Mvc\Model\Query\StatusInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\InvoicesRawValue;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

/**
 * Tests Phalcon\Mvc\Model\Query :: executeSelect() - RawValue bind-splice must
 * not corrupt a placeholder whose name shares a prefix with the RawValue's
 * placeholder (":p" vs ":p1"). Regression for the non-anchored str_replace.
 */
final class ExecuteSelectRawValueSpliceTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * A RawValue bound to ":p:" is spliced inline; a separate ":p1:" bind must
     * survive untouched (word-boundary match), so the row is found by its
     * real, still-bound value.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryExecuteSelectRawValueSpliceKeepsPrefixedBind(): void
    {
        $manager = $this->getService('modelsManager');

        // Seed a row with a distinctive customer id.
        $insert = sprintf(
            "INSERT INTO [%s] (inv_cst_id, inv_status_flag, inv_title, inv_total) "
            . "VALUES (:cst_id:, :status:, :title:, :total:)",
            InvoicesRawValue::class
        );

        /** @var StatusInterface $status */
        $status = $manager->executeQuery(
            $insert,
            [
                'cst_id' => 7,
                'status' => 1,
                'title'  => 'spliced',
                'total'  => 10.0,
            ]
        );
        $this->assertTrue($status->success());

        // ":p" is a RawValue (spliced inline), ":p1" is a normal bind. The old
        // str_replace(":p", ...) would also rewrite ":p1" -> corrupting it.
        $phql = sprintf(
            "SELECT * FROM [%s] WHERE inv_status_flag = :p: AND inv_cst_id = :p1:",
            InvoicesRawValue::class
        );

        $result = $manager->executeQuery(
            $phql,
            [
                'p'  => new RawValue('1'),
                'p1' => 7,
            ]
        );

        $found = $result->getFirst();

        $this->assertNotNull($found);
        $this->assertSame(7, (int) $found->inv_cst_id);
        $this->assertSame('spliced', $found->inv_title);
    }
}
