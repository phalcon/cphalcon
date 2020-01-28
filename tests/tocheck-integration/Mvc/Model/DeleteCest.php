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
use Phalcon\Test\Models\AlbumORama\Artists;

use function uniqid;

/**
 * Class DeleteCest
 */
class DeleteCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model :: delete()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelDelete(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - delete()');

        $this->setNewFactoryDefault();

        $name = uniqid();

        // MySql
        $this->setDiMysql();

        $artist       = new Artists();
        $artist->name = $name;
        $result       = $artist->save();

        $I->assertNotFalse($result);

        $result = $artist->delete();

        $I->assertNotFalse($result);

        // Postgresql
        $this->setDiPostgresql();

        $artist       = new Artists();
        $artist->name = $name;
        $result       = $artist->save();

        $I->assertNotFalse($result);

        $result = $artist->delete();

        $I->assertNotFalse($result);
    }
}
