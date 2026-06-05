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

/**
 * Tests Phalcon\Mvc\Model\Query :: executeInsert() - RawValue bind params
 *
 * @issue https://github.com/phalcon/cphalcon/issues/15064
 */
final class ExecuteInsertRawValueTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: executeInsert() - RawValue bind param
     * with typed model properties: the raw SQL expression must be embedded
     * unquoted in the INSERT, not treated as a plain string value.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-28
     * @issue  https://github.com/phalcon/cphalcon/issues/15064
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryExecuteInsertRawValue(): void
    {
        $manager = $this->getService('modelsManager');

        $phql = sprintf(
            "INSERT INTO [%s] (inv_cst_id, inv_status_flag, inv_title, inv_total) "
            . "VALUES (:cst_id:, :status:, :title:, :total:)",
            InvoicesRawValue::class
        );

        /** @var StatusInterface $result */
        $result = $manager->executeQuery(
            $phql,
            [
                'cst_id' => 1,
                'status' => 1,
                'title'  => new RawValue("UPPER('hello')"),
                'total'  => 100.0,
            ]
        );

        $this->assertInstanceOf(StatusInterface::class, $result);
        $this->assertTrue($result->success());

        $invoice = InvoicesRawValue::findFirst(
            [
                'conditions' => 'inv_cst_id = :cst_id:',
                'bind'       => ['cst_id' => 1],
                'order'      => 'inv_id DESC',
            ]
        );

        $this->assertNotNull($invoice);
        $this->assertSame('HELLO', $invoice->inv_title);
    }
}
