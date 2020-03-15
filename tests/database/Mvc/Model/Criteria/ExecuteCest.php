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

namespace Phalcon\Test\Database\Mvc\Model\Criteria;

use DatabaseTester;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;

use function uniqid;

/**
 * Class ExecuteCest
 */
class ExecuteCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: execute()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function mvcModelCriteriaExecute(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - execute()');

        $title      = uniqid('inv-');
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, 1, 2, $title);

        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $result = $criteria
            ->setModelName(Invoices::class)
            ->andWhere('inv_cst_id = :custId:', ['custId' => 1])
            ->execute()
        ;

        $I->assertInstanceOf(Simple::class, $result);

        $I->assertEquals(4, $result[0]->inv_id);
        $I->assertEquals(1, $result[0]->inv_cst_id);
        $I->assertEquals(2, $result[0]->inv_status_flag);
        $I->assertEquals($title, $result[0]->inv_title);
        $I->assertEquals(0.00, $result[0]->inv_total);
    }
}
