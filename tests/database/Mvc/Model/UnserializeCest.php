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

namespace Phalcon\Tests\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;

use function date;
use function uniqid;

/**
 * Class UnserializeCest
 */
class UnserializeCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        (new InvoicesMigration($I->getConnection()));
    }

    /**
     * Tests Phalcon\Mvc\Model :: unserialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-31
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnserialize(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - unserialize()');

        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $data = [
            'inv_id'          => null,
            'inv_cst_id'      => 5,
            'inv_status_flag' => 2,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new Invoices();
        $invoice->assign($data);

        $result = $invoice->save();
        $I->assertNotFalse($result);

        $serialized = serialize($data);
        $newObject = unserialize($serialized);

        $I->assertEquals(
            $data,
            $newObject->toArray()
        );
    }
}
