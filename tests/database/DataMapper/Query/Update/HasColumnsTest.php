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

namespace Phalcon\Tests\Database\DataMapper\Query\Update;

use Phalcon\DataMapper\Query\QueryFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class HasColumnsTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQueryUpdateHasColumns(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $update     = $factory->newUpdate($connection);

        $actual = $update->hasColumns();
        $this->assertFalse($actual);

        $update->columns(['inv_id', 'inv_total']);

        $actual = $update->hasColumns();
        $this->assertTrue($actual);
    }
}
