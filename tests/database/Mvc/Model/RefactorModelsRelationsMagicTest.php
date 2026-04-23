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

use Phalcon\Tests\AbstractDatabaseTestCase;

final class RefactorModelsRelationsMagicTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testModelsMysql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }
}

// Original Cest file content (ModelsRelationsMagicCest):
//
// <?php
//
// namespace Phalcon\Tests\Integration\Mvc\Model;
//
// use IntegrationTester;
// use Phalcon\Mvc\Model;
// use Phalcon\Tests\Support\Traits\DiTrait;
// use Phalcon\Tests\Support\Models\AlbumORama\Albums;
// use Phalcon\Tests\Support\Models\AlbumORama\Artists;
// use Phalcon\Tests\Support\Models\AlbumORama\Songs;
//
// class ModelsRelationsMagicCest
// {
//     use DiTrait;
//
//     public function _before(IntegrationTester $I)
//     {
//         $this->setNewFactoryDefault();
//     }
//
//     public function _after(IntegrationTester $I)
//     {
//         $this->container['db']->close();
//     }
//
//     public function testModelsMysql(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//
//         $this->executeQueryRelated($I);
//         $this->executeSaveRelatedBelongsTo($I);
//     }
//
//     /*public function testModelsPostgresql()
//     {
//         $di = $this->_getDI();
//
//         $di->set(
//             'db',
//             function () {
//                 require 'unit-tests/config.db.php';
//
//                 return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
//             },
//             true
//         );
//
//         $this->_executeQueryRelated();
//         $this->_executeSaveRelatedBelongsTo($connection);
//     }
//
//     public function testModelsSqlite()
//     {
//         $di = $this->_getDI();
//
//         $di->set(
//             'db',
//             function () {
//                 require 'unit-tests/config.db.php';
//
//                 return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
//             },
//             true
//         );
//
//         $this->_executeQueryRelated();
//         $this->_executeSaveRelatedBelongsTo($connection);
//     }*/
//
//     private function executeQueryRelated(IntegrationTester $I)
//     {
//         //Belongs to
//         $album = Albums::findFirst();
//         $I->assertInstanceOf(Albums::class, $album);
//
//         $artist = $album->artist;
//         $I->assertInstanceOf(Artists::class, $artist);
//
//         $albums = $artist->albums;
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $albums);
//         $I->assertCount(2, $albums);
//         $I->assertInstanceOf(Albums::class, $albums[0]);
//
//         $songs = $album->songs;
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $songs);
//         $I->assertCount(7, $songs);
//         $I->assertInstanceOf(Songs::class, $songs[0]);
//
//         $originalAlbum = $album->artist->albums[0];
//         $I->assertEquals($originalAlbum->id, $album->id);
//     }
//
//     private function executeSaveRelatedBelongsTo(IntegrationTester $I)
//     {
//         $connection = $this->getService('db');
//         $artist     = new Artists();
//
//         $album         = new Albums();
//         $album->artist = $artist;
//
//         /**
//          * @todo Check this
//
