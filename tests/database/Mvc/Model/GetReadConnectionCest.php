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
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;

/**
 * Class GetReadConnectionCest
 */
class GetReadConnectionCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model :: getReadConnection()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-31
     */
    public function mvcModelGetReadConnection(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - getReadConnection()');

        $connection = $this->container->get('db');
        $invoice    = new Invoices();

        $I->assertEquals($connection, $invoice->getReadConnection());
    }
}
