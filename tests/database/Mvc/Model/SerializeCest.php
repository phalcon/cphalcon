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

use function date;
use function serialize;
use function uniqid;
use function unserialize;

/**
 * Class SerializeCest
 */
class SerializeCest
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
     * Tests Phalcon\Mvc\Model :: serialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    public function mvcModelSerialize(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - serialize()');

        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');
        $data  = [
            'inv_id'          => 1,
            'inv_cst_id'      => 2,
            'inv_status_flag' => 3,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new Invoices();
        $invoice->assign($data);
        $result = $invoice->save();

        $I->assertNotFalse($result);

        $serialized = serialize($invoice);

        $newObject = unserialize($serialized);

        $I->assertEquals(1, $newObject->inv_id);
        $I->assertEquals(2, $newObject->inv_cst_id);
        $I->assertEquals(3, $newObject->inv_status_flag);
        $I->assertEquals($title, $newObject->inv_title);
        $I->assertEquals(100.12, $newObject->inv_total);
        $I->assertEquals($date, $newObject->inv_created_at);
    }
}
