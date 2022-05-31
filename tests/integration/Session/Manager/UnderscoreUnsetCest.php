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

class UnderscoreUnsetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: __unset()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerUnderscoreUnset(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - __unset()');
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        $actual = $manager->start();
        $I->assertTrue($actual);

        $actual = $manager->has('test');
        $I->assertFalse($actual);

        $manager->set('test', 'myval');
        $actual = $manager->has('test');
        $I->assertTrue($actual);

        unset($manager->test);
        $actual = $manager->has('test');
        $I->assertFalse($actual);

        $manager->destroy();

        $actual = $manager->exists();
        $I->assertFalse($actual);
    }
}
