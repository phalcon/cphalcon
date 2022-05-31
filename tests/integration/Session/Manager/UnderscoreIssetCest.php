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

class UnderscoreIssetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: __isset()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerUnderscoreIsset(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - __isset()');
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        $actual = $manager->start();
        $I->assertTrue($actual);

        $actual = isset($manager->test);
        $I->assertFalse($actual);

        $manager->set('test', 'myval');
        $actual = isset($manager->test);
        $I->assertTrue($actual);

        $manager->destroy();

        $actual = $manager->exists();
        $I->assertFalse($actual);
    }
}
