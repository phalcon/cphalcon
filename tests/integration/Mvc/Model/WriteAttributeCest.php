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

class WriteAttributeCest
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
     * Tests Phalcon\Mvc\Model :: writeAttribute()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function mvcModelWriteAttribute(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - writeAttribute()');

        $user = new Users();

        $user->writeAttribute('id', 123);
        $user->writeAttribute('name', 'Sid');

        $I->assertEquals(
            123,
            $user->readAttribute('id')
        );

        $I->assertEquals(
            'Sid',
            $user->readAttribute('name')
        );

        $I->assertEquals(
            [
                'id'   => 123,
                'name' => 'Sid',
            ],
            $user->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: writeAttribute() with associative array
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
     */
    public function mvcModelWriteAttributeWithAssociativeArray(IntegrationTester $I)
    {
        $I->wantToTest('Phalcon\Mvc\Model :: writeAttribute() with associative array');

        $associativeArray = [
            'firstName' => 'First name',
            'lastName'  => 'Last name',
        ];

        $user = new Users();

        $user->writeAttribute('id', 123);
        $user->writeAttribute('name', $associativeArray);

        $I->assertEquals(
            $associativeArray,
            $user->readAttribute('name')
        );

        $I->assertEquals(
            [
                'id'   => 123,
                'name' => $associativeArray,
            ],
            $user->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: writeAttribute() undefined property with
     * associative array
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14021
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
     */
    public function mvcModelWriteAttributeUndefinedPropertyWithAssociativeArray(IntegrationTester $I)
    {
        $I->wantToTest('Phalcon\Mvc\Model :: writeAttribute() undefined property with associative array');

        $associativeArray = [
            'id'   => 123,
            'name' => 'My Name',
        ];

        $user = new Users();

        $user->writeAttribute('whatEverUndefinedProperty', $associativeArray);

        $I->assertEquals(
            [
                'id'   => null,
                'name' => null,
            ],
            $user->toArray()
        );
    }
}
