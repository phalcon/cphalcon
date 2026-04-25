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

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetSetWriteConnectionServiceTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-31
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelGetSetWriteConnectionService(): void
    {
        $invoice = new Invoices();

        $this->assertEquals('db', $invoice->getWriteConnectionService());

        $invoice->setWriteConnectionService('other');
        $this->assertEquals('other', $invoice->getWriteConnectionService());
    }
}
