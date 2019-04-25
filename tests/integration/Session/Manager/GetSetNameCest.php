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
use InvalidArgumentException;
use Phalcon\Session\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

/**
 * Class GetSetNameCest
 */
class GetSetNameCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * Tests Phalcon\Session\Manager :: getName()/setName()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerGetSetName(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getName()/setName()');

        $manager = new Manager();

        $files = $this->getSessionFiles();

        $manager->setHandler($files);

        if (false !== $manager->exists()) {
            $manager->destroy();
        }

        $manager->setName('myname');

        $I->assertEquals(
            'myname',
            $manager->getName()
        );
    }

    /**
     * Tests Phalcon\Session\Manager :: getName()/setName() - not valid name
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerGetNameNotValidName(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getName()/setName() - not valid name');

        $I->expectThrowable(
            new InvalidArgumentException('The name contains non alphanum characters'),
            function () {
                $manager = new Manager();

                $files = $this->getSessionFiles();

                $manager->setHandler($files);

                $manager->setName('%-gga34');
            }
        );
    }

    /**
     * Tests Phalcon\Session\Manager :: getName()/setName() - session started
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerGetNameSessionStarted(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getName()/setName() - session started');

        $manager = new Manager();

        $files = $this->getSessionFiles();

        $manager->setHandler($files);

        $manager->start();

        $I->expectThrowable(
            new InvalidArgumentException('Cannot set session name after a session has started'),
            function () use ($manager) {
                $manager->setName('%-gga34');
            }
        );

        $manager->destroy();
    }
}
