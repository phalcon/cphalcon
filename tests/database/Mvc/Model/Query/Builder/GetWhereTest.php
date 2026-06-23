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
final class GetWhereTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getWhere()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryBuilderGetWhere(): void
    {
        $builder = new Builder();

        $this->assertNull($builder->getWhere());

        $builder->where('inv_id > 0');

        $this->assertSame('inv_id > 0', $builder->getWhere());
    }
}
