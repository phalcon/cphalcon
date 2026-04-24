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

namespace Phalcon\Tests\Database\Mvc\Model\Criteria;

use Phalcon\Mvc\Model\Criteria;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

/**
 *
 * @group phql
 */
final class ExecuteTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelCriteriaExecute(): void
    {
        $title      = uniqid('inv-');
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, 1, 2, $title);

        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $result = $criteria
            ->setModelName(Invoices::class)
            ->andWhere('inv_cst_id = :custId:', ['custId' => 1])
            ->execute()
        ;

        $this->assertInstanceOf(Simple::class, $result);

        $this->assertEquals(4, $result[0]->inv_id);
        $this->assertEquals(1, $result[0]->inv_cst_id);
        $this->assertEquals(2, $result[0]->inv_status_flag);
        $this->assertEquals($title, $result[0]->inv_title);
        $this->assertEquals(0.00, $result[0]->inv_total);
    }
}
