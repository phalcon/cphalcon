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
final class GetHavingTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getHaving()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryBuilderGetHaving(): void
    {
        $builder = new Builder();

        $this->assertNull($builder->getHaving());

        $builder->having('SUM(inv_total) > 0');

        $this->assertSame('SUM(inv_total) > 0', $builder->getHaving());
    }
}
