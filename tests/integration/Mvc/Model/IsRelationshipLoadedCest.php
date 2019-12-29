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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\AlbumORama;

class IsRelationshipLoadedCest
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
     * Testing relationship loading using Model::__get()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelUnderscoreGet(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - isRelationshipLoaded() when using __get()');

        /**
         * @var AlbumORama\Albums
         */
        $album = AlbumORama\Albums::findFirst();

        $I->assertFalse(
            $album->isRelationshipLoaded('artist')
        );

        $I->assertFalse(
            $album->isRelationshipLoaded('songs')
        );

        /**
         * @var AlbumORama\Artists
         */
        $artist = $album->artist;

        $I->assertTrue(
            $album->isRelationshipLoaded('artist')
        );

        /**
         * @var \Phalcon\Mvc\Model\Resultset\Simple
         */
        $songs = $album->songs;

        $I->assertTrue(
            $album->isRelationshipLoaded('songs')
        );
    }

    /**
     * Testing relationship loading using Model::__set()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelUnderscoreSet(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - isRelationshipLoaded() when using __set()');

        /**
         * @var AlbumORama\Albums
         */
        $album = AlbumORama\Albums::findFirst();

        $I->assertFalse(
            $album->isRelationshipLoaded('artist')
        );

        $I->assertFalse(
            $album->isRelationshipLoaded('songs')
        );

        $album->artist = new AlbumORama\Artists();

        $I->assertFalse(
            $album->isRelationshipLoaded('artist')
        );

        $album->songs = [
            new AlbumORama\Songs(),
            new AlbumORama\Songs(),
        ];

        $I->assertFalse(
            $album->isRelationshipLoaded('songs')
        );
    }

    /**
     * Testing relationship loading using Model::__call() getters
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelUnderscoreCallGet(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - isRelationshipLoaded() when using __call() getters');

        /**
         * @var AlbumORama\Albums
         */
        $album = AlbumORama\Albums::findFirst();

        $I->assertFalse(
            $album->isRelationshipLoaded('artist')
        );

        $I->assertFalse(
            $album->isRelationshipLoaded('songs')
        );

        /**
         * @var AlbumORama\Artists
         */
        $artist = $album->getArtist();

        $I->assertTrue(
            $album->isRelationshipLoaded('artist')
        );

        /**
         * @var \Phalcon\Mvc\Model\Resultset\Simple
         */
        $songs = $album->getSongs();

        $I->assertTrue(
            $album->isRelationshipLoaded('songs')
        );
    }

    /**
     * Testing relationship loading using Model::getRelated() method
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelGetRelated(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - isRelationshipLoaded() when using getRelated()');

        /**
         * @var AlbumORama\Albums
         */
        $album = AlbumORama\Albums::findFirst();

        $I->assertFalse(
            $album->isRelationshipLoaded('artist')
        );

        $I->assertFalse(
            $album->isRelationshipLoaded('songs')
        );

        /**
         * @var AlbumORama\Artists
         */
        $artist = $album->getRelated('artist');

        $I->assertTrue(
            $album->isRelationshipLoaded('artist')
        );

        /**
         * @var \Phalcon\Mvc\Model\Resultset\Simple
         */
        $songs = $album->getRelated('songs');

        $I->assertTrue(
            $album->isRelationshipLoaded('songs')
        );
    }
}
