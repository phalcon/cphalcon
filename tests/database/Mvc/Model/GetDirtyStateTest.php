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

use Phalcon\Mvc\Model;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetDirtyStateTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelGetDirtyState(): void
    {
        $invoice = new Invoices();

        // A freshly created model is transient
        $this->assertSame(
            Model::DIRTY_STATE_TRANSIENT,
            $invoice->getDirtyState()
        );

        $invoice->setDirtyState(Model::DIRTY_STATE_PERSISTENT);

        $this->assertSame(
            Model::DIRTY_STATE_PERSISTENT,
            $invoice->getDirtyState()
        );
    }
}
