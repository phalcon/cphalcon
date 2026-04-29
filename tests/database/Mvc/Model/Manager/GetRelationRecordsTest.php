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

use PDO;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\Resultset;
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
final class GetRelationRecordsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-22
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelManagerGetRelationRecords(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $artistsMigration = new ArtistsMigration($connection);
        $artistsMigration->insert(1, 'Lana del Rey');

        $albumsMigration = new AlbumsMigration($connection);
        $albumsMigration->insert(1, 1, 'Born to Die');

        $songsMigration = new SongsMigration($connection);
        $songsMigration->insert(1, 1, 'Born to Die');
        $songsMigration->insert(2, 1, 'Off to the Races');
        $songsMigration->insert(3, 1, 'Blue Jeans');
        $songsMigration->insert(4, 1, 'Video Games');
        $songsMigration->insert(5, 1, 'Diet Mountain Dew');
        $songsMigration->insert(6, 1, 'National Anthem');
        $songsMigration->insert(7, 1, 'Dark Paradise');

        /** @var Albums $album */
        $album = Albums::findFirst(1);

        /** @var Manager $modelsManager */
        $modelsManager = $album->getModelsManager();

        /**
         * Relation: belongsTo artist
         */
        $artistRelation = $modelsManager->getRelationByAlias(
            Albums::class,
            'artist'
        );

        $artistRelationRecord = $modelsManager->getRelationRecords(
            $artistRelation,
            $album
        );

        $this->assertInstanceOf(Artists::class, $artistRelationRecord);

        $expected = [
            'id'   => 1,
            'name' => 'Lana del Rey',
        ];
        $actual   = $artistRelationRecord->toArray();
        $this->assertEquals($expected, $actual);

        /**
         * Relation: hasMany songs
         */
        $songsRelation = $modelsManager->getRelationByAlias(
            Albums::class,
            'songs'
        );

        $songsRelationRecordsCount = $modelsManager->getRelationRecords(
            $songsRelation,
            $album,
            [],
            'count'
        );

        $expected = 7;
        $this->assertEquals($expected, $songsRelationRecordsCount);

        $songsRelationRecords = $modelsManager->getRelationRecords(
            $songsRelation,
            $album,
            [
                'id <= 5',
            ]
        );

        $this->assertInstanceOf(Resultset\Simple::class, $songsRelationRecords);
        $this->assertInstanceOf(Songs::class, $songsRelationRecords->getFirst());

        $expected = 5;
        $actual   = $songsRelationRecords->count();
        $this->assertEquals($expected, $actual);

        /**
         * Relation: hasMany singles (with multiple referenced fields)
         */
        $singlesRelation = $modelsManager->getRelationByAlias(
            Albums::class,
            'singles'
        );

        $singlesRelationRecords = $modelsManager->getRelationRecords(
            $singlesRelation,
            $album
        );

        $this->assertInstanceOf(Resultset\Simple::class, $singlesRelationRecords);
        $this->assertInstanceOf(Songs::class, $singlesRelationRecords->getFirst());

        $expected = 1;
        $actual   = $singlesRelationRecords->count();
        $this->assertEquals($expected, $actual);

        $expected = [
            'id'        => 1,
            'albums_id' => $album->id,
            'name'      => 'Born to Die',
        ];
        $actual   = $singlesRelationRecords->getFirst()->toArray();
        $this->assertEquals($expected, $actual);
    }
}
