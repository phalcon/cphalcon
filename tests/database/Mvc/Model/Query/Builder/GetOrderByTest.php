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
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetOrderByTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getOrderBy()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryBuilderGetOrderBy(): void
    {
        $builder = new Builder();

        $this->assertNull($builder->getOrderBy());

        $builder->orderBy('inv_id DESC');

        $this->assertSame('inv_id DESC', $builder->getOrderBy());
    }
}
