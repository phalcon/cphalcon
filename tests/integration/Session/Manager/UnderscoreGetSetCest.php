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

namespace Phalcon\Tests\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class UnderscoreGetSetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: __get()/__set()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerUnderscoreGetSet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - __get()/__set()');

        $manager = new Manager();

        $files = $this->newService('sessionStream');

        $manager->setAdapter($files);

        $actual = $manager->start();
        $I->assertTrue($actual);

        $expected      = 'myval';
        $manager->test = $expected;

        $I->assertEquals($expected, $manager->test);

        $manager->destroy();

        $actual = $manager->exists();
        $I->assertFalse($actual);
    }
}
