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

namespace Phalcon\Test\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\AlbumORama\Artists;

use Phalcon\Test\Models\Invoices;
use function date;
use function uniqid;

/**
 * Class DeleteCest
 */
class DeleteCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration = new InvoicesMigration($connection);
        $migration->clear();
    }

    /**
     * Tests Phalcon\Mvc\Model :: delete()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelDelete(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - delete()');

        $title   = uniqid('inv-');
        $date    = date('Y-m-d H:i:s');
        $invoice = new Invoices();
        $invoice->inv_id          = 1;
        $invoice->inv_cst_id      = 2;
        $invoice->inv_status_flag = 3;
        $invoice->inv_title       = $title;
        $invoice->inv_total       = 100.12;
        $invoice->inv_created_at  = $date;

        $result = $invoice->create();
        $I->assertNotFalse($result);

        $result = $invoice->delete();
        $I->assertTrue($result);
    }
}
