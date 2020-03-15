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
use Phalcon\Test\Models\Invoices;

use function uniqid;

/**
 * Class UpdateCest
 */
class UpdateCest
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
     * Tests Phalcon\Mvc\Model :: update()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-31
     *
     * @group mysql
     * @group sqlite
     * @group pgsql
     */
    public function mvcModelUpdate(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - update()');

        $title   = uniqid('inv-');
        $invoice = new Invoices();
        $invoice->assign(
            [
                'inv_title' => $title,
            ]
        );

        $result = $invoice->save();
        $I->assertNotFalse($result);

        $invoice->inv_cst_id      = 456;
        $invoice->inv_status_flag = 2;

        $result = $invoice->update();
        $I->assertNotFalse($result);

        /**
         * Get the record again to ensure that the update is successful
         */
        $record = Invoices::findFirst(
            [
                'conditions' => 'inv_title = :title:',
                'bind'       => [
                    'title' => $title,
                ],
            ]
        );

        $I->assertEquals(
            [
                'inv_id'          => $invoice->inv_id,
                'inv_title'       => $title,
                'inv_cst_id'      => 456,
                'inv_status_flag' => 2,
                'inv_total'       => null,
                'inv_created_at'  => null,
            ],
            $record->toArray()
        );
    }
}
