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

class GetSetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: get()/set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerGetSet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - get()/set()');

        $manager = new Manager();

        $files = $this->newService('sessionStream');

        $manager->setAdapter($files);


        $I->assertTrue(
            $manager->start()
        );


        $expected = 'myval';

        $manager->set('test', $expected);

        $I->assertEquals(
            $expected,
            $manager->get('test')
        );


        $manager->destroy();


        $I->assertFalse(
            $manager->exists()
        );
    }
}
