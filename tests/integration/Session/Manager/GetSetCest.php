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

use function uniqid;

class GetSetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: get()/set()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerGetSet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - get()/set()');

        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        $actual = $manager->get('test');
        $I->assertNull($actual);

        $actual = $manager->start();
        $I->assertTrue($actual);

        $expected = 'myval';
        $manager->set('test', $expected);

        $actual = $manager->get('test');
        $I->assertEquals($expected, $actual);

        $actual = $manager->has('test');
        $I->assertTrue($actual);

        $actual = $manager->get('test', null, true);
        $I->assertEquals($expected, $actual);

        $actual = $manager->has('test');
        $I->assertFalse($actual);

        $name     = uniqid();
        $expected = $name;
        $actual   = $manager->get('test', $name);
        $I->assertEquals($expected, $actual);

        $manager->destroy();

        $actual = $manager->exists();
        $I->assertFalse($actual);
    }
}
