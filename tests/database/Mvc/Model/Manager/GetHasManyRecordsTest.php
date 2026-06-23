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

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Mvc\Model\Resultset;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\AlbumsMigration;
use Phalcon\Tests\Support\Migrations\ArtistsMigration;
use Phalcon\Tests\Support\Models\AlbumORama\Albums;
use Phalcon\Tests\Support\Models\AlbumORama\Artists;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetHasManyRecordsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: getHasManyRecords()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelManagerGetHasManyRecords(): void
    {
        $connection = self::getConnection();

        $artistsMigration = new ArtistsMigration($connection);
        $artistsMigration->insert(1, 'Artist 1');

        $albumsMigration = new AlbumsMigration($connection);
        $albumsMigration->insert(1, 1, 'Album 1');
        $albumsMigration->insert(2, 1, 'Album 2');

        $artist  = Artists::findFirst(1);
        $manager = $artist->getModelsManager();

        $records = $manager->getHasManyRecords(Artists::class, Albums::class, $artist);

        $this->assertInstanceOf(Resultset\Simple::class, $records);
        $this->assertSame(2, $records->count());
    }
}
