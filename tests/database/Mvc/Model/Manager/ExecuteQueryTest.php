<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Mvc\Model\Query\StatusInterface;
use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class ExecuteQueryTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }
        $this->setDatabase();

        // Recreate the table so the test is isolated from records left behind
        // by earlier tests (the auto-increment INSERT below otherwise collides
        // on PostgreSQL when a prior test seeded inv_id = 1).
        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }
    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/15024
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-06
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelManagerExecuteQuery(): void
    {
        /** @var ManagerInterface $manager */
        $manager = $this->getService("modelsManager");
        $sql = sprintf("SELECT * FROM [%s]", Invoices::class);
        $this->assertInstanceOf(Simple::class, $manager->executeQuery($sql));
        $sql = sprintf("SELECT SUM(inv_total) AS s FROM [%s]", Invoices::class);
        $this->assertInstanceOf(Simple::class, $manager->executeQuery($sql));
        $sql = sprintf("SELECT i.inv_total FROM [%s] AS i WHERE i.inv_id = :id:", Invoices::class);
        $this->assertInstanceOf(Simple::class, $manager->executeQuery($sql, ["id" => 0]));
        $sql = sprintf("SELECT COUNT(inv_status_flag) FROM [%s] GROUP BY inv_status_flag", Invoices::class);
        $this->assertInstanceOf(Complex::class, $manager->executeQuery($sql));
        $sql = sprintf("INSERT INTO [%s] (inv_total) VALUES (1)", Invoices::class);
        $this->assertInstanceOf(StatusInterface::class, $manager->executeQuery($sql));
        $sql = sprintf("UPDATE [%s] SET inv_total = 0 WHERE inv_id = :id:", Invoices::class);
        $this->assertInstanceOf(StatusInterface::class, $manager->executeQuery($sql, ["id" => 0]));
        $sql = sprintf("DELETE FROM [%s] WHERE inv_id = :id:", Invoices::class);
        $this->assertInstanceOf(StatusInterface::class, $manager->executeQuery($sql, ["id" => 0]));
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16976
     * @issue  https://github.com/phalcon/cphalcon/issues/2373
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-04
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelManagerExecuteQueryIssue16976(): void
    {
        $this->markTestSkipped(
            "Skipped pending re-implementation of #16976. "
            . "Original fix reverted because the substitution path triggered "
            . "a use-after-free during record->update (#17042)."
        );

        /** @var ManagerInterface $manager */
        $manager = $this->getService("modelsManager");

        $manager->executeQuery(
            sprintf("INSERT INTO [%s] (inv_total) VALUES (0)", Invoices::class)
        );

        $invoice = Invoices::findFirst(
            [
                "order" => "inv_id DESC",
            ]
        );

        $this->assertNotFalse($invoice);

        $manager->useDynamicUpdate($invoice, true);

        $id = (int) $invoice->inv_id;

        $manager->executeQuery(
            sprintf("UPDATE [%s] SET inv_total = 0 WHERE inv_id = :id:", Invoices::class),
            ["id" => $id]
        );

        $status = $manager->executeQuery(
            sprintf(
                "UPDATE [%s] SET inv_total = inv_total + :inc: WHERE inv_id = :id:",
                Invoices::class
            ),
            [
                "id"  => $id,
                "inc" => 2,
            ]
        );

        $this->assertInstanceOf(StatusInterface::class, $status);
        $this->assertTrue($status->success());

        $invoice = Invoices::findFirst(
            [
                "conditions" => "inv_id = :id:",
                "bind"       => ["id" => $id],
            ]
        );

        $this->assertNotFalse($invoice);
        $this->assertSame(2.0, (float) $invoice->inv_total);
    }
}
