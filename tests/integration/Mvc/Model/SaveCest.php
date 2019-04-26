<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\AlbumORama;

/**
 * Class SaveCest
 */
class SaveCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after fetching related records
     *
     * @param IntegrationTester $I
     *
     * @see https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelSaveAfterFetchingRelated(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() after fetching related');

        /**
         * @var AlbumORama\Albums $album
         */
        $album = AlbumORama\Albums::findFirst();

        /**
         * @var AlbumORama\Artists $artist
         */
        $artist = $album->artist;

        $I->assertTrue($album->save());

        /**
         * @var \Phalcon\Mvc\Model\Resultset\Simple $songs
         */
        $songs = $album->songs;

        $I->assertTrue($album->save());
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after using related records getters
     *
     * @param IntegrationTester $I
     *
     * @see https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     */
    public function mvcModelSaveAfterUsingRelatedGetters(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save() after using related records getters');

        /**
         * @var AlbumORama\Albums $album
         */
        $album = AlbumORama\Albums::findFirst();

        /**
         * @var AlbumORama\Artists $artist
         */
        $artist = $album->getArtist();

        $I->assertTrue($album->save());

        /**
         * @var \Phalcon\Mvc\Model\Resultset\Simple $songs
         */
        $songs = $album->getSongs();

        $I->assertTrue($album->save());
    }

    /**
     * Tests Phalcon\Mvc\Model :: save()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelSave(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - save()');
        $I->skipTest('Need implementation');
    }
}
