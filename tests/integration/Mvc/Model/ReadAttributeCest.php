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
use Phalcon\Test\Models\Users;

class ReadAttributeCest
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
     * Tests Phalcon\Mvc\Model :: readAttribute()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function mvcModelReadAttribute(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - readAttribute()');

        $user = new Users();

        $user->assign(
            [
                'id'   => 123,
                'name' => 'Sid',
            ]
        );

        $I->assertEquals(
            123,
            $user->readAttribute('id')
        );

        $I->assertEquals(
            'Sid',
            $user->readAttribute('name')
        );
    }
}
