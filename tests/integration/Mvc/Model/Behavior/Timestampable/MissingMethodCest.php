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

namespace Phalcon\Test\Integration\Mvc\Model\Behavior\Timestampable;

use IntegrationTester;
use Phalcon\Mvc\Model\Behavior\Timestampable;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Users;

class MissingMethodCest
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
     * Tests Phalcon\Mvc\Model\Behavior\Timestampable :: missingMethod()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-03
     */
    public function mvcModelBehaviorTimestampableMissingMethod(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Behavior\Timestampable - missingMethod()');

        $user = new Users();

        $behavior = new Timestampable();

        $I->assertNull(
            $behavior->missingMethod(
                $user,
                'somethingAmazing',
                []
            )
        );
    }
}
