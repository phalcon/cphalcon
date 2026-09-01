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

namespace Phalcon\Tests\Database\DataMapper\Query\Select;

use Phalcon\DataMapper\Query\QueryFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class WhereEqualsTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectWhereEquals(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->whereEquals(
                [
                    'inv_id'     => [1, 2, 3],
                    'inv_cst_id' => null,
                    'inv_title'  => 'ACME',
                    'inv_created_at = NOW()',
                ]
            )
        ;

        $expected = "SELECT * "
            . "FROM co_invoices "
            . "WHERE inv_id IN (:__1__, :__2__, :__3__) "
            . "AND inv_cst_id IS NULL "
            . "AND inv_title = :__4__ "
            . "AND inv_created_at = NOW()";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);
    }
}
