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
use PDO;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Test\Fixtures\Migrations\CustomersDefaultsMigration;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Migrations\SettersMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\CustomersDefaults;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\Setters;

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
     * @group  mysql
     * @group  sqlite
     * @group  pgsql
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

    /**
     * Tests Phalcon\Mvc\Model :: update() - with default values
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14924
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-10-18
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveAfterWithoutDefaultValues(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - update() - with default values');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $customersMigration = new CustomersDefaultsMigration($connection);
        $customersMigration->clear();

        /**
         * Customer is created manually with empty first and last name
         */
        $customersMigration->insert(1, 1, null, null);

        $manualCustomer = CustomersDefaults::findFirst(1);

        $I->assertEquals(
            '',
            $manualCustomer->cst_name_first
        );

        $I->assertEquals(
            '',
            $manualCustomer->cst_name_last
        );

        /**
         * Validation should fail because we don't allow
         * empty strings for `not null` columns
         */
        $I->assertFalse(
            $manualCustomer->update()
        );

        /**
         * Customer is created by ORM with proper default values
         */
        $ormCustomer = new CustomersDefaults();

        $I->assertTrue(
            $ormCustomer->create()
        );

        $I->assertEquals(
            'cst_default_firstName',
            $ormCustomer->cst_name_first
        );

        $I->assertEquals(
            'cst_default_lastName',
            $ormCustomer->cst_name_last
        );

        $I->assertTrue(
            $ormCustomer->update()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: update() - via setters and local method
     *
     * @see    https://github.com/phalcon/cphalcon/discussions/15625
     *
     * @author Anton Vasiliev <https://github.com/Jeckerson>
     * @since  2021-08-20
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveViaSettersAndLocalMethod(DatabaseTester $I): void
    {
        $I->wantToTest('Mvc\Model - update() - with default values');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $settersMigration = new SettersMigration($connection);
        $settersMigration->clear();
        $settersMigration->insert('value1', 'value2', 'value3');

        /**
         * Validate initial data
         */
        $row = Setters::findFirst(1);
        $I->assertEquals('value1', $row->getColumn1());
        $I->assertEquals('value2', $row->getColumn2());
        $I->assertEquals('value3', $row->getColumn3());

        /**
         * First save via local method
         */
        $firstValue = 'value2';
        $this->setColumn1($row, $firstValue);
        $I->assertEquals($firstValue, $row->getColumn1());
        $I->assertEquals($firstValue, Setters::findFirst(1)->getColumn1());

        /**
         * Second save via model's setter and direct save() call
         */
        $secondValue = 'value3';
        $row->setColumn2($secondValue);
        $row->save();
        $I->assertEquals($secondValue, $row->getColumn2());
        $I->assertEquals($secondValue, Setters::findFirst(1)->getColumn2());

        /**
         * Final assertions
         */
        $I->assertEquals($firstValue, $row->getColumn1());
        $I->assertEquals($secondValue, $row->getColumn2());
        $I->assertEquals('value3', $row->getColumn3());
        $I->assertEquals($firstValue, Setters::findFirst(1)->getColumn1());
        $I->assertEquals($secondValue, Setters::findFirst(1)->getColumn2());
        $I->assertEquals('value3', Setters::findFirst(1)->getColumn3());
    }

    private function setColumn1(ModelInterface $model, string $value): void
    {
        $model->setColumn1($value);
        $model->save();
    }
}
