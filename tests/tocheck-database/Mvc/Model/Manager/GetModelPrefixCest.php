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

namespace Phalcon\Tests\Integration\Mvc\Model\Manager;

use IntegrationTester;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetModelPrefixCest
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
     * Tests Phalcon\Mvc\Model\Manager :: getModelPrefix()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-04
     */
    public function mvcModelManagerGetModelPrefix(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - getModelPrefix()');

        $manager = new Manager();

        $I->assertEquals(
            '',
            $manager->getModelPrefix()
        );

        $manager->setModelPrefix('wp_');

        $I->assertEquals(
            'wp_',
            $manager->getModelPrefix()
        );
    }
}
