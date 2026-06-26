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

namespace Phalcon\Tests\Database\Db\Column;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Db\Fake\DbTrait;
use Phalcon\Tests\Support\Migrations\FractalDatesMigration;
use Phalcon\Tests\Support\Models\FractalDates;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class GetScaleTest extends AbstractDatabaseTestCase
{
    use DbTrait;
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Column :: getScale()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnGetScale(): void
    {
        $columns         = $this->getColumnsArray();
        $expectedColumns = $this->getColumnsObjects();

        foreach ($expectedColumns as $index => $column) {
            // Column::getScale() returns int 0 when no scale is set; the
            // fixture array omits the 'scale' key for those rows, so
            // coalesce to 0 (not null) to keep the assertSame contract.
            $this->assertSame(
                $columns[$index]['scale'] ?? 0,
                $column->getScale()
            );
        }
    }

    /**
     * Tests Phalcon\Db\Column :: getScale() - datetime, time, timestamp
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-23
     */
    #[Group('mysql')]
    public function testDbColumnGetScaleDateTimeTimeTimeStamp(): void
    {
        // pgsql/sqlite are excluded above - the FractalDates schema and
        // sub-second precision behavior tested here are mysql-specific.
        $connection = self::getConnection();
        $migration  = new FractalDatesMigration($connection);
        $migration->clear();
        $migration->insert(
            1,
            '14:15:16.444',
            '2019-12-25 17:18:19.666',
            '2019-12-25 20:21:22.888'
        );

        $record = FractalDates::findFirst('id = 1');

        $this->assertSame(1, $record->id);
        $this->assertSame('14:15:16.44', $record->ftime);
        $this->assertSame('2019-12-25 17:18:19.67', $record->fdatetime);
        $this->assertSame('2019-12-25 20:21:22.89', $record->ftimestamp);
    }
}
