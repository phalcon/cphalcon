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

namespace Phalcon\Test\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

class UnderscoreGetSetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: __get()/__set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerUnderscoreGetSet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - __get()/__set()');

        $manager = new Manager();

        $files = $this->newService('sessionStream');

        $manager->setAdapter($files);

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
