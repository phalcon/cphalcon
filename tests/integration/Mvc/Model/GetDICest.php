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
use Phalcon\Di;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Users;

/**
 * Class GetDICest
 */
class GetDICest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Tests Phalcon\Mvc\Model :: getDI()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-18
     */
    public function mvcModelGetDI(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - getDI()');

        $container = new Di();

        $user = new Users(
            [],
            $container,
            $this->container->get('modelsManager')
        );

        $actual = $user->getDI();

        $I->assertInstanceOf(
            Di::class,
            $actual
        );

        $I->assertEquals(
            $container,
            $actual
        );
    }
}
