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
use Phalcon\Tests\Support\Models\Customers;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetJoinsTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getJoins()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryBuilderGetJoins(): void
    {
        $builder = new Builder();

        $this->assertSame([], $builder->getJoins());

        $builder->innerJoin(Customers::class, 'Customers.cst_id = Invoices.inv_cst_id', 'c');

        $this->assertSame(
            [
                [Customers::class, 'Customers.cst_id = Invoices.inv_cst_id', 'c', 'INNER'],
            ],
            $builder->getJoins()
        );
    }
}
