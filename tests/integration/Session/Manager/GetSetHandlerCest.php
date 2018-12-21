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
use Phalcon\Session\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;
use SessionHandlerInterface;

/**
 * Class GetSetHandlerCest
 */
class GetSetHandlerCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * Tests Phalcon\Session\Manager :: getHandler()/setHandler()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerGetSetHandler(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getHandler()/setHandler()');
        $manager = new Manager();
        $files   = $this->getSessionFiles();
        $manager->setHandler($files);

        $actual = $manager->getHandler();
        $class  = SessionHandlerInterface::class;
        $I->assertInstanceOf($class, $actual);
    }
}
