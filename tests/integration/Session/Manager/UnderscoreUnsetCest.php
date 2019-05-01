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

namespace Phalcon\Test\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

/**
 * @package Phalcon\Test\Integration\Session\Manager
 */
class UnderscoreUnsetCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * Tests Phalcon\Session\Manager :: __unset()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerUnderscoreUnset(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - __unset()');

        $manager = new Manager();

        $files = $this->getSessionFiles();

        $manager->setHandler($files);

        $I->assertTrue(
            $manager->start()
        );

        $I->assertFalse(
            $manager->has('test')
        );

        $manager->set('test', 'myval');

        $I->assertTrue(
            $manager->has('test')
        );

        unset($manager->test);

        $I->assertFalse(
            $manager->has('test')
        );

        $manager->destroy();

        $I->assertFalse(
            $manager->exists()
        );
    }
}
