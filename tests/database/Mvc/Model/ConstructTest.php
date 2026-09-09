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
use Phalcon\Mvc\ModelInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class ConstructTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelConstruct(): void
    {
        $invoice = new Invoices();

        $this->assertInstanceOf(
            Model::class,
            $invoice
        );
        $this->assertInstanceOf(
            ModelInterface::class,
            $invoice
        );
    }

    /**
     * A non-array `data` argument is ignored, as the Zephir source does,
     * instead of reaching `assign()` and raising a `TypeError`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-04
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelConstructIgnoresNonArrayData(): void
    {
        $invoice = new Invoices('nonsense');

        $this->assertInstanceOf(ModelInterface::class, $invoice);
        $this->assertNull($invoice->inv_title);
    }
}
