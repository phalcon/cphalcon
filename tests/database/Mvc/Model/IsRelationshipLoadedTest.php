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

use PDO;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\AlbumsMigration;
use Phalcon\Tests\Support\Migrations\ArtistsMigration;
use Phalcon\Tests\Support\Migrations\SongsMigration;
use Phalcon\Tests\Support\Models\AlbumORama\Albums;
use Phalcon\Tests\Support\Models\AlbumORama\Artists;
use Phalcon\Tests\Support\Models\AlbumORama\Songs;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class IsRelationshipLoadedTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @return void
     */
    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getConnection();

        $artistsMigration = new ArtistsMigration($connection);
        $artistsMigration->insert(1, 'Test Artist');

        $albumsMigration = new AlbumsMigration($connection);
        $albumsMigration->insert(1, 1, 'Test Album');

        $songsMigration = new SongsMigration($connection);
        $songsMigration->insert(1, 1, 'Test Song One');
        $songsMigration->insert(2, 1, 'Test Song Two');
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelIsRelationshipLoadedViaUnderscoreGet(): void
    {
        /** @var Albums $album */
        $album = Albums::findFirst();

        $this->assertFalse(
            $album->isRelationshipLoaded('artist')
        );

        $this->assertFalse(
            $album->isRelationshipLoaded('songs')
        );

        /** @var Artists $artist */
        $artist = $album->artist;

        $this->assertTrue(
            $album->isRelationshipLoaded('artist')
        );

        /** @var \Phalcon\Mvc\Model\Resultset\Simple $songs */
        $songs = $album->songs;

        $this->assertTrue(
            $album->isRelationshipLoaded('songs')
        );
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelIsRelationshipLoadedViaUnderscoreSet(): void
    {
        /** @var Albums $album */
        $album = Albums::findFirst();

        $this->assertFalse(
            $album->isRelationshipLoaded('artist')
        );

        $this->assertFalse(
            $album->isRelationshipLoaded('songs')
        );

        $album->artist = new Artists();

        $this->assertFalse(
            $album->isRelationshipLoaded('artist')
        );

        $album->songs = [
            new Songs(),
            new Songs(),
        ];

        $this->assertFalse(
            $album->isRelationshipLoaded('songs')
        );
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelIsRelationshipLoadedViaCallGetters(): void
    {
        /** @var Albums $album */
        $album = Albums::findFirst();

        $this->assertFalse(
            $album->isRelationshipLoaded('artist')
        );

        $this->assertFalse(
            $album->isRelationshipLoaded('songs')
        );

        /** @var Artists $artist */
        $artist = $album->getArtist();

        $this->assertTrue(
            $album->isRelationshipLoaded('artist')
        );

        /** @var \Phalcon\Mvc\Model\Resultset\Simple $songs */
        $songs = $album->getSongs();

        $this->assertTrue(
            $album->isRelationshipLoaded('songs')
        );
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelIsRelationshipLoadedViaGetRelated(): void
    {
        /** @var Albums $album */
        $album = Albums::findFirst();

        $this->assertFalse(
            $album->isRelationshipLoaded('artist')
        );

        $this->assertFalse(
            $album->isRelationshipLoaded('songs')
        );

        /** @var Artists $artist */
        $artist = $album->getRelated('artist');

        $this->assertTrue(
            $album->isRelationshipLoaded('artist')
        );

        /** @var \Phalcon\Mvc\Model\Resultset\Simple $songs */
        $songs = $album->getRelated('songs');

        $this->assertTrue(
            $album->isRelationshipLoaded('songs')
        );
    }
}
