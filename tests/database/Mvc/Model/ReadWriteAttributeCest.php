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

class ReadWriteAttributeCest
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
     * Tests Phalcon\Mvc\Model :: writeAttribute()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelWriteAttribute(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - writeAttribute()');

        $title   = uniqid('inv-');
        $invoice = new Invoices();
        $invoice->writeAttribute('inv_id', 123);
        $invoice->writeAttribute('inv_title', $title);

        $I->assertEquals(123, $invoice->readAttribute('inv_id'));
        $I->assertEquals($title, $invoice->readAttribute('inv_title'));

        $I->assertEquals(
            [
                'inv_id'          => 123,
                'inv_title'       => $title,
                'inv_cst_id'      => null,
                'inv_status_flag' => null,
                'inv_total'       => null,
                'inv_created_at'  => null,
            ],
            $invoice->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: writeAttribute() with associative array
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelWriteAttributeWithAssociativeArray(DatabaseTester $I)
    {
        $I->wantToTest('Phalcon\Mvc\Model :: writeAttribute() with associative array');

        $array = [
            'one' => uniqid('one-'),
            'two' => uniqid('two-'),
        ];

        $invoice = new Invoices();
        $invoice->writeAttribute('inv_id', 123);
        $invoice->writeAttribute('inv_title', $array);

        $I->assertEquals(
            $array,
            $invoice->readAttribute('inv_title')
        );

        $I->assertEquals(
            [
                'inv_id'          => 123,
                'inv_title'       => $array,
                'inv_cst_id'      => null,
                'inv_status_flag' => null,
                'inv_total'       => null,
                'inv_created_at'  => null,
            ],
            $invoice->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: writeAttribute() undefined property with
     * associative array
     *
     * @issue  14021
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelWriteAttributeUndefinedPropertyWithAssociativeArray(DatabaseTester $I)
    {
        $I->wantToTest(
            'Phalcon\Mvc\Model :: writeAttribute() undefined property with associative array'
        );

        $array = [
            'inv_id'    => 123,
            'inv_title' => uniqid('inv-'),
        ];

        $invoice = new Invoices();
        $invoice->writeAttribute('whatEverUndefinedProperty', $array);

        $I->assertEquals(
            [
                'inv_id'          => null,
                'inv_title'       => null,
                'inv_cst_id'      => null,
                'inv_status_flag' => null,
                'inv_total'       => null,
                'inv_created_at'  => null,
            ],
            $invoice->toArray()
        );
    }
}
