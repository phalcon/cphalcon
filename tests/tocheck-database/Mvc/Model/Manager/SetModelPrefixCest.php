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
use Phalcon\Tests\Models\Robots;

class SetModelPrefixCest
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
     * Tests empty prefix for model
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10328
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2017-04-15
     */
    public function testShouldReturnSourceWithoutPrefix(IntegrationTester $I)
    {
        $manager = new Manager();

        $robots = new Robots(null, null, $manager);

        $I->assertEquals(
            'robots',
            $robots->getModelsManager()->getModelSource($robots)
        );

        $I->assertEquals(
            'robots',
            $robots->getSource()
        );
    }

    /**
     * Tests non-empty prefix for model
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10328
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2017-04-15
     */
    public function testShouldReturnSourceWithPrefix(IntegrationTester $I)
    {
        $manager = new Manager();

        $manager->setModelPrefix('wp_');

        $robots = new Robots(null, null, $manager);

        $I->assertEquals(
            'wp_robots',
            $robots->getModelsManager()->getModelSource($robots)
        );

        $I->assertEquals(
            'wp_robots',
            $robots->getSource()
        );
    }
}
