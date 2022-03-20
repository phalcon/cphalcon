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

class HasCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: has()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerHas(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - has()');

        $manager = new Manager();

        $files = $this->newService('sessionStream');

        $manager->setAdapter($files);

        $actual = $manager->has('test');
        $I->assertFalse($actual);

        $actual = $manager->start();
        $I->assertTrue($actual);

        $actual = $manager->has('test');
        $I->assertFalse($actual);

        $manager->set('test', 'myval');

        $actual = $manager->has('test');
        $I->assertTrue($actual);

        $manager->destroy();

        $actual = $manager->exists();
        $I->assertFalse($actual);
    }
}
