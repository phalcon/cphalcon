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

namespace Phalcon\Tests\Integration\Mvc\Model\Behavior\Timestampable;

use IntegrationTester;
use Phalcon\Mvc\Model\Behavior\Timestampable;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Users;

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
