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
use Phalcon\Tests\Fixtures\Traits\SessionTrait;
use SessionHandlerInterface;

class GetSetAdapterCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: getAdapter()/setAdapter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerGetSetAdapter(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getAdapter()/setAdapter()');
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        $actual = $manager->getAdapter();
        $class  = SessionHandlerInterface::class;
        $I->assertInstanceOf($class, $actual);
    }
}
