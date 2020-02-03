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

class RemoveCest
{
    use DiTrait;
    use SessionTrait;

    public function _after(IntegrationTester $I)
    {
        $_SESSION = [];
    }

    /**
     * Tests Phalcon\Session\Manager :: remove()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerRemove(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - remove()');
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

        $manager->remove('test');
        $actual = $manager->has('test');
        $I->assertFalse($actual);

        $manager->destroy();

        $actual = $manager->exists();
        $I->assertFalse($actual);
    }
}
