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

class UnderscoreGetSetCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * Tests Phalcon\Session\Manager :: __get()/__set()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerUnderscoreGetSet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - __get()/__set()');

        $manager = new Manager();

        $files = $this->getSessionStream();

        $manager->setHandler($files);

        $I->assertTrue(
            $manager->start()
        );

        $expected      = 'myval';
        $manager->test = $expected;

        $I->assertEquals(
            $expected,
            $manager->test
        );

        $manager->destroy();

        $I->assertFalse(
            $manager->exists()
        );
    }
}
