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

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Tests\Models\Invoices;
use UnitTester;

class SerializeDirtyStateCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query :: serialize() - with dirtyState
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-11-09
     * @issue        15571
     */
    public function mvcModelSerializeDirtyState(UnitTester $I)
    {
        $I->wantToTest('Phalcon\Mvc\Model - serialize() - with dirtyState');

        $invoice = new Invoices();
        $invoice->setDirtyState(0);
        $data = serialize($invoice);

        /** @var Invoices $unSerializedInvoice */
        $unSerializedInvoice = unserialize($data);
        $dirtyState = $unSerializedInvoice->getDirtyState();

        $I->assertEquals(0, $dirtyState);
    }
}
