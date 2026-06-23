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

namespace Phalcon\Tests\Database\Mvc\Model\Query\Builder;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ColumnsTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: columns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryBuilderColumns(): void
    {
        $builder = new Builder();
        $builder
            ->columns('inv_id, inv_total')
            ->addFrom(Invoices::class);

        $this->assertSame('inv_id, inv_total', $builder->getColumns());

        $this->assertSame(
            'SELECT inv_id, inv_total FROM [' . Invoices::class . ']',
            $builder->getPhql()
        );
    }
}
