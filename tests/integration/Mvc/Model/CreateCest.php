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
use Phalcon\Test\Models\AlbumORama\Artists;
use function uniqid;

/**
 * Class CreateCest
 */
class CreateCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model :: create()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCreate(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - create()');

        $this->setNewFactoryDefault();

        $name = uniqid();

        // MySql
        $this->setDiMysql();

        $artist = new Artists();
        $artist->name = $name;
        $result = $artist->save();

        $I->assertNotFalse($result);

        $result = $artist->delete();

        $I->assertNotFalse($result);

        // Postgresql
        $this->setDiPostgresql();

        $artist = new Artists();
        $artist->name = $name;
        $result = $artist->save();

        $I->assertNotFalse($result);

        $result = $artist->delete();

        $I->assertNotFalse($result);
    }
}
