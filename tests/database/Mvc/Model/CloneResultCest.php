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

use Codeception\Example;
use DatabaseTester;
use Phalcon\Mvc\Model;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\CustomersKeepSnapshots;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\InvoicesMap;

/**
 * Class CloneResultCest
 */
class CloneResultCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model :: cloneResult()
     *
     * @dataProvider modelDataProvider
     *
     * @param DatabaseTester $I
     * @param Example        $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-10-16
     *
     * @group        mysql
     * @group        pgsql
     * @group        sqlite
     */
    public function cloneResult(DatabaseTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Model - cloneResult()');

        $base = new Invoices();

        $data = [
            'inv_id'          => $example['inv_id'],
            'inv_cst_id'      => $example['inv_cst_id'],
            'inv_status_flag' => $example['inv_status_flag'],
            'inv_title'       => $example['inv_title'],
            'inv_total'       => $example['inv_total'],
            'inv_created_at'  => $example['inv_created_at']
        ];

        /**
         * @var InvoicesMap $invoice
         */
        $invoice = Model::cloneResult(
            $base,
            $data
        );

        $I->assertEquals(
            $data,
            $invoice->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: cloneResult() is using setters
     *
     * @param DatabaseTester $I
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-10-16
     *
     * @group        mysql
     * @group        pgsql
     * @group        sqlite
     */
    public function cloneResultUsingSetters(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - cloneResult() is using setters');

        $base = new CustomersKeepSnapshots();

        $customer = Model::cloneResult(
            $base,
            [
                'cst_status_flag' => 2
            ]
        );

        $I->assertEquals(
            3,
            $customer->cst_status_flag
        );
    }

    /**
     * @return array
     */
    protected function modelDataProvider(): array
    {
        return [
            [
                'inv_id'          => '1',
                'inv_cst_id'      => '42',
                'inv_status_flag' => '1',
                'inv_title'       => 'Test title',
                'inv_total'       => '3.14',
                'inv_created_at'  => '2020-10-05 20:43',
            ],
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 42,
                'inv_status_flag' => 1,
                'inv_title'       => 'Test title',
                'inv_total'       => 3.14,
                'inv_created_at'  => '2020-10-05 20:43',
            ]
        ];
    }
}
