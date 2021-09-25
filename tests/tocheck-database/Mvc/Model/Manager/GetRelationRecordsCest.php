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

namespace Phalcon\Tests\Integration\Mvc\Model\Manager;

use IntegrationTester;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\AlbumORama\Albums;
use Phalcon\Tests\Models\AlbumORama\Artists;
use Phalcon\Tests\Models\AlbumORama\Songs;

class GetRelationRecordsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: getRelationRecords()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-22
     */
    public function mvcModelManagerGetRelationRecords(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - getRelationRecords()');

        /**
         * @var Albums
         */
        $album = Albums::findFirst(1);

        /**
         * @var Manager
         */
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

        $I->assertInstanceOf(
            Artists::class,
            $artistRelationRecord
        );

        $I->assertEquals(
            [
                'id'   => 1,
                'name' => 'Lana del Rey',
            ],
            $artistRelationRecord->toArray()
        );


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

        $I->assertEquals(
            7,
            $songsRelationRecordsCount
        );

        $songsRelationRecords = $modelsManager->getRelationRecords(
            $songsRelation,
            $album,
            [
                'id <= 5',
            ]
        );

        $I->assertInstanceOf(
            Resultset\Simple::class,
            $songsRelationRecords
        );

        $I->assertInstanceOf(
            Songs::class,
            $songsRelationRecords->getFirst()
        );

        $I->assertEquals(
            5,
            $songsRelationRecords->count()
        );


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

        $I->assertInstanceOf(
            Resultset\Simple::class,
            $singlesRelationRecords
        );

        $I->assertInstanceOf(
            Songs::class,
            $singlesRelationRecords->getFirst()
        );

        $I->assertEquals(
            1,
            $singlesRelationRecords->count()
        );

        $I->assertEquals(
            [
                'id'        => 1,
                'albums_id' => $album->id,
                'name'      => 'Born to Die',
            ],
            $singlesRelationRecords->getFirst()->toArray()
        );
    }
}
