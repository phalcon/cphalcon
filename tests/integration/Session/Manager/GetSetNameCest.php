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
use InvalidArgumentException;
use Phalcon\Session\Manager;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\SessionTrait;

/**
 * Class GetSetNameCest
 */
class GetSetNameCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: getName()/setName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerGetSetName(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getName()/setName()');
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        if (false !== $manager->exists()) {
            $manager->destroy();
        }

        $manager->setName('myname');
        $expected = 'myname';
        $actual   = $manager->getName();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Session\Manager :: getName()/setName() - not valid name
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerGetNameNotValidName(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getName()/setName() - not valid name');
        $I->expectThrowable(
            new InvalidArgumentException('The name contains non alphanum characters'),
            function () {
                $manager = new Manager();
                $files   = $this->newService('sessionStream');
                $manager->setAdapter($files);

                $manager->setName('%-gga34');
            }
        );
    }

    /**
     * Tests Phalcon\Session\Manager :: getName()/setName() - session started
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerGetNameSessionStarted(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getName()/setName() - session started');
        $valid   = false;
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        try {
            $manager->start();
            $manager->setName('%-gga34');
        } catch (InvalidArgumentException $ex) {
            $manager->destroy();
            $valid    = true;
            $expected = 'Cannot set session name after a session has started';
            $actual   = $ex->getMessage();
            $I->assertEquals($expected, $actual);
        }

        $I->assertTrue($valid);
    }
}
